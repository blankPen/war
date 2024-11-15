//
// File: calculate_qtsquare.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 15-Nov-2024 21:35:36
//

// Include Files
#include "calculate_qtsquare.h"
#include "calculate_qtfisher_data.h"
#include "calculate_qtfisher_initialize.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Declarations
static void binary_expand_op(coder::array<double, 1U> &qtsquare, double qr_0,
                             double a, const coder::array<double, 1U> &y);

// Function Definitions
//
// Arguments    : coder::array<double, 1U> &qtsquare
//                double qr_0
//                double a
//                const coder::array<double, 1U> &y
// Return Type  : void
//
static void binary_expand_op(coder::array<double, 1U> &qtsquare, double qr_0,
                             double a, const coder::array<double, 1U> &y)
{
  coder::array<double, 1U> b_qr_0;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  if (y.size(0) == 1) {
    i = qtsquare.size(0);
  } else {
    i = y.size(0);
  }
  b_qr_0.set_size(i);
  stride_0_0 = (qtsquare.size(0) != 1);
  stride_1_0 = (y.size(0) != 1);
  if (y.size(0) == 1) {
    loop_ub = qtsquare.size(0);
  } else {
    loop_ub = y.size(0);
  }
  for (i = 0; i < loop_ub; i++) {
    b_qr_0[i] = qr_0 * qtsquare[i * stride_0_0] - a * y[i * stride_1_0];
  }
  qtsquare.set_size(b_qr_0.size(0));
  loop_ub = b_qr_0.size(0);
  for (i = 0; i < loop_ub; i++) {
    qtsquare[i] = b_qr_0[i];
  }
}

//
// Arguments    : double kr
//                double kb
//                const coder::array<double, 1U> &t
//                double qr_0
//                double qb_0
//                coder::array<double, 1U> &qtsquare
// Return Type  : void
//
void calculate_qtsquare(double kr, double kb, const coder::array<double, 1U> &t,
                        double qr_0, double qb_0,
                        coder::array<double, 1U> &qtsquare)
{
  coder::array<double, 1U> y;
  double a_tmp;
  int k;
  int nx;
  if (!isInitialized_calculate_qtfisher) {
    calculate_qtfisher_initialize();
  }
  a_tmp = std::sqrt(kr * kb);
  qtsquare.set_size(t.size(0));
  nx = t.size(0);
  for (k = 0; k < nx; k++) {
    qtsquare[k] = a_tmp * t[k];
  }
  nx = qtsquare.size(0);
  for (k = 0; k < nx; k++) {
    qtsquare[k] = std::cosh(qtsquare[k]);
  }
  y.set_size(t.size(0));
  nx = t.size(0);
  for (k = 0; k < nx; k++) {
    y[k] = a_tmp * t[k];
  }
  a_tmp = std::sqrt(kb / kr) * qb_0;
  nx = y.size(0);
  for (k = 0; k < nx; k++) {
    y[k] = std::sinh(y[k]);
  }
  if (qtsquare.size(0) == y.size(0)) {
    nx = qtsquare.size(0);
    for (k = 0; k < nx; k++) {
      qtsquare[k] = qr_0 * qtsquare[k] - a_tmp * y[k];
    }
  } else {
    binary_expand_op(qtsquare, qr_0, a_tmp, y);
  }
  nx = qtsquare.size(0);
  for (k = 0; k < nx; k++) {
    qtsquare[k] = std::round(qtsquare[k]);
  }
}

//
// File trailer for calculate_qtsquare.cpp
//
// [EOF]
//
