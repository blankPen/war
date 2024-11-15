//
// File: probability_PIMC.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 15-Nov-2024 21:35:36
//

// Include Files
#include "probability_PIMC.h"
#include "calculate_qtfisher_data.h"
#include "calculate_qtfisher_initialize.h"
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
//                const coder::array<double, 2U> &data
//                double qb_0
//                double t_known
//                double num_grid_points_r
// Return Type  : double
//
double probability_PIMC(double kr, double kb,
                        const coder::array<double, 2U> &data, double qb_0,
                        double t_known, double num_grid_points_r)
{
  coder::array<double, 2U> th_gailv;
  coder::array<double, 1U> box;
  coder::array<char, 2U> charStr;
  double A_real_tmp;
  double A_real_tmp_tmp;
  double B_real_tmp;
  double S_real;
  double S_real_tmp;
  double a;
  double a_tmp;
  double b_A_real_tmp_tmp;
  double b_S_real_tmp;
  double bsum;
  double m_r;
  double qr_0;
  double qr_real;
  double qr_real_tmp_tmp;
  double sum_gailv;
  int firstBlockLength;
  int nblocks;
  int nbytes;
  if (!isInitialized_calculate_qtfisher) {
    calculate_qtfisher_initialize();
  }
  qr_0 = data[data.size(0)];
  bsum = std::round(qr_0);
  if (bsum < 2.147483648E+9) {
    if (bsum >= -2.147483648E+9) {
      firstBlockLength = static_cast<int>(bsum);
    } else {
      firstBlockLength = MIN_int32_T;
    }
  } else if (bsum >= 2.147483648E+9) {
    firstBlockLength = MAX_int32_T;
  } else {
    firstBlockLength = 0;
  }
  nbytes = snprintf(nullptr, 0, "%d", firstBlockLength);
  charStr.set_size(1, nbytes + 1);
  snprintf(&charStr[0], (size_t)(nbytes + 1), "%d", firstBlockLength);
  if (1 > nbytes) {
    nbytes = 0;
  }
  m_r = rt_powd_snf(10.0, -static_cast<double>(nbytes) - 1.0);
  qr_real_tmp_tmp = std::sqrt(kr * kb);
  sum_gailv = qr_real_tmp_tmp * t_known;
  qr_real = std::round(qr_0 * std::cosh(sum_gailv) -
                       std::sqrt(kb / kr) * qb_0 * std::sinh(sum_gailv));
  th_gailv.set_size(1, 0);
  A_real_tmp_tmp = std::exp(-qr_real_tmp_tmp * t_known);
  b_A_real_tmp_tmp = std::exp(sum_gailv);
  A_real_tmp = std::exp(-qr_real_tmp_tmp * 0.0);
  a = (qr_real * A_real_tmp - qr_0 * A_real_tmp_tmp) /
      (b_A_real_tmp_tmp - A_real_tmp_tmp);
  B_real_tmp = std::exp(qr_real_tmp_tmp * 0.0);
  a_tmp = std::exp(qr_real_tmp_tmp * t_known) -
          std::exp(-qr_real_tmp_tmp * t_known);
  sum_gailv = (qr_0 * b_A_real_tmp_tmp - qr_real * B_real_tmp) / a_tmp;
  S_real_tmp = -std::exp(-2.0 * t_known * qr_real_tmp_tmp) +
               std::exp(-2.0 * qr_real_tmp_tmp * 0.0);
  b_S_real_tmp = std::exp(2.0 * t_known * qr_real_tmp_tmp) -
                 std::exp(2.0 * qr_real_tmp_tmp * 0.0);
  S_real = (0.5 * (sum_gailv * sum_gailv) * S_real_tmp +
            0.5 * (a * a) * b_S_real_tmp) *
           m_r * qr_real_tmp_tmp;
  bsum = qr_real - num_grid_points_r;
  nblocks = static_cast<int>((qr_real + num_grid_points_r) + (1.0 - bsum));
  for (nbytes = 0; nbytes < nblocks; nbytes++) {
    sum_gailv = bsum + static_cast<double>(nbytes);
    a = (sum_gailv * A_real_tmp - qr_0 * A_real_tmp_tmp) / a_tmp;
    sum_gailv = (qr_0 * b_A_real_tmp_tmp - sum_gailv * B_real_tmp) / a_tmp;
    firstBlockLength = th_gailv.size(1);
    th_gailv.set_size(1, th_gailv.size(1) + 1);
    th_gailv[firstBlockLength] =
        std::exp(-((0.5 * (sum_gailv * sum_gailv) * S_real_tmp +
                    0.5 * (a * a) * b_S_real_tmp) *
                       m_r * qr_real_tmp_tmp -
                   S_real) *
                 2.0);
  }
  if (th_gailv.size(1) == 0) {
    sum_gailv = 0.0;
  } else {
    int k;
    int lastBlockLength;
    if (th_gailv.size(1) <= 1024) {
      firstBlockLength = th_gailv.size(1);
      lastBlockLength = 0;
      nblocks = 1;
    } else {
      firstBlockLength = 1024;
      nblocks = th_gailv.size(1) / 1024;
      lastBlockLength = th_gailv.size(1) - (nblocks << 10);
      if (lastBlockLength > 0) {
        nblocks++;
      } else {
        lastBlockLength = 1024;
      }
    }
    sum_gailv = th_gailv[0];
    for (k = 2; k <= firstBlockLength; k++) {
      sum_gailv += th_gailv[k - 1];
    }
    for (int ib{2}; ib <= nblocks; ib++) {
      nbytes = (ib - 1) << 10;
      bsum = th_gailv[nbytes];
      if (ib == nblocks) {
        firstBlockLength = lastBlockLength;
      } else {
        firstBlockLength = 1024;
      }
      for (k = 2; k <= firstBlockLength; k++) {
        bsum += th_gailv[(nbytes + k) - 1];
      }
      sum_gailv += bsum;
    }
  }
  th_gailv.set_size(1, th_gailv.size(1));
  firstBlockLength = th_gailv.size(1) - 1;
  for (nblocks = 0; nblocks <= firstBlockLength; nblocks++) {
    th_gailv[nblocks] = th_gailv[nblocks] / sum_gailv;
  }
  // 分柱状区间
  sum_gailv = num_grid_points_r / 5.0;
  // 区间宽度
  bsum = num_grid_points_r * 2.0 / sum_gailv;
  // 区间数量
  firstBlockLength = static_cast<int>(bsum);
  box.set_size(firstBlockLength);
  for (nblocks = 0; nblocks < firstBlockLength; nblocks++) {
    box[nblocks] = 0.0;
  }
  // 建立区间进行统计
  nblocks = static_cast<int>(num_grid_points_r * 2.0);
  for (firstBlockLength = 0; firstBlockLength < nblocks; firstBlockLength++) {
    qr_real = std::trunc(((static_cast<double>(firstBlockLength) + 1.0) - 1.0) /
                         sum_gailv);
    box[static_cast<int>(qr_real + 1.0) - 1] =
        box[static_cast<int>(qr_real + 1.0) - 1] + th_gailv[firstBlockLength];
  }
  return box[static_cast<int>(std::trunc(bsum / 2.0) + 1.0) - 1];
}

//
// File trailer for probability_PIMC.cpp
//
// [EOF]
//
