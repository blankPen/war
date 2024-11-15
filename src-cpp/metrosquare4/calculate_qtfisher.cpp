//
// File: calculate_qtfisher.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 15-Nov-2024 21:35:36
//

// Include Files
#include "calculate_qtfisher.h"
#include "calculate_qtfisher_data.h"
#include "calculate_qtfisher_initialize.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Declarations
static void binary_expand_op(coder::array<double, 1U> &qtfisher, double qr_0,
                             double c1, const coder::array<double, 1U> &t,
                             double c2, double x);

// Function Definitions
//
// Arguments    : coder::array<double, 1U> &qtfisher
//                double qr_0
//                double c1
//                const coder::array<double, 1U> &t
//                double c2
//                double x
// Return Type  : void
//
static void binary_expand_op(coder::array<double, 1U> &qtfisher, double qr_0,
                             double c1, const coder::array<double, 1U> &t,
                             double c2, double x)
{
  coder::array<double, 1U> b_qr_0;
  double b_c2;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  b_c2 = c2 * x;
  if (qtfisher.size(0) == 1) {
    i = t.size(0);
  } else {
    i = qtfisher.size(0);
  }
  b_qr_0.set_size(i);
  stride_0_0 = (t.size(0) != 1);
  stride_1_0 = (qtfisher.size(0) != 1);
  if (qtfisher.size(0) == 1) {
    loop_ub = t.size(0);
  } else {
    loop_ub = qtfisher.size(0);
  }
  for (i = 0; i < loop_ub; i++) {
    b_qr_0[i] =
        ((qr_0 - c1 * t[i * stride_0_0]) - c2 * qtfisher[i * stride_1_0]) +
        b_c2;
  }
  qtfisher.set_size(b_qr_0.size(0));
  loop_ub = b_qr_0.size(0);
  for (i = 0; i < loop_ub; i++) {
    qtfisher[i] = b_qr_0[i];
  }
}

//
// Arguments    : double c1
//                double c2
//                double c3
//                const coder::array<double, 1U> &t
//                double qr_0
//                coder::array<double, 1U> &qtfisher
// Return Type  : void
//
void calculate_qtfisher(double c1, double c2, double c3,
                        const coder::array<double, 1U> &t, double qr_0,
                        coder::array<double, 1U> &qtfisher)
{
  double a;
  int k;
  int nx;
  if (!isInitialized_calculate_qtfisher) {
    calculate_qtfisher_initialize();
  }
  a = c1 / c2;
  qtfisher.set_size(t.size(0));
  nx = t.size(0);
  for (k = 0; k < nx; k++) {
    qtfisher[k] = a * t[k] + c3;
  }
  nx = qtfisher.size(0);
  for (k = 0; k < nx; k++) {
    qtfisher[k] = std::sin(qtfisher[k]);
  }
  a = std::sin(c3);
  if (t.size(0) == qtfisher.size(0)) {
    a *= c2;
    qtfisher.set_size(t.size(0));
    nx = t.size(0);
    for (k = 0; k < nx; k++) {
      qtfisher[k] = ((qr_0 - c1 * t[k]) - c2 * qtfisher[k]) + a;
    }
  } else {
    binary_expand_op(qtfisher, qr_0, c1, t, c2, a);
  }
  nx = qtfisher.size(0);
  for (k = 0; k < nx; k++) {
    qtfisher[k] = std::round(qtfisher[k]);
  }
}

//
// File trailer for calculate_qtfisher.cpp
//
// [EOF]
//
