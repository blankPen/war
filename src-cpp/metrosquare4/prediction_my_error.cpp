//
// File: prediction_my_error.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 15-Nov-2024 21:35:36
//

// Include Files
#include "prediction_my_error.h"
#include "calculate_qtfisher_data.h"
#include "calculate_qtfisher_initialize.h"
#include "find.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
//
// 一共有31天的数据
//
// Arguments    : const double v[3]
//                const coder::array<double, 2U> &data
//                double t_known
// Return Type  : double
//
double prediction_my_error(const double v[3],
                           const coder::array<double, 2U> &data, double t_known)
{
  coder::array<int, 1U> ii;
  coder::array<int, 1U> jj;
  coder::array<boolean_T, 2U> b_data;
  double c1;
  double c2;
  double c3;
  double sum_error;
  int i;
  int loop_ub;
  if (!isInitialized_calculate_qtfisher) {
    calculate_qtfisher_initialize();
  }
  c1 = v[0];
  c2 = v[1];
  c3 = v[2];
  b_data.set_size(data.size(0), 2);
  loop_ub = data.size(0) * 2;
  for (i = 0; i < loop_ub; i++) {
    b_data[i] = (data[i] == t_known);
  }
  coder::eml_find(b_data, ii, jj);
  sum_error = 0.0;
  i = ii[0] - 1;
  for (loop_ub = 0; loop_ub <= i; loop_ub++) {
    double ti;
    ti = data[loop_ub];
    ti = -data[loop_ub + data.size(0)] +
         (((data[data.size(0)] - c1 * ti) - c2 * std::sin(c1 / c2 * ti + c3)) +
          c2 * std::sin(c3));
    sum_error += ti * ti;
  }
  return std::sqrt(sum_error);
}

//
// File trailer for prediction_my_error.cpp
//
// [EOF]
//
