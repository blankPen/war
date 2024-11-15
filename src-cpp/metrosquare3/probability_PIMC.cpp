//
// File: probability_PIMC.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 12-Nov-2024 22:50:14
//

// Include Files
#include "probability_PIMC.h"
#include "metrosquare_data.h"
#include "metrosquare_initialize.h"
#include "rt_nonfinite.h"
#include "sqrt.h"
#include "coder_array.h"
#include <cmath>
#include <cstddef>
#include <stdio.h>

// Function Declarations
static double rt_powd_snf(double u0, double u1);

// Function Definitions
//
// Arguments    : double u0
//                double u1
// Return Type  : double
//
static double rt_powd_snf(double u0, double u1)
{
  double y;
  if (std::isnan(u0) || std::isnan(u1)) {
    y = rtNaN;
  } else {
    double d;
    double d1;
    d = std::abs(u0);
    d1 = std::abs(u1);
    if (std::isinf(u1)) {
      if (d == 1.0) {
        y = 1.0;
      } else if (d > 1.0) {
        if (u1 > 0.0) {
          y = rtInf;
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = rtInf;
      }
    } else if (d1 == 0.0) {
      y = 1.0;
    } else if (d1 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = std::sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > std::floor(u1))) {
      y = rtNaN;
    } else {
      y = std::pow(u0, u1);
    }
  }
  return y;
}

