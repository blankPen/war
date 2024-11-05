//
// File: probability_PIMC.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 04-Nov-2024 13:13:25
//

// Include Files
#include "probability_PIMC.h"
#include "metrosquare_data.h"
#include "metrosquare_initialize.h"
#include "rt_nonfinite.h"
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
//                const double data[64]
//                double t_known
//                double num_grid_points_r
// Return Type  : double
//
double probability_PIMC(double kr, double kb, const double data[64],
                        double t_known, double num_grid_points_r)
{
  coder::array<double, 2U> th_gailv;
  coder::array<double, 1U> box;
  coder::array<char, 2U> charStr;
  double A_real_tmp;
  double B_real_tmp;
  double S_real;
  double S_real_tmp;
  double a;
  double a_tmp;
  double b_a_tmp;
  double bsum;
  double d;
  double m_r;
  double omega;
  double qr_0;
  double sum_gailv;
  double t_tmp;
  int hi;
  int nbytes;
  int xblockoffset;
  if (!isInitialized_metrosquare) {
    metrosquare_initialize();
  }
  qr_0 = data[32];
  nbytes = snprintf(nullptr, 0, "%f", data[32]);
  charStr.set_size(1, nbytes + 1);
  snprintf(&charStr[0], (size_t)(nbytes + 1), "%f", data[32]);
  if (1 > nbytes) {
    nbytes = 0;
  }
  m_r = rt_powd_snf(10.0, -static_cast<double>(nbytes) - 1.0);
  t_tmp = data[static_cast<int>(t_known + 1.0) - 1];
  omega = std::sqrt(kr * kb);
  th_gailv.set_size(1, 0);
  sum_gailv = std::exp(-omega * t_tmp);
  bsum = std::exp(omega * t_tmp);
  A_real_tmp = std::exp(-omega * 0.0);
  a_tmp = data[static_cast<int>(t_known + 1.0) + 31];
  a = (a_tmp * A_real_tmp - data[32] * sum_gailv) / (bsum - sum_gailv);
  B_real_tmp = std::exp(omega * 0.0);
  b_a_tmp = std::exp(omega * data[static_cast<int>(t_known + 1.0) - 1]) -
            std::exp(-omega * data[static_cast<int>(t_known + 1.0) - 1]);
  sum_gailv = (data[32] * bsum - a_tmp * B_real_tmp) / b_a_tmp;
  bsum = -std::exp(-2.0 * t_tmp * omega) + std::exp(-2.0 * omega * 0.0);
  S_real_tmp = std::exp(2.0 * t_tmp * omega) - std::exp(2.0 * omega * 0.0);
  S_real = (0.5 * (sum_gailv * sum_gailv) * bsum + 0.5 * (a * a) * S_real_tmp) *
           m_r * omega;
  d = a_tmp - num_grid_points_r;
  hi = static_cast<int>((a_tmp + num_grid_points_r) + (1.0 - d));
  for (nbytes = 0; nbytes < hi; nbytes++) {
    sum_gailv = d + static_cast<double>(nbytes);
    a = (sum_gailv * A_real_tmp - qr_0 * std::exp(-omega * t_tmp)) / b_a_tmp;
    sum_gailv =
        (qr_0 * std::exp(omega * t_tmp) - sum_gailv * B_real_tmp) / b_a_tmp;
    xblockoffset = th_gailv.size(1);
    th_gailv.set_size(1, th_gailv.size(1) + 1);
    th_gailv[xblockoffset] = std::exp(
        -((0.5 * (sum_gailv * sum_gailv) * bsum + 0.5 * (a * a) * S_real_tmp) *
              m_r * omega -
          S_real) *
        2.0);
  }
  if (th_gailv.size(1) == 0) {
    sum_gailv = 0.0;
  } else {
    int k;
    int lastBlockLength;
    int nblocks;
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
    sum_gailv = th_gailv[0];
    for (k = 2; k <= nbytes; k++) {
      sum_gailv += th_gailv[k - 1];
    }
    for (nbytes = 2; nbytes <= nblocks; nbytes++) {
      xblockoffset = (nbytes - 1) << 10;
      bsum = th_gailv[xblockoffset];
      if (nbytes == nblocks) {
        hi = lastBlockLength;
      } else {
        hi = 1024;
      }
      for (k = 2; k <= hi; k++) {
        bsum += th_gailv[(xblockoffset + k) - 1];
      }
      sum_gailv += bsum;
    }
  }
  th_gailv.set_size(1, th_gailv.size(1));
  nbytes = th_gailv.size(1) - 1;
  for (hi = 0; hi <= nbytes; hi++) {
    th_gailv[hi] = th_gailv[hi] / sum_gailv;
  }
  // 分柱状区间
  sum_gailv = num_grid_points_r / 5.0;
  // 区间宽度
  bsum = num_grid_points_r * 2.0 / sum_gailv;
  // 区间数量
  nbytes = static_cast<int>(bsum);
  box.set_size(nbytes);
  for (hi = 0; hi < nbytes; hi++) {
    box[hi] = 0.0;
  }
  // 建立区间进行统计
  hi = static_cast<int>(num_grid_points_r * 2.0);
  for (nbytes = 0; nbytes < hi; nbytes++) {
    S_real_tmp =
        std::trunc(((static_cast<double>(nbytes) + 1.0) - 1.0) / sum_gailv);
    box[static_cast<int>(S_real_tmp + 1.0) - 1] =
        box[static_cast<int>(S_real_tmp + 1.0) - 1] + th_gailv[nbytes];
  }
  return box[static_cast<int>(std::trunc(bsum / 2.0) + 1.0) - 1];
}

//
// File trailer for probability_PIMC.cpp
//
// [EOF]
//
