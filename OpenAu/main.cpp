/////////////////////////////////
// VERTVER, 2018 (C)
// OpenAu, Open Audio Utility
// MIT-License
/////////////////////////////////
// main.cpp:
// entry-point
/////////////////////////////////

#include "main.h"
#include "oau.h"

int		argc;
char	*argv[MAX_NUM_ARGVS];

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

void ExceptionTextThrow(std::string sz1, std::string sz2, std::string sz3)
{
	Msg(sz1);
	MessageBoxA(NULL, sz2.c_str(), sz3.c_str(), MB_OK | MB_ICONHAND);
	DEBUG_BREAK;
}

// creating a implemented entry-point for stack overflow
int main_impl(int argc, char *argv[])
{
	try
	{	
		// creating directories for application
		QStringList paths = QCoreApplication::libraryPaths();
		paths.append(".");
		paths.append("platforms");
		QCoreApplication::setLibraryPaths(paths);
		Msg("AuEngine: Created library path");

		// make up UI
		QApplication a(argc, argv);
		OAU w;
		w.show();
		Msg("AuEngine: UI Loaded");

		return a.exec();
	}
	catch (AuEngine::Exception& exc)
	{
		const char* exText;

		switch (exc.opset())
		{
		case AuEngine::OpSet::SUCCESS_ERROR:		// Success (if all done, for testing exceptions)
			exText = "Success";
			Msg(exText);
			MessageBoxA(NULL, exText, exText, MB_OK | MB_ICONINFORMATION);	
			DEBUG_BREAK;
			break;

		case AuEngine::OpSet::UI_ERROR:				// if Qt or UI part can't load		
			ExceptionTextThrow("AuEngine Error: Can't initialize user interface",
				"Can't initialize user interface. Please, re-install application or check directory",
				"UI Init error");
			break;

		case AuEngine::OpSet::INIT_ERROR:			// if main processes can't init
			ExceptionTextThrow("AuEngine Error: Can't initialize appication",
				"Can't initialize appication. Maybe re-install can fix this problem.",
				"Init error");
			break;

		case AuEngine::OpSet::NO_AUDIO_DEVICE:		// if audio device doesn't exist
			ExceptionTextThrow("AuEngine Error: No audio device",
				"No audio device. Please, check audio devices.",
				"Audio device error");
			break;

		case AuEngine::OpSet::STREAM_ERROR:			// if output stream doesn't exist
			ExceptionTextThrow("AuEngine Error: No audio stream",
				"No audio stream. Re-install may fix this problem.",
				"Audio stream error");
			break;

		case AuEngine::OpSet::PORTAUDIO_ERROR:		// if PortAudio throw exception
			ExceptionTextThrow("AuEngine Error: PortAudio error",
				"PortAudio error. Check your file directory.",
				"PortAudio error");
			break;

		case AuEngine::OpSet::ENGINE_ERROR:			// if AuEngine throw exception
			ExceptionTextThrow("AuEngine Error: AuEngine error",
				"AuEngine error. Please, contact developers to fix thix problem.",
				"AuEngine error");
			break;

		default:									// default case
			break;							
		}
	}
}


int main(int argc, char *argv[])
{
	try
	{
		return main_impl(argc, argv);
	}
	catch (...)
	{
		MessageBoxA(NULL, "Unknown Error. Please, close the window.", "Unknown Error", MB_OK | MB_ICONHAND);
		return 0;
	}
}
