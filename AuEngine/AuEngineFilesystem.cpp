#include "AuEngine.h"
FILE* lFile;
int iFileType;

void AuEngine::FileSystem::CreateFileInBuffer(FILE* oFile, size_t szBuffer)
{

}

void AuEngine::FileSystem::OpenFileByPart(const char* lpPath)
{
	lFile = fopen(lpPath, "rb");
	if (!lFile)
	{
		// Without UI this is a critical error
		THROW_EXCEPTION(AuEngine::OpSet::ENGINE_ERROR);
	}

	//fseek(lFile, 0, SEEK_END);
	//long fileSize = ftell(lFile);
	//void* buffer = malloc(fileSize);
	//fseek(lFile, 0, SEEK_SET);

	if (freadStr(lFile, 4) == "RIFF")
	{
		uint32_t wavechunksize = freadNum<uint32_t>(lFile);
		CHECK(freadStr(lFile, 4) == "WAVE");
		iFileType = 1;				// WAV_FILE
	}
	else if (freadStr(lFile, 4) == "FORM")
	{
		uint32_t wavechunksize = freadNum<uint32_t>(lFile);
		CHECK(freadStr(lFile, 4) == "AIFF");
		iFileType = 2;				// AIF_FILE
	}
	else if (freadStr(lFile, 3) == "ID3")
	{
		iFileType = 3;				// MP3_FILE
	}
	else if (freadStr(lFile, 12) == "   ftypmp42")
	{
		iFileType = 4;				// MP3C_FILE
	}
	else if (freadStr(lFile, 11) == "    ftypM4A")
	{
		iFileType = 6;				// AAC_FILE (M4A)
	}
	else if (freadStr(lFile, 4) == "fLaC")
	{
		iFileType = 5;				// FLAC_FILE
	}
}

