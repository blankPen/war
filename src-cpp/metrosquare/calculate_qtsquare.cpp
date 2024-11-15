//
// File: calculate_qtsquare.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 15-Nov-2024 22:44:42
//

// Include Files
#include "calculate_qtsquare.h"
#include "calculate_qtfisher_data.h"
#include "calculate_qtfisher_initialize.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Definitions
//
// Arguments    : double kr
//                double kb
//                double t
//                double qr_0
//                double qb_0
// Return Type  : double
//
double calculate_qtsquare(double kr, double kb, double t, double qr_0,
                          double qb_0)
{
  double qtsquare_tmp;
  if (!isInitialized_calculate_qtfisher) {
    calculate_qtfisher_initialize();
  }
  qtsquare_tmp = std::sqrt(kr * kb) * t;
  return std::round(qr_0 * std::cosh(qtsquare_tmp) -
                    std::sqrt(kb / kr) * qb_0 * std::sinh(qtsquare_tmp));
}

//
// File trailer for calculate_qtsquare.cpp
//
// [EOF]
//
