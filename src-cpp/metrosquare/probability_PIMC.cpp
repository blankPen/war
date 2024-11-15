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
//
// Arguments    : double kr
//                double kb
//                const double data[]
//                double t_known
//                double num_grid_points_r
// Return Type  : double
//
double probability_PIMC(double kr, double kb, const double data[],
                        double t_known, double num_grid_points_r, int size)
{
  double t0 = 0;
  double qr_0 = data[size/2];
  double m_r = std::pow(
      10,
      static_cast<int>(-std::to_string(static_cast<int>(qr_0)).length() - 1));
  double t = data[static_cast<int>(t_known)];
  double qr_real = data[size/2 + static_cast<int>(t_known)];
  double omega = std::sqrt(kr * kb);
  double T = t - t0;

  std::vector<double> th_S_cl;
  std::vector<double> th_gailv;

  double A_real =
      (qr_real * std::exp(-omega * t0) - qr_0 * std::exp(-omega * t)) /
      (std::exp(omega * T) - std::exp(-omega * T));
  double B_real =
      ((qr_0 * std::exp(omega * t) - qr_real * std::exp(omega * t0)) /
       (std::exp(omega * T) - std::exp(-omega * T)));

  double exp_term1 = exp(-2 * t * omega);
  double exp_term2 = exp(2 * t * omega);
  double exp_term3 = exp(-2 * omega * t0);

  double term1 = -exp_term1 + exp_term3;
  double term2 = exp_term2 - exp_term3;

  double B_real_squared = B_real * B_real;
  double A_real_squared = A_real * A_real;

  double S_real =
      (0.5 * B_real_squared * term1 + 0.5 * A_real_squared * term2) * m_r *
      omega;

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
