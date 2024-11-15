//
// File: calculate_qtfisher.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 15-Nov-2024 22:44:42
//

// Include Files
#include "calculate_qtfisher.h"
#include "calculate_qtfisher_data.h"
#include "calculate_qtfisher_initialize.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Definitions
//
// Arguments    : double c1
//                double c2
//                double c3
//                double t
//                double qr_0
// Return Type  : double
//
double calculate_qtfisher(double c1, double c2, double c3, double t,
                          double qr_0)
{
  if (!isInitialized_calculate_qtfisher) {
    calculate_qtfisher_initialize();
  }
  return std::round(((qr_0 - c1 * t) - c2 * std::sin(c1 / c2 * t + c3)) +
                    c2 * std::sin(c3));
}

//
// File trailer for calculate_qtfisher.cpp
//
// [EOF]
//
