//
// File: probability_PIMC.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 15-Nov-2024 22:44:42
//

// Include Files
#include "probability_PIMC.h"
#include "calculate_qtfisher_data.h"
#include "calculate_qtfisher_initialize.h"
#include "calculate_qtsquare.h"
#include "coder_array.h"
#include "rt_nonfinite.h"
#include <cmath>
#include <cstddef>
#include <iostream>
#include <stdio.h>
#include <string>

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
  double d;
  double m_r;
  double omega;
  double qr_0;
  double qr_real;
  int firstBlockLength;
  int nblocks;
  int nbytes;
  if (!isInitialized_calculate_qtfisher) {
    calculate_qtfisher_initialize();
  }
  qr_0 = data[data.size(0)];
  std::cout << "qr_0: " << qr_0 << std::endl;
  // d = std::round(qr_0);
  // if (d < 2.147483648E+9) {
  //   if (d >= -2.147483648E+9) {
  //     firstBlockLength = static_cast<int>(d);
  //   } else {
  //     firstBlockLength = MIN_int32_T;
  //   }
  // } else if (d >= 2.147483648E+9) {
  //   firstBlockLength = MAX_int32_T;
  // } else {
  //   firstBlockLength = 0;
  // }
  // nbytes = snprintf(nullptr, 0, "%d", firstBlockLength);
  // charStr.set_size(1, nbytes + 1);
  // snprintf(&charStr[0], (size_t)(nbytes + 1), "%d", firstBlockLength);
  // if (1 > nbytes) {
  //   nbytes = 0;
  // }

  std::string qr_0_str = std::to_string((int)qr_0);
  int length = qr_0_str.length();
  // m_r = pow(10, -(qr_0_str.length()) - 1);

  m_r = rt_powd_snf(10.0, -static_cast<double>(length) - 1.0);

  qr_real = calculate_qtsquare(kr, kb, t_known, qr_0, qb_0);
  omega = std::sqrt(kr * kb);
  th_gailv.set_size(1, 0);
  A_real_tmp_tmp = std::exp(-omega * t_known);
  b_A_real_tmp_tmp = std::exp(omega * t_known);
  A_real_tmp = std::exp(-omega * 0.0);
  a = (qr_real * A_real_tmp - qr_0 * A_real_tmp_tmp) /
      (b_A_real_tmp_tmp - A_real_tmp_tmp);
  B_real_tmp = std::exp(omega * 0.0);
  a_tmp = std::exp(omega * t_known) - std::exp(-omega * t_known);
  bsum = (qr_0 * b_A_real_tmp_tmp - qr_real * B_real_tmp) / a_tmp;
  S_real_tmp = -std::exp(-2.0 * t_known * omega) + std::exp(-2.0 * omega *
  0.0); b_S_real_tmp = std::exp(2.0 * t_known * omega) - std::exp(2.0 * omega
  * 0.0); S_real = (0.5 * (bsum * bsum) * S_real_tmp + 0.5 * (a * a) *
  b_S_real_tmp) *
           m_r * omega;
  d = qr_real - num_grid_points_r;
  nblocks = static_cast<int>((qr_real + num_grid_points_r) + (1.0 - d));
  for (nbytes = 0; nbytes < nblocks; nbytes++) {
    qr_real = d + static_cast<double>(nbytes);
    a = (qr_real * A_real_tmp - qr_0 * A_real_tmp_tmp) / a_tmp;
    bsum = (qr_0 * b_A_real_tmp_tmp - qr_real * B_real_tmp) / a_tmp;
    firstBlockLength = th_gailv.size(1);
    th_gailv.set_size(1, th_gailv.size(1) + 1);
    th_gailv[firstBlockLength] = std::exp(
        -((0.5 * (bsum * bsum) * S_real_tmp + 0.5 * (a * a) * b_S_real_tmp) *
              m_r * omega -
          S_real) *
        2.0);
  }
  if (th_gailv.size(1) == 0) {
    qr_real = 0.0;
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
    qr_real = th_gailv[0];
    for (k = 2; k <= firstBlockLength; k++) {
      qr_real += th_gailv[k - 1];
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
      qr_real += bsum;
    }
  }
  th_gailv.set_size(1, th_gailv.size(1));
  firstBlockLength = th_gailv.size(1) - 1;
  for (nblocks = 0; nblocks <= firstBlockLength; nblocks++) {
    th_gailv[nblocks] = th_gailv[nblocks] / qr_real;
  }
  // 分柱状区间
  qr_real = num_grid_points_r / 5.0;
  // 区间宽度
  bsum = num_grid_points_r * 2.0 / qr_real;
  // 区间数量
  firstBlockLength = static_cast<int>(bsum);
  box.set_size(firstBlockLength);
  for (nblocks = 0; nblocks < firstBlockLength; nblocks++) {
    box[nblocks] = 0.0;
  }
  // 建立区间进行统计
  nblocks = static_cast<int>(num_grid_points_r * 2.0);
  for (firstBlockLength = 0; firstBlockLength < nblocks; firstBlockLength++)
  {
    qr_0 = std::trunc(((static_cast<double>(firstBlockLength) + 1.0) - 1.0) /
                      qr_real);
    box[static_cast<int>(qr_0 + 1.0) - 1] =
        box[static_cast<int>(qr_0 + 1.0) - 1] + th_gailv[firstBlockLength];
  }
  return box[static_cast<int>(std::trunc(bsum / 2.0) + 1.0) - 1];
}

