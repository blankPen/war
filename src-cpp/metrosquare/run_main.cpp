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
// 一、测试函数
//
// Arguments    : const double data[64]
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
void run_main(const double data[64], double qb_0, double t_known, double *kr,
              double *kb, double *c1, double *c2, double *c3,
              double *probability, double t_data[], int t_size[1], double *qr_0,
              double qtsquare_data[], int qtsquare_size[1],
              double qtfisher_data[], int qtfisher_size[1], double *error_code)
{
  creal_T dc;
  double y_data[32];
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
    //  '输入错误：兵力数应为非负数'
    // quit
  } else {
    b_data[0] = data[0];
    b_data[1] = data[32];
    if (coder::internal::b_minimum(b_data) < 0.0) {
      *error_code = 2.0;
      // '输入错误：时间应为非负数'
      // quit
    } else {
      b_data[0] = data[1];
      b_data[1] = data[33];
      if (coder::internal::b_minimum(b_data) < 0.0) {
        *error_code = 3.0;
        // '输入错误：兵力数应为非负数'
        // quit
      } else {
        double absx;
        int k;
        boolean_T exitg1;
        boolean_T tf;
        tf = false;
        k = 0;
        exitg1 = false;
        while ((!exitg1) && (k < 32)) {
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
          //   二、数据导入（实现参数赋值）
          //   三、运算分析（模型的数值运算）
          metrosquare(data, qb_0, t_known, kr, kb);
          // 平方律模型参数计算
          prediction_POS(data, t_known, c1, c2, c3);
          // 本项目模型参数计算
          *probability = probability_PIMC(*kr, *kb, data, t_known,
                                          std::round(data[32] / 100.0) * 20.0);
          // 路径积分概率计算
          t_size[0] = 32;
          std::copy(&data[0], &data[32], &t_data[0]);
          *qr_0 = data[32];
          absx = *kr * *kb;
          dc.re = absx;
          dc.im = 0.0;
          coder::b_sqrt(&dc);
          for (k = 0; k < 32; k++) {
            y_data[k] = std::cosh(dc.re * data[k]);
          }
          dc.re = absx;
          dc.im = 0.0;
          coder::b_sqrt(&dc);
          a = std::sqrt(*kb / *kr) * qb_0;
          qtsquare_size[0] = 32;
          b_a = *c1 / *c2;
          b_c2 = *c2 * std::sin(*c3);
          qtfisher_size[0] = 32;
          for (k = 0; k < 32; k++) {
            absx = data[k];
            qtsquare_data[k] =
                std::round(data[32] * y_data[k] - a * std::sinh(dc.re * absx));
            absx = std::round(
                ((data[32] - *c1 * absx) - *c2 * std::sin(b_a * absx + *c3)) +
                b_c2);
            y_data[k] = absx;
            qtfisher_data[k] = absx;
          }
        } else {
          *error_code = 4.0;
          // '输入错误：输入数据中未包含已知时间数据'
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
