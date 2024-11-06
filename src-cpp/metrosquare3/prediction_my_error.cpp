//
// File: prediction_my_error.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 04-Nov-2024 13:13:25
//

// Include Files
#include "prediction_my_error.h"
#include "find.h"
#include "metrosquare_data.h"
#include "metrosquare_initialize.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Definitions
//
// 一共有31天的数据
//
// Arguments    : const double v[3]
//                const double data[64]
//                double t_known
// Return Type  : double
//
double prediction_my_error(const double v[3], const double data[64],
                           double t_known)
{
  double c1;
  double c2;
  double c3;
  double sum_error;
  int ii_data[64];
  int jj_data[64];
  int ii_size;
  int jj_size;
  boolean_T b_data[64];
  if (!isInitialized_metrosquare) {
    metrosquare_initialize();
  }
  c1 = v[0];
  c2 = v[1];
  c3 = v[2];
  for (ii_size = 0; ii_size < 64; ii_size++) {
    b_data[ii_size] = (data[ii_size] == t_known);
  }
  coder::eml_find(b_data, ii_data, &ii_size, jj_data, &jj_size);
  sum_error = 0.0;
  ii_size = ii_data[0] - 1;
  for (jj_size = 0; jj_size <= ii_size; jj_size++) {
    double a;
    a = -data[jj_size + 32] + (((data[32] - c1 * data[jj_size]) -
                                c2 * std::sin(c1 / c2 * data[jj_size] + c3)) +
                               c2 * std::sin(c3));
    sum_error += a * a;
  }
  return std::sqrt(sum_error);
}

//
// File trailer for prediction_my_error.cpp
//
// [EOF]
//
