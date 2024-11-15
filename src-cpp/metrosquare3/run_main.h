//
// File: run_main.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 12-Nov-2024 22:50:14
//

#ifndef RUN_MAIN_H
#define RUN_MAIN_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
extern void run_main(const coder::array<double, 2U> &data, double qb_0,
                     double t_known, double *kr, double *kb, double *c1,
                     double *c2, double *c3, double *probability,
                     coder::array<double, 1U> &t, double *qr_0,
                     coder::array<double, 1U> &qtsquare,
                     coder::array<double, 1U> &qtfisher, double *error_code);

#endif
//
// File trailer for run_main.h
//
// [EOF]
//
