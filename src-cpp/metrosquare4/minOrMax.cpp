//
// File: minOrMax.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 15-Nov-2024 21:35:36
//

// Include Files
#include "minOrMax.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Definitions
//
// Arguments    : const double x[2]
// Return Type  : double
//
namespace coder {
namespace internal {
double minimum(const double x[2])
{
  double ex;
  if ((x[0] > x[1]) || (std::isnan(x[0]) && (!std::isnan(x[1])))) {
    ex = x[1];
  } else {
    ex = x[0];
  }
  return ex;
}

} // namespace internal
} // namespace coder

//
// File trailer for minOrMax.cpp
//
// [EOF]
//
