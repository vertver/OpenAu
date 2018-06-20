/////////////////////////////////
// VERTVER, 2018 (C)
// OpenAu, Open Audio Utility
// MIT-License
/////////////////////////////////
// AuEngineMath.h:
// header for AuEngineMath
/////////////////////////////////
#pragma once

#define _OPENCL_MATH_
#ifdef _OPENCL_MATH_
#include <CL/opencl.h>
#endif
#include "AuEngine.h"

#define FFT_EXP_SIZE (13)
#define NUM_SECONDS (20)


static float ComputeShape(float atten);

struct FFTStruct 
{
	int bitReverse[32768];		// 2^15, max size for FFT
	int bits;
};

class AuMath 
{
public:
	void FFTProcess(void* FFT, float a[2], float b[3], float mem1[4], float mem2[4], int winmode);
	void*FFTInit(int i);
	void FFTClose();
	void ConvertToFFT(void* fft, float* xr, float* xi, bool inv);

	void BuildHammingWindow(float* window, int size);
	void BuildHannWindow(float* window, int size);
	void BuildKaiserWindow(float* window, float shape, int size);
	void BuildBlackmanWindow(float* window, int size);
	void BuildBlackmanHarrisWindow(float* window, int size);

	void ApplyWindow(float* window, float *data, int size);

	void ComputeSecondOrderLowPassParameters(float sRate, float f, float* a, float* b);
	float ProcessSecondOrderFilter(float x, float* mem, float* a, float* b);
	float ZeroEthOrderBessel(float x);

	void SignalHandler(int signum);

private:
};