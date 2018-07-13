/////////////////////////////////
// VERTVER, 2018 (C)
// OpenAu, Open Audio Utility
// MIT-License
/////////////////////////////////
// AuEngineVU.cpp:
// VU-meter
/////////////////////////////////
#include "AuEngine.h"

static const float start_threshold = -3;
static const int lights_per_dB = 3;
static const int light_count = 10;
static char stars[11]; // must match light_count

/***********************************************
* VUGetCurrentLevels():
* Getting current level of stream
***********************************************/
int AuEngine::Output::VUGetCurrentLevels()
{
	float sampleBlock[100];
	int value;
	for (int i = 0; i < (60 * SAMPLE_RATE) / 100; ++i)
	{
		const char *read_error = "", *write_error = "";

		PaError err = Pa_ReadStream(stream, sampleBlock, 100);
		read_error = Pa_GetErrorText(err);

		value = VUMeterForSample(100, (float *)sampleBlock);
	}
	return value;
}

/***********************************************
* VUMeterForSample():
* Counting a volume
***********************************************/
int AuEngine::Output::VUMeterForSample(int count, float* buffer)
{
	float K = 0, sum = 0, volume = 0;

	for (int i = 0; i < count; i++)
	{
		sum += pow(buffer[i], 2);
	}
	volume = 20 * log10(sqrt(sum / count)) + K;

	const float origVolume = volume;

	// Make volume a number from 0 to number of dB
	volume += (light_count * lights_per_dB);
	volume = fmax(0, volume);
	volume /= lights_per_dB;
	//printf("%6.2f %d %s\n", origVolume, v, stars + (light_count - v));
	int valueMain = fmin(volume, light_count);
	return valueMain;
}

/***********************************************
* VUMeterInit():
* Initing VU-Meter
***********************************************/
void AuEngine::Output::VUMeterInit()
{
	int i;
	for (i = 0; i < light_count; i++)
	{
		stars[i] = '*';
	}
	stars[light_count] = 0;
}
