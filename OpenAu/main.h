/////////////////////////////////
// VERTVER, 2018 (C)
// OpenAu, Open Audio Utility
// MIT-License
/////////////////////////////////
// main.h:
// entry-point header
/////////////////////////////////
#pragma once

#include <windows.h>
#include <string>
void Msg(std::string szMessage);
void Msg(std::string szMessage, int iNum);

struct buffer_data
{
	uint8_t *ptr;
	size_t size; // size left in the buffer
};