//
// File trailer for probability_PIMC.cpp
//
// [EOF]
//

// double probability_PIMC(double kr, double kb,
//                         const coder::array<double, 2U> &data, double qb_0,
//                         double t_known, double num_grid_points_r)
// {
//   // 用来计算Lanchester方程平方律各个末态所对应最小作用量/概率的理论值

//   double t0 = 0;
//   double qr_0 = data[data.size(0)];

//   // 计算m_r (将数字转为字符串计算位数)
//   std::string qr_0_str = std::to_string((int)qr_0);
//   int length = qr_0_str.length();
//   // m_r = pow(10, -(qr_0_str.length()) - 1);

//   double m_r = rt_powd_snf(10.0, -static_cast<double>(length) - 1.0);

//   double t = t_known;
//   // 假设calculate_qtsquare是已经实现的函数
//   double qr_real = calculate_qtsquare(kr, kb, t, qr_0, qb_0);
//   double omega = sqrt(kr * kb);
//   double T = t - t0;

//   coder::array<double, 1U> th_S_cl;
//   coder::array<double, 1U> th_gailv;
//   th_S_cl.set_size(2 * num_grid_points_r + 1);
//   th_gailv.set_size(2 * num_grid_points_r + 1);

//   // 计算实际值
//   double A_real = (qr_real * exp(-omega * t0) - qr_0 * exp(-omega * t)) /
//                   (exp(omega * T) - exp(-omega * T));
//   double B_real = (qr_0 * exp(omega * t) - qr_real * exp(omega * t0)) /
//                   (exp(omega * T) - exp(-omega * T));
//   double S_real =
//       (0.5 * pow(B_real, 2) * (-exp(-2 * t * omega) + exp(-2 * omega * t0)) +
//        0.5 * pow(A_real, 2) * (exp(2 * t * omega) - exp(2 * omega * t0))) *
//       m_r * omega;

//   // 计算每个点的概率
//   int idx = 0;
//   for (double qr = qr_real - num_grid_points_r;
//        qr <= qr_real + num_grid_points_r; qr++) {
//     double A = (qr * exp(-omega * t0) - qr_0 * exp(-omega * t)) /
//                (exp(omega * T) - exp(-omega * T));
//     double B = (qr_0 * exp(omega * t) - qr * exp(omega * t0)) /
//                (exp(omega * T) - exp(-omega * T));

//     double S =
//         (0.5 * pow(B, 2) * (-exp(-2 * t * omega) + exp(-2 * omega * t0)) +
//          0.5 * pow(A, 2) * (exp(2 * t * omega) - exp(2 * omega * t0))) *
//             m_r * omega -
//         S_real;

//     th_S_cl[idx] = S;
//     th_gailv[idx] = exp(-S * 2);
//     idx++;
//   }

//   // 归一化概率
//   double sum_gailv = 0;
//   for (int i = 0; i < th_gailv.size(0); i++) {
//     sum_gailv += th_gailv[i];
//   }
//   for (int i = 0; i < th_gailv.size(0); i++) {
//     th_gailv[i] /= sum_gailv;
//   }

//   // 分柱状区间
//   int num_interval = num_grid_points_r / 5;             // 区间宽度
//   int num_box = (num_grid_points_r * 2) / num_interval; // 区间数量
//   coder::array<double, 1U> box;
//   box.set_size(num_box);

//   // 初始化box数组
//   for (int i = 0; i < num_box; i++) {
//     box[i] = 0.0;
//   }

//   // 统计区间
//   for (int final_pos_ridx = 0; final_pos_ridx < num_grid_points_r * 2;
//        final_pos_ridx++) {
//     int box_i = final_pos_ridx / num_interval;
//     box[box_i] += th_gailv[final_pos_ridx];
//   }

//   return box[num_box / 2];
// }