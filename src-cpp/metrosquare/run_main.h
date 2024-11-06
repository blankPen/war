//
// File: run_main.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Nov-2024 23:16:58
//

#ifndef RUN_MAIN_H
#define RUN_MAIN_H

// Include Files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
extern void run_main(const double data[64], double qb_0, double t_known,
                     double *kr, double *kb, double *c1, double *c2, double *c3,
                     double *probability, double t_data[], int t_size[1],
                     double *qr_0, double qtsquare_data[], int qtsquare_size[1],
                     double qtfisher_data[], int qtfisher_size[1],
                     double *error_code);

#endif
//
// File trailer for run_main.h
//
// [EOF]
//
