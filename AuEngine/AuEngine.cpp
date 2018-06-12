/////////////////////////////////
// VERTVER, 2018 (C)
// OpenAu, Open Audio Utility
// MIT-License
/////////////////////////////////
// AuEngine.cpp:
// methods for AuEngine
/////////////////////////////////

#include "AuEngine.h"
#include <thread>
#define SAMPLE_RATE 44100

void Msg(std::string szMessage)
{
#ifdef WIN32
	OutputDebugStringA(szMessage.c_str());
	OutputDebugStringA("\n");
#endif
}

void Msg(std::string szMessage, int iNum)
{
#ifdef WIN32
	OutputDebugStringA(szMessage.c_str());
	OutputDebugStringA(std::to_string(iNum).c_str());
	OutputDebugStringA("\n");
#endif
}

int streamCallback(const void *inputBuffer, void *outputBuffer, unsigned long framesPerBuffer,
	const PaStreamCallbackTimeInfo* timeInfo, PaStreamCallbackFlags statusFlags)
{
	float *out = (float*)outputBuffer;
	unsigned long i;

	(void)timeInfo;			// Prevent unused variable warnings.
	(void)statusFlags;
	(void)inputBuffer;

	for (i = 0; i < framesPerBuffer; i++) {  }

	return paContinue;
}

static int paCallback(const void *inputBuffer, void *outputBuffer, unsigned long framesPerBuffer,
	const PaStreamCallbackTimeInfo* timeInfo, PaStreamCallbackFlags statusFlags, void *userData)
{
	return streamCallback(inputBuffer, outputBuffer, framesPerBuffer, timeInfo, statusFlags);
}

std::string HostDefault;
#include <iomanip>

void AuEngine::Output::CreateStream(PaDeviceIndex paDevice)
{
	outputParameters.device = paDevice;
	if (paDevice != paNoDevice)
	{
		const PaDeviceInfo* pInfo = Pa_GetDeviceInfo(paDevice);
		std::string toMsg = pInfo->name;
		int iSampleRate = pInfo->defaultSampleRate * 1000000 / 1000000;
		if (pInfo) { Msg("Output device name: " + toMsg); }
		HostDefault = "All done! Default device sample rate: " + std::to_string(iSampleRate) + "Hz.";


		outputParameters.channelCount = 2;       
		outputParameters.sampleFormat = paFloat32;		// 32-bit output
		outputParameters.suggestedLatency = Pa_GetDeviceInfo(outputParameters.device)->defaultLowOutputLatency;	// set low latency
		outputParameters.hostApiSpecificStreamInfo = NULL;

		PaError err = Pa_OpenStream(&stream, NULL, &outputParameters, iSampleRate,
									paFramesPerBufferUnspecified, paClipOff, &paCallback, this);

		if (err != paNoError)
		{
			Msg("Error! Can't create audio stream");
			THROW_EXCEPTION(AuEngine::OpSet::STREAM_ERROR);
		}

		//err = Pa_SetStreamFinishedCallback(stream, &FinishedCallbackMsg);

		/*if (err != paNoError)
		{
			Pa_CloseStream(stream);
			stream = 0;
		}
		else
			THROW_EXCEPTION(OpSet::INIT_ERROR);
			
		if (stream) PaError err = Pa_StartStream(stream);*/
	}
	else 
		THROW_EXCEPTION(AuEngine::OpSet::NO_AUDIO_DEVICE);

}

static void FinishedCallbackMsg(void *userData)
{
	return Msg("");
}

void AuEngine::Output::CloseStream()
{

}

void AuEngine::Output::OutputThread()
{
	//#TODO: Have some problem with default sample rate
	PaDeviceIndex outDevice = Pa_GetDefaultOutputDevice();
	CreateStream(outDevice);
}

void AuEngine::Output::CreateOutput()
{
	try
	{
		AuEngine::Output output;
		AuEngine::Input input;
		input.GetListOfDevices();
		output.OutputThread();
		Msg("AuEngine: Output was created");
	}
	catch (...)
	{
		THROW_EXCEPTION(AuEngine::OpSet::ENGINE_ERROR);
	}
}

const char* AuEngine::Output::GetOutputDevice()
{
	return HostDefault.c_str();
}