//
// 用来计算Lanchester方程平方律各个末态所对应最小作用量/概率的理论值
//
// Arguments    : double kr
//                double kb
//                const coder::array<double, 2U> &data
//                double t_known
//                double num_grid_points_r
// Return Type  : double
//
double probability_PIMC(double kr, double kb,
                        const coder::array<double, 2U> &data, double t_known,
                        double num_grid_points_r)
{
  coder::array<double, 2U> th_gailv;
  coder::array<double, 1U> box;
  coder::array<char, 2U> charStr;
  creal_T dc;
  double A_real_tmp;
  double A_real_tmp_tmp;
  double B_real_tmp;
  double a;
  double a_tmp;
  double apnd;
  double b_A_real_tmp_tmp;
  double b_a_tmp;
  double b_tmp;
  double cdiff;
  double m_r;
  double ndbl;
  double qr_0;
  double qr_real;
  double t;
  int k;
  int nblocks;
  int nbytes;
  int nm1d2;
  if (!isInitialized_metrosquare) {
    metrosquare_initialize();
  }
  qr_0 = data[data.size(0)];
  nbytes = snprintf(nullptr, 0, "%f", qr_0);
  charStr.set_size(1, nbytes + 1);
  snprintf(&charStr[0], (size_t)(nbytes + 1), "%f", qr_0);
  if (1 > nbytes) {
    nbytes = 0;
  }
  m_r = rt_powd_snf(10.0, -static_cast<double>(nbytes) - 1.0);
  t = data[static_cast<int>(t_known + 1.0) - 1];
  qr_real = data[(static_cast<int>(t_known + 1.0) + data.size(0)) - 1];
  dc.re = kr * kb;
  dc.im = 0.0;
  coder::b_sqrt(&dc);
  a_tmp = qr_real - num_grid_points_r;
  b_tmp = qr_real + num_grid_points_r;
  if (std::isnan(a_tmp) || std::isnan(b_tmp)) {
    th_gailv.set_size(th_gailv.size(0), 1);
  } else if (b_tmp < a_tmp) {
    th_gailv.set_size(th_gailv.size(0), 0);
  } else if ((std::isinf(a_tmp) || std::isinf(b_tmp)) && (a_tmp == b_tmp)) {
    th_gailv.set_size(th_gailv.size(0), 1);
  } else if (std::floor(a_tmp) == a_tmp) {
    th_gailv.set_size(th_gailv.size(0),
                      static_cast<int>(std::floor(b_tmp - a_tmp)) + 1);
  } else {
    ndbl = std::floor((b_tmp - a_tmp) + 0.5);
    apnd = a_tmp + ndbl;
    cdiff = apnd - b_tmp;
    if (std::abs(cdiff) <
        4.4408920985006262E-16 * std::fmax(std::abs(a_tmp), std::abs(b_tmp))) {
      ndbl++;
      apnd = b_tmp;
    } else if (cdiff > 0.0) {
      apnd = a_tmp + (ndbl - 1.0);
    } else {
      ndbl++;
    }
    if (ndbl >= 0.0) {
      nbytes = static_cast<int>(ndbl);
    } else {
      nbytes = 0;
    }
    th_gailv.set_size(1, nbytes);
    if ((nbytes > 0) && (nbytes > 1)) {
      th_gailv[nbytes - 1] = apnd;
      nm1d2 = (nbytes - 1) / 2;
      for (k = 0; k <= nm1d2 - 2; k++) {
        th_gailv[k + 1] = a_tmp + (static_cast<double>(k) + 1.0);
        th_gailv[(nbytes - k) - 2] = apnd - (static_cast<double>(k) + 1.0);
      }
      if (nm1d2 << 1 == nbytes - 1) {
        th_gailv[nm1d2] = (a_tmp + apnd) / 2.0;
      } else {
        th_gailv[nm1d2] = a_tmp + static_cast<double>(nm1d2);
        th_gailv[nm1d2 + 1] = apnd - static_cast<double>(nm1d2);
      }
    }
  }
  nbytes = th_gailv.size(1);
  th_gailv.set_size(1, nbytes);
  for (nblocks = 0; nblocks < nbytes; nblocks++) {
    th_gailv[nblocks] = 0.0;
  }
  A_real_tmp_tmp = std::exp(-dc.re * t);
  b_A_real_tmp_tmp = std::exp(dc.re * t);
  A_real_tmp = std::exp(-dc.re * 0.0);
  a = (qr_real * A_real_tmp - qr_0 * A_real_tmp_tmp) /
      (b_A_real_tmp_tmp - A_real_tmp_tmp);
  B_real_tmp = std::exp(dc.re * 0.0);
  b_a_tmp = std::exp(dc.re * t) - std::exp(-dc.re * t);
  ndbl = (qr_0 * b_A_real_tmp_tmp - qr_real * B_real_tmp) / b_a_tmp;
  qr_real = -std::exp(-2.0 * t * dc.re) + std::exp(-2.0 * dc.re * 0.0);
  apnd = std::exp(2.0 * t * dc.re) - std::exp(2.0 * dc.re * 0.0);
  cdiff = (0.5 * (ndbl * ndbl) * qr_real + 0.5 * (a * a) * apnd) * m_r * dc.re;
  nblocks = static_cast<int>(b_tmp + (1.0 - a_tmp));
  for (nm1d2 = 0; nm1d2 < nblocks; nm1d2++) {
    ndbl = a_tmp + static_cast<double>(nm1d2);
    a = (ndbl * A_real_tmp - qr_0 * A_real_tmp_tmp) / b_a_tmp;
    ndbl = (qr_0 * b_A_real_tmp_tmp - ndbl * B_real_tmp) / b_a_tmp;
    nbytes = th_gailv.size(1);
    th_gailv.set_size(1, th_gailv.size(1) + 1);
    th_gailv[nbytes] = std::exp(
        -((0.5 * (ndbl * ndbl) * qr_real + 0.5 * (a * a) * apnd) * m_r * dc.re -
          cdiff) *
        2.0);
  }
  if (th_gailv.size(1) == 0) {
    ndbl = 0.0;
  } else {
    int lastBlockLength;
    if (th_gailv.size(1) <= 1024) {
      nbytes = th_gailv.size(1);
      lastBlockLength = 0;
      nblocks = 1;
    } else {
      nbytes = 1024;
      nblocks = th_gailv.size(1) / 1024;
      lastBlockLength = th_gailv.size(1) - (nblocks << 10);
      if (lastBlockLength > 0) {
        nblocks++;
      } else {
        lastBlockLength = 1024;
      }
    }
    ndbl = th_gailv[0];
    for (k = 2; k <= nbytes; k++) {
      ndbl += th_gailv[k - 1];
    }
    for (int ib{2}; ib <= nblocks; ib++) {
      nbytes = (ib - 1) << 10;
      apnd = th_gailv[nbytes];
      if (ib == nblocks) {
        nm1d2 = lastBlockLength;
      } else {
        nm1d2 = 1024;
      }
      for (k = 2; k <= nm1d2; k++) {
        apnd += th_gailv[(nbytes + k) - 1];
      }
      ndbl += apnd;
    }
  }
  th_gailv.set_size(1, th_gailv.size(1));
  nbytes = th_gailv.size(1) - 1;
  for (nblocks = 0; nblocks <= nbytes; nblocks++) {
    th_gailv[nblocks] = th_gailv[nblocks] / ndbl;
  }
  // 分柱状区间
  ndbl = num_grid_points_r / 5.0;
  // 区间宽度
  apnd = num_grid_points_r * 2.0 / ndbl;
  // 区间数量
  nbytes = static_cast<int>(apnd);
  box.set_size(nbytes);
  for (nblocks = 0; nblocks < nbytes; nblocks++) {
    box[nblocks] = 0.0;
  }
  // 建立区间进行统计
  nblocks = static_cast<int>(num_grid_points_r * 2.0);
  for (nbytes = 0; nbytes < nblocks; nbytes++) {
    cdiff = std::trunc(((static_cast<double>(nbytes) + 1.0) - 1.0) / ndbl);
    box[static_cast<int>(cdiff + 1.0) - 1] =
        box[static_cast<int>(cdiff + 1.0) - 1] + th_gailv[nbytes];
  }
  return box[static_cast<int>(std::trunc(apnd / 2.0) + 1.0) - 1];
}

//
// File trailer for probability_PIMC.cpp
//
// [EOF]
//
