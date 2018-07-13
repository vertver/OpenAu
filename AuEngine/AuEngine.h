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
#include <malloc.h>
extern "C"
{
#include "../PortAudio/include/portaudio.h"
#include "../PortAudio/include/pa_asio.h"
#include "../PortAudio/include/pa_win_wmme.h"
}

// Validating and checking
#define CHECK(x)				{ if(!(x))				{  Msg("failure:" + __LINE__); } }
#define PA_CHECK(x, y)			if (x != paNoError)		{ THROW_EXCEPTION(y); }

void Msg(std::string szMessage);
void Msg(std::string szMessage, int iNum);
template<typename T> T freadNum(FILE* f);
std::string freadStr(FILE* f, size_t len);

#define THROW_EXCEPTION(x) 		throw AuEngine::Exception(x)
#define DEBUG_BREAK				__debugbreak()		// int 3
#define FFT_SIZE				1024
#define SAMPLE_RATE				44100

#ifdef WIN32
#define ENGINE_EXPORTS
#pragma comment(lib, "../x64/Release/portaudio_x64.lib")
#endif
#ifdef ENGINE_EXPORTS
#define DLL_API					__declspec(dllexport)
#else
#define DLL_API					__declspec(dllimport)
#endif


/***********************************************
* class AuEngine:
* All audio engine for OpenAu
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
namespace AuEngine
{
	// Opset list for exception class
	enum OpSet
	{
		FILESYSYEM_ERROR,
		SUCCESS_ERROR,
		NO_AUDIO_DEVICE,
		MME_ERROR,
		ASIO_ERROR,
		UI_ERROR,
		INIT_ERROR,
		PORTAUDIO_ERROR,
		ENGINE_ERROR,
		STREAM_ERROR,
		MEMORY_ERROR,
		MAX_VAL		= 0xFFFF
	};

	enum PCM_File
	{
		WAV_FILE	= 1,
		AIF_FILE	= 2,
		AIFF_FILE	= 3,
		MP3_FILE	= 4,
		MP3C_FILE	= 5,			// Mpeg-4 at MP3
		FLAC_FLIE	= 6,
		AAC_FILE	= 7
	};	

	class FileSystem
	{
	public:
		void CreateFileInBuffer(FILE * oFile, size_t szBuffer);
		void OpenFileByPart(const char * lpPath);
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
		Exception() {}												// Constructor with exception
		~Exception() {}											// Destructor
		const char* what() const noexcept { return errMessage.c_str(); }
		OpSet opset() const { return opSetDescr; }
	};
	class Output
	{
	public:
		PaStream * stream;

		Output() {}
		~Output() {}
		DLL_API void CreateStream(PaDeviceIndex paDeviceOutput, PaDeviceIndex paDeviceInput);
		DLL_API void CloseOutput(PaStream* stream);
		DLL_API void CreateOutput(const char* lpName);
		DLL_API const char* GetOutputDevice();
		DLL_API int GetCPULoadStream(float fLoad);
		DLL_API int VUGetCurrentLevels();
	private:
		int  VUMeterForSample(int count, float *buffer);
		void OutputThread(const char* lpName);
		void FinishedCallbackMsg(void* userData);
		void ReadChunks();
		void VUMeterInit();

		int left_phase;
		int right_phase;
		int numDevices, defaultDisplayed;
		const PaDeviceInfo *deviceInfo;
		PaStreamParameters inputParameters, outputParameters;
	};
	class Input
	{
	public:
		DLL_API void GetListOfDevices();
		DLL_API void ReadAudioFile(const char* lpFileName);
		FILE* oFile;

	private:
		int		numDevices, defaultDisplayed;
		const	PaDeviceInfo *deviceInfo;
		PaStreamParameters inputParameters, outputParameters;
	};
};