//
// File: _coder_calculate_qtfisher_mex.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 15-Nov-2024 22:44:42
//

#ifndef _CODER_CALCULATE_QTFISHER_MEX_H
#define _CODER_CALCULATE_QTFISHER_MEX_H

// Include Files
#include "emlrt.h"
#include "mex.h"
#include "tmwtypes.h"

// Function Declarations
MEXFUNCTION_LINKAGE void mexFunction(int32_T nlhs, mxArray *plhs[],
                                     int32_T nrhs, const mxArray *prhs[]);

emlrtCTX mexFunctionCreateRootTLS();

void unsafe_calculate_qtfisher_mexFunction(int32_T nlhs, mxArray *plhs[1],
                                           int32_T nrhs,
                                           const mxArray *prhs[5]);

void unsafe_calculate_qtsquare_mexFunction(int32_T nlhs, mxArray *plhs[1],
                                           int32_T nrhs,
                                           const mxArray *prhs[5]);

void unsafe_metrosquare_mexFunction(int32_T nlhs, mxArray *plhs[2],
                                    int32_T nrhs, const mxArray *prhs[3]);

void unsafe_my_error_square_mexFunction(int32_T nlhs, mxArray *plhs[1],
                                        int32_T nrhs, const mxArray *prhs[4]);

void unsafe_prediction_POS_mexFunction(int32_T nlhs, mxArray *plhs[3],
                                       int32_T nrhs, const mxArray *prhs[2]);

void unsafe_prediction_my_error_mexFunction(int32_T nlhs, mxArray *plhs[1],
                                            int32_T nrhs,
                                            const mxArray *prhs[3]);

void unsafe_probability_PIMC_mexFunction(int32_T nlhs, mxArray *plhs[1],
                                         int32_T nrhs, const mxArray *prhs[6]);

void unsafe_run_main_mexFunction(int32_T nlhs, mxArray *plhs[11], int32_T nrhs,
                                 const mxArray *prhs[3]);

#endif
//
// File trailer for _coder_calculate_qtfisher_mex.h
//
// [EOF]
//
