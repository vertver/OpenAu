/////////////////////////////////
// VERTVER, 2018 (C)
// OpenAu, Open Audio Utility
// MIT-License
/////////////////////////////////
// AuEngine.h:
// header for AuEngine
/////////////////////////////////
#pragma once
#include <exception>
#include <string>
#include <windows.h>
#include <math.h>
extern "C"
{
#include "../PortAudio/include/portaudio.h"
#include "../PortAudio/include/pa_asio.h"
#include "../PortAudio/include/pa_win_wmme.h"
}

#define THROW_EXCEPTION(x) 	throw AuEngine::Exception(x)
#define DEBUG_BREAK __debugbreak()
#ifdef WIN32
#pragma comment(lib, "../x64/Release/portaudio_x64.lib")
#define DLL_API __declspec(dllexport)
#endif

/***********************************************
* class AuEngine:
* All audio engine for OpenAu.exe
***********************************
* enum OpSet:
* contain enums for OpSet (Operation Set)
*
* enum PCM_File:
* contain enums for PCM Formats
*
* class Exception:
* Exception class for AuEngine
*
* class Output:
* Output class for AuEngine
*
* class Input:
* Input class for AuEngine
***********************************************/
__declspec(dllexport) class AuEngine
{
public:
	AuEngine() {};
	~AuEngine() { delete output; delete input; delete exc; };
	AuEngine(size_t weight) {};

	// Opset list for exception class
	enum OpSet
	{
		SUCCESS_ERROR,
		NO_AUDIO_DEVICE,
		ASIO_ERROR,
		UI_ERROR,
		INIT_ERROR,
		PORTAUDIO_ERROR,
		ENGINE_ERROR,
		STREAM_ERROR,
		MEMORY_ERROR,
		MAX_VAL = 0xFFFF
	};

	enum PCM_File
	{
		WAV_FILE = 1,
		AIF_FILE = 2,
		AIFF_FILE = 4,
		MP3_FILE = 8,
		MAX_VALUE = 0xFFFF
	};

	// Exception Class
	class Exception : std::exception
	{
	private:
		std::string errMessage;
		OpSet opSetDescr = OpSet::MAX_VAL;		// Max case
	public:
		// Constructor with const message and opset
		Exception(const std::string szString, OpSet opSet) noexcept
		{
			errMessage = szString;
			opSetDescr = opSet;
		}
		Exception(OpSet opSet) noexcept { opSetDescr = opSet; }	// Constructor with opset
		Exception() {}											// Constructor with exception
		~Exception() {};										// Destructor
		const char* what() const noexcept { return errMessage.c_str(); }
		OpSet opset() const { return opSetDescr; }
	};
	class Output
	{
	public:
		Output() {}
		~Output() {}
		void ReadChunks();
		DLL_API void CreateStream(PaDeviceIndex paDevice);
		void FinishedCallbackMsg(void *userData);
		DLL_API void CloseStream();
		void OutputThread(const char* lpName);
		DLL_API void CreateOutput(const char* lpName);
		DLL_API const char * GetOutputDevice();
	private:
		PaStream * stream;
		int left_phase;
		int right_phase;
		char message[20];
		int numDevices, defaultDisplayed;
		const PaDeviceInfo *deviceInfo;
		PaStreamParameters inputParameters, outputParameters;
	};
	class Input
	{
	public:
		DLL_API void GetListOfDevices();
		DLL_API void ReadAudioFile(const char* lpFileName, int iFileType);
	private:
		int numDevices, defaultDisplayed;
		const PaDeviceInfo *deviceInfo;
		PaStreamParameters inputParameters, outputParameters;
	};
private:
	AuEngine::Output* output;
	AuEngine::Input* input;
	AuEngine::Exception* exc;
};