//
// File: my_error_square.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 03-Nov-2024 23:50:41
//

// Include Files
#include "my_error_square.h"
#include "find.h"
#include "metrosquare_data.h"
#include "metrosquare_initialize.h"
#include <cmath>

// Function Definitions
//
// Arguments    : const double v_data[]
//                const int v_size[2]
//                const double data[64]
//                double qb_0
//                double t_known
// Return Type  : double
//
double b_my_error_square(const double v_data[], const int v_size[2],
                         const double data[64], double qb_0, double t_known)
{
  double kb;
  double kr;
  double sum_error;
  int ii_data[64];
  int jj_data[64];
  int ii_size;
  int jj_size;
  boolean_T b_data[64];
  //  平方律拟合数据计算函数
  kr = v_data[0];
  kb = v_data[v_size[0]];
  for (ii_size = 0; ii_size < 64; ii_size++) {
    b_data[ii_size] = (data[ii_size] == t_known);
  }
  coder::eml_find(b_data, ii_data, &ii_size, jj_data, &jj_size);
  sum_error = 0.0;
  ii_size = ii_data[0] - 1;
  for (jj_size = 0; jj_size <= ii_size; jj_size++) {
    double a_tmp;
    a_tmp = std::sqrt(kr * kb) * data[jj_size];
    a_tmp = (-data[jj_size + 32] + data[32] * std::cosh(a_tmp)) -
            std::sqrt(kb / kr) * qb_0 * std::sinh(a_tmp);
    sum_error += a_tmp * a_tmp;
  }
  return std::sqrt(sum_error);
}

//
// Arguments    : const double v[2]
//                const double data[64]
//                double qb_0
//                double t_known
// Return Type  : double
//
double my_error_square(const double v[2], const double data[64], double qb_0,
                       double t_known)
{
  double kb;
  double kr;
  double sum_error;
  int ii_data[64];
  int jj_data[64];
  int ii_size;
  int jj_size;
  boolean_T b_data[64];
  if (!isInitialized_metrosquare) {
    metrosquare_initialize();
  }
  //  平方律拟合数据计算函数
  kr = v[0];
  kb = v[1];
  for (ii_size = 0; ii_size < 64; ii_size++) {
    b_data[ii_size] = (data[ii_size] == t_known);
  }
  coder::eml_find(b_data, ii_data, &ii_size, jj_data, &jj_size);
  sum_error = 0.0;
  ii_size = ii_data[0] - 1;
  for (jj_size = 0; jj_size <= ii_size; jj_size++) {
    double a_tmp;
    a_tmp = std::sqrt(kr * kb) * data[jj_size];
    a_tmp = (-data[jj_size + 32] + data[32] * std::cosh(a_tmp)) -
            std::sqrt(kb / kr) * qb_0 * std::sinh(a_tmp);
    sum_error += a_tmp * a_tmp;
  }
  return std::sqrt(sum_error);
}

//
// File trailer for my_error_square.cpp
//
// [EOF]
//
