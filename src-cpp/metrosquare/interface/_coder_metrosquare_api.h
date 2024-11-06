//
// File: _coder_metrosquare_api.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Nov-2024 23:16:58
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

void prediction_POS(real_T data[64], real_T t_known, real_T *c1, real_T *c2,
                    real_T *c3);

void prediction_POS_api(const mxArray *const prhs[2], int32_T nlhs,
                        const mxArray *plhs[3]);

real_T prediction_my_error(real_T v[3], real_T data[64], real_T t_known);

void prediction_my_error_api(const mxArray *const prhs[3],
                             const mxArray **plhs);

real_T probability_PIMC(real_T kr, real_T kb, real_T data[64], real_T t_known,
                        real_T num_grid_points_r);

void probability_PIMC_api(const mxArray *const prhs[5], const mxArray **plhs);

void run_main(real_T data[64], real_T qb_0, real_T t_known, real_T *kr,
              real_T *kb, real_T *c1, real_T *c2, real_T *c3,
              real_T *probability, real_T t_data[], int32_T t_size[1],
              real_T *qr_0, real_T qtsquare_data[], int32_T qtsquare_size[1],
              real_T qtfisher_data[], int32_T qtfisher_size[1],
              real_T *error_code);

void run_main_api(const mxArray *const prhs[3], int32_T nlhs,
                  const mxArray *plhs[11]);

#endif
//
// File trailer for _coder_metrosquare_api.h
//
// [EOF]
//
