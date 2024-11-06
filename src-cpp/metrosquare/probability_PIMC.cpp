//
// File: probability_PIMC.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Nov-2024 23:16:58
//

// Include Files
#include "probability_PIMC.h"
#include "coder_array.h"
#include "metrosquare_data.h"
#include "metrosquare_initialize.h"
#include "rt_nonfinite.h"
#include "sqrt.h"
#include <cmath>
#include <cstddef>
#include <iostream>
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
  double t0 = 0;
  double qr_0 = data[32];
  double m_r = std::pow(
      10,
      static_cast<int>(-std::to_string(static_cast<int>(qr_0)).length() - 1));
  double t = data[static_cast<int>(t_known)];
  double qr_real = data[32 + static_cast<int>(t_known)];
  double omega = std::sqrt(kr * kb);
  double T = t - t0;

  std::vector<double> th_S_cl;
  std::vector<double> th_gailv;

  // A_real 和 B_real 的计算
  double A_real =
      (qr_real * std::exp(-omega * t0) - qr_0 * std::exp(-omega * t)) /
      (std::exp(omega * T) - std::exp(-omega * T));
  double B_real =
      ((qr_0 * std::exp(omega * t) - qr_real * std::exp(omega * t0)) /
       (std::exp(omega * T) - std::exp(-omega * T)));

  // 提取公共计算变量
  double exp_term1 = exp(-2 * t * omega);
  double exp_term2 = exp(2 * t * omega);
  double exp_term3 = exp(-2 * omega * t0);

  // 计算中间变量
  double term1 = -exp_term1 + exp_term3;
  double term2 = exp_term2 - exp_term3;

  // 计算 B_real 和 A_real 的平方
  double B_real_squared = B_real * B_real;
  double A_real_squared = A_real * A_real;

  // 计算 S_real
  double S_real =
      (0.5 * B_real_squared * term1 + 0.5 * A_real_squared * term2) * m_r *
      omega;
  std::cout << "xxx  " << 0.5 * B_real_squared * term1 << std::endl;
  std::cout << "xxx  " << 0.5 * A_real_squared * term2 << std::endl;
  std::cout << "exp_term1  " << exp_term1 << std::endl;
  std::cout << "exp_term2  " << exp_term2 << std::endl;
  std::cout << "exp_term3  " << exp_term3 << std::endl;
  std::cout << "term1  " << term1 << std::endl;
  std::cout << "term2  " << term2 << std::endl;
  std::cout << "B_real_squared  " << B_real_squared << std::endl;
  std::cout << "A_real_squared  " << A_real_squared << std::endl;
  std::cout << "A_real  " << A_real << std::endl;
  std::cout << "B_real  " << B_real << std::endl;
  std::cout << "S_real  " << S_real << std::endl;

  for (double qr = qr_real - num_grid_points_r;
       qr <= qr_real + num_grid_points_r; qr += 1) {
    double A = (qr * std::exp(-omega * t0) - qr_0 * std::exp(-omega * t)) /
               (std::exp(omega * T) - std::exp(-omega * T));
    double B = ((qr_0 * std::exp(omega * t) - qr * std::exp(omega * t0)) /
                (std::exp(omega * T) - std::exp(-omega * T)));
    th_S_cl.push_back(
        (0.5 * B * B * (-std::exp(-2 * t * omega) + std::exp(-2 * omega * t0)) +
         0.5 * A * A * (std::exp(2 * t * omega) - std::exp(2 * omega * t0))) *
            m_r * omega -
        S_real);
    th_gailv.push_back(std::exp(
        -((0.5 * B * B *
               (-std::exp(-2 * t * omega) + std::exp(-2 * omega * t0)) +
           0.5 * A * A * (std::exp(2 * t * omega) - std::exp(2 * omega * t0))) *
              m_r * omega -
          S_real) *
        2));
  }

  double sum_gailv = 0;
  for (double g : th_gailv) {
    sum_gailv += g;
  }

  for (size_t i = 0; i < th_gailv.size(); ++i) {
    th_gailv[i] /= sum_gailv;
  }

  int num_interval = num_grid_points_r / 5;
  int num_box = (num_grid_points_r * 2) / num_interval;
  std::vector<double> box(num_box, 0);

  for (int final_pos_ridx = 0; final_pos_ridx < num_grid_points_r * 2;
       ++final_pos_ridx) {
    int box_i = (final_pos_ridx - 1) / num_interval + 1;
    box[box_i - 1] += th_gailv[final_pos_ridx];
  }

  return box[num_box / 2];
}

//
// File trailer for probability_PIMC.cpp
//
// [EOF]
//
