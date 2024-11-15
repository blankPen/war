//
// File: my_error_square.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 15-Nov-2024 21:35:36
//

// Include Files
#include "my_error_square.h"
#include "calculate_qtfisher_data.h"
#include "calculate_qtfisher_initialize.h"
#include "find.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
//
// Arguments    : const double v[2]
//                const coder::array<double, 2U> &data
//                double qb_0
//                double t_known
// Return Type  : double
//
double my_error_square(const double v[2], const coder::array<double, 2U> &data,
                       double qb_0, double t_known)
{
  coder::array<int, 1U> ii;
  coder::array<int, 1U> jj;
  coder::array<boolean_T, 2U> b_data;
  double kb;
  double kr;
  double qr_0;
  double sum_error;
  int i;
  int loop_ub;
  if (!isInitialized_calculate_qtfisher) {
    calculate_qtfisher_initialize();
  }
  //  平方律拟合数据计算函数
  kr = v[0];
  kb = v[1];
  b_data.set_size(data.size(0), 2);
  loop_ub = data.size(0) * 2;
  for (i = 0; i < loop_ub; i++) {
    b_data[i] = (data[i] == t_known);
  }
  coder::eml_find(b_data, ii, jj);
  qr_0 = data[data.size(0)];
  sum_error = 0.0;
  i = ii[0] - 2;
  for (loop_ub = 0; loop_ub <= i; loop_ub++) {
    double a_tmp;
    // a =
    // min(qrsquarelist(i-1),qr_0*cosh(sqrt(kr*kb)*ti)-(kb/kr)^0.5*qb_0*sinh(sqrt(kr*kb)*ti));
    a_tmp = std::sqrt(kr * kb) * data[loop_ub + 1];
    a_tmp = -data[(loop_ub + data.size(0)) + 1] +
            (qr_0 * std::cosh(a_tmp) -
             std::sqrt(kb / kr) * qb_0 * std::sinh(a_tmp));
    sum_error += a_tmp * a_tmp;
  }
  return std::sqrt(sum_error);
}

//
// File trailer for my_error_square.cpp
//
// [EOF]
//
