//
// File: run_main.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 04-Nov-2024 13:13:25
//

#ifndef RUN_MAIN_H
#define RUN_MAIN_H

// Include Files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
extern void run_main(const double data[64], double qb_0, double t_known,
                     const double *kr, const double *kb, const double *c1,
                     const double *c2, const double *c3, double *probability,
                     double t_data[], int t_size[1], double *qr_0,
                     double qtsquare_data[], int qtsquare_size[1],
                     double qtfisher_data[], int qtfisher_size[1],
                     double *error_code);

#endif
//
// File trailer for run_main.h
//
// [EOF]
//