void AuEngine::Input::GetListOfDevices()
{
	PaError err = Pa_Initialize();

	if (err != paNoError)
	{
		Msg("ERROR: Pa_Initialize returned: ", err);
		THROW_EXCEPTION(AuEngine::OpSet::INIT_ERROR);
	}
	numDevices = Pa_GetDeviceCount();

	if (numDevices < 0)
	{
		Msg("AuEngine: No devices");
		THROW_EXCEPTION(AuEngine::OpSet::NO_AUDIO_DEVICE);
	}
	else
		Msg("AuEngine: List of devices: ", numDevices);

	for (int i = 0; i < numDevices; i++)
	{
		deviceInfo = Pa_GetDeviceInfo(i);
		Msg("AuEngine: Device number: ", i);

		/* Mark global and API specific default devices */
		defaultDisplayed = 0;
		if (i == Pa_GetDefaultInputDevice())
		{
			Msg("AuEngine: Default Input");
			defaultDisplayed = 1;
		}
		else if (i == Pa_GetHostApiInfo(deviceInfo->hostApi)->defaultInputDevice)
		{
			const PaHostApiInfo *hostInfo = Pa_GetHostApiInfo(deviceInfo->hostApi);
			std::string hName = hostInfo->name;
			Msg("AuEngine: Default Input: " + hName);
			defaultDisplayed = 1;
		}

		if (i == Pa_GetDefaultOutputDevice())
		{
			Msg("AuEngine: Default Output");
			defaultDisplayed = 1;
		}
		else if (i == Pa_GetHostApiInfo(deviceInfo->hostApi)->defaultOutputDevice)
		{
			const PaHostApiInfo *hostInfo = Pa_GetHostApiInfo(deviceInfo->hostApi);
			std::string hName = hostInfo->name;
			Msg("AuEngine: Default Output: " + hName);
			defaultDisplayed = 1;
		}

		std::string szDevice = deviceInfo->name;
		std::string szDeviceInfoHostAPI = Pa_GetHostApiInfo(deviceInfo->hostApi)->name;
#ifdef DEBUG
		Msg("Name: " + szDevice);

		Msg("Host API = " + szDeviceInfoHostAPI);
		Msg("Max inputs = ", deviceInfo->maxInputChannels);
		Msg("Max outputs = ", deviceInfo->maxOutputChannels);
		Msg("Default low input latency = ", deviceInfo->defaultLowInputLatency);
		Msg("Default low output latency  = ", deviceInfo->defaultLowOutputLatency);
		Msg("Default high input latency  = ", deviceInfo->defaultHighInputLatency);
		Msg("Default high output latency = ", deviceInfo->defaultHighOutputLatency);
#endif

#ifdef WIN32
#if PA_USE_ASIO
		/* ASIO specific latency information */
		if (Pa_GetHostApiInfo(deviceInfo->hostApi)->type == paASIO) 
		{
			long minLatency, maxLatency, preferredLatency, granularity;

			err = PaAsio_GetAvailableLatencyValues(i,
				&minLatency, &maxLatency, &preferredLatency, &granularity);
#ifdef DEBUG
			Msg("ASIO minimum buffer size    = %ld\n", minLatency);
			Msg("ASIO maximum buffer size    = %ld\n", maxLatency);
			Msg("ASIO preferred buffer size  = %ld\n", preferredLatency);
#endif
		}
#endif
#endif

		static double standardSampleRates[] = { 8000.0, 9600.0, 11025.0, 12000.0, 16000.0, 22050.0, 24000.0,
												32000.0, 44100.0, 48000.0, 88200.0, 96000.0, 192000.0, -1 };

		int printCount = 0;

		inputParameters.device = i;
		inputParameters.channelCount = deviceInfo->maxInputChannels;
		inputParameters.sampleFormat = paInt16;
		inputParameters.suggestedLatency = 0; /* ignored by Pa_IsFormatSupported() */
		inputParameters.hostApiSpecificStreamInfo = NULL;

		outputParameters.device = i;
		outputParameters.channelCount = deviceInfo->maxOutputChannels;
		outputParameters.sampleFormat = paInt16;
		outputParameters.suggestedLatency = 0; /* ignored by Pa_IsFormatSupported() */
		outputParameters.hostApiSpecificStreamInfo = NULL;

		for (int u = 0; standardSampleRates[u] > 0; u++)
		{
			err = Pa_IsFormatSupported(&inputParameters, &outputParameters, standardSampleRates[u]);
			if (err == paFormatIsSupported)
			{
#ifdef DEBUG
				if (printCount == 0)
				{
					Msg("Sample rates: ", standardSampleRates[u]);
					printCount = 1;
				}
				else if (printCount == 4)
				{
					Msg("Sample rates: ", standardSampleRates[u]);
					printCount = 1;
				}
				else
				{
					Msg("Sample rates: ", standardSampleRates[u]);
					++printCount;
				}
#endif
			}
		}
	}
}
