//
// File: run_main.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Nov-2024 23:16:58
//

// Include Files
#include "run_main.h"
#include "metrosquare.h"
#include "metrosquare_data.h"
#include "metrosquare_initialize.h"
#include "minOrMax.h"
#include "prediction_POS.h"
#include "probability_PIMC.h"
#include "rt_nonfinite.h"
#include "sqrt.h"
#include <algorithm>
#include <cmath>
#include <math.h>
#include <iostream>

// Function Definitions
//
//
// Arguments    : const double data[]
//                double qb_0
//                double t_known
//                double *kr
//                double *kb
//                double *c1
//                double *c2
//                double *c3
//                double *probability
//                double t_data[]
//                int t_size[1]
//                double *qr_0
//                double qtsquare_data[]
//                int qtsquare_size[1]
//                double qtfisher_data[]
//                int qtfisher_size[1]
//                double *error_code
// Return Type  : void
//
void run_main(const double data[], int size, double qb_0, double t_known, double *kr,
              double *kb, double *c1, double *c2, double *c3,
              double *probability, double t_data[], int t_size[1], double *qr_0,
              double qtsquare_data[], int qtsquare_size[1],
              double qtfisher_data[], int qtfisher_size[1], double *error_code)
{
  creal_T dc;

  int half_size = static_cast<int>(size / 2);
  std::cout << "This is an info message  :" << half_size << std::endl;
  double* y_data = new double[half_size];
  double b_data[2];
  int exponent;
  if (!isInitialized_metrosquare) {
    metrosquare_initialize();
  }
  *kr = rtNaN;
  *kb = rtNaN;
  *c1 = rtNaN;
  *c2 = rtNaN;
  *c3 = rtNaN;
  *probability = rtNaN;
  t_size[0] = 1;
  t_data[0] = rtNaN;
  *qr_0 = rtNaN;
  qtsquare_size[0] = 1;
  qtsquare_data[0] = rtNaN;
  qtfisher_size[0] = 1;
  qtfisher_data[0] = rtNaN;
  *error_code = rtNaN;

  
  if (qb_0 < 0.0) {
    *error_code = 1.0;
    // std::cout << "error_code" << error_code << std::endl;
    // quit
  } else {
      // std::cout << "rr" << error_code << std::endl;
    b_data[0] = data[0];
    b_data[1] = data[half_size];
    if (coder::internal::b_minimum(b_data) < 0.0) {
      *error_code = 2.0;
      
      // std::cout << "error_code2" << error_code << std::endl;
      // quit
    } else {
      b_data[0] = data[1];
      b_data[1] = data[half_size + 1];
      if (coder::internal::b_minimum(b_data) < 0.0) {
        *error_code = 3.0;
      // std::cout << "error_code3" << error_code << std::endl;
        // quit
      } else {
        double absx;
        int k;
        boolean_T exitg1;
        boolean_T tf;
        tf = false;
        k = 0;
        exitg1 = false;
        while ((!exitg1) && (k < half_size)) {
          absx = std::abs(data[k] / 2.0);
          if ((!std::isinf(absx)) && (!std::isnan(absx))) {
            if (absx <= 2.2250738585072014E-308) {
              absx = 4.94065645841247E-324;
            } else {
              frexp(absx, &exponent);
              absx = std::ldexp(1.0, exponent - 53);
            }
          } else {
            absx = rtNaN;
          }
          if ((std::abs(data[k] - t_known) < absx) ||
              (std::isinf(t_known) && std::isinf(data[k]) &&
               ((t_known > 0.0) == (data[k] > 0.0)))) {
            tf = true;
            exitg1 = true;
          } else {
            k++;
          }
        }
        if (tf) {
          double a;
          double b_a;
          double b_c2;
          metrosquare(data, size, qb_0, t_known, kr, kb);
          prediction_POS(data, size, t_known, c1, c2, c3);
          *probability = probability_PIMC(*kr, *kb, data, t_known,
                                          std::round(data[half_size] / 100.0) * 20.0, size);
          t_size[0] = half_size;
          std::copy(&data[0], &data[half_size], &t_data[0]);
          *qr_0 = data[half_size];
          absx = *kr * *kb;
          dc.re = absx;
          dc.im = 0.0;
          coder::b_sqrt(&dc);
          for (k = 0; k < half_size; k++) {
            y_data[k] = std::cosh(dc.re * data[k]);
          }
          dc.re = absx;
          dc.im = 0.0;
          coder::b_sqrt(&dc);
          a = std::sqrt(*kb / *kr) * qb_0;
          std::cout << "a: " << kb << std::endl;
          std::cout << "a: " << kr << std::endl;
          std::cout << "a: " << qb_0 << std::endl;
          qtsquare_size[0] = half_size;
          b_a = *c1 / *c2;
          b_c2 = *c2 * std::sin(*c3);
          qtfisher_size[0] = half_size;
          for (k = 0; k < half_size; k++) {
            absx = data[k];

            qtsquare_data[k] =
                std::round(data[half_size] * y_data[k] - a * std::sinh(dc.re * absx));
            absx = std::round(
                ((data[half_size] - *c1 * absx) - *c2 * std::sin(b_a * absx + *c3)) +
                b_c2);
            y_data[k] = absx;
            qtfisher_data[k] = absx;
          }
        } else {
          *error_code = 4.0;
          // quit
        }
      }
    }
  }
}

//
// File trailer for run_main.cpp
//
// [EOF]
//
