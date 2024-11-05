//
// File: _coder_metrosquare_api.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 03-Nov-2024 23:50:41
//

#ifndef _CODER_METROSQUARE_API_H
#define _CODER_METROSQUARE_API_H

// Include Files
#include "emlrt.h"
#include "tmwtypes.h"
#include <algorithm>
#include <cstring>

// Variable Declarations
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

// Function Declarations
void metrosquare(real_T data[64], real_T qb_0, real_T t_known, real_T *kr,
                 real_T *kb);

void metrosquare_api(const mxArray *const prhs[3], int32_T nlhs,
                     const mxArray *plhs[2]);

void metrosquare_atexit();

void metrosquare_initialize();

void metrosquare_terminate();

void metrosquare_xil_shutdown();

void metrosquare_xil_terminate();

real_T my_error_square(real_T v[2], real_T data[64], real_T qb_0,
                       real_T t_known);

void my_error_square_api(const mxArray *const prhs[4], const mxArray **plhs);

void run_main(real_T data[64], real_T qb_0, real_T t_known, real_T *kr,
              real_T *kb);

void run_main_api(const mxArray *const prhs[3], int32_T nlhs,
                  const mxArray *plhs[2]);

#endif
//
// File trailer for _coder_metrosquare_api.h
//
// [EOF]
//
