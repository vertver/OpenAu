/////////////////////////////////
// VERTVER, 2018 (C)
// OpenAu, Open Audio Utility
// MIT-License
/////////////////////////////////
// AuEngineFFT.cpp:
// FFT analyse for EQ
/////////////////////////////////

#include "AuEngineMath.h"

#ifdef _OPENCL_MATH_
DLL_API bool OpenCL_FFT = true;
#else
DLL_API bool OpenCL_FFT = false;
#endif

