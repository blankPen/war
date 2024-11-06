//
// File: run_main.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 04-Nov-2024 13:13:25
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
#include <cmath>
#include <math.h>
#include <stdio.h>
#include <iostream>

// Function Definitions
//
// 一、测试函数
//
// Arguments    : const double data[64]
//                double qb_0
//                double t_known
//                const double *kr
//                const double *kb
//                const double *c1
//                const double *c2
//                const double *c3
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
void run_main(const double data[64], double qb_0, double t_known,
              const double *kr, const double *kb, const double *c1,
              const double *c2, const double *c3, double *probability,
              double t_data[], int t_size[1], double *qr_0,
              double qtsquare_data[], int qtsquare_size[1],
              double qtfisher_data[], int qtfisher_size[1], double *error_code)
{
  double b_data[2];
  double a;
  double absx;
  double b_a;
  double b_c2;
  int exponent;
  int k;
  boolean_T exitg1;
  boolean_T tf;
  if (!isInitialized_metrosquare) {
    metrosquare_initialize();
  }
  *error_code = rtNaN;
  // if (qb_0 < 0.0) {
  //   *error_code = 1.0;
  //   //  '输入错误：兵力数应为非负数'
  //   // quit
  //   // getchar();
  //   return;
  // }
  // b_data[0] = data[0];
  // b_data[1] = data[32];

  // if (coder::internal::minimum(b_data) < 0.0) {
  //   *error_code = 2.0;
  //   // '输入错误：时间应为非负数'
  //   // quit
  //   // getchar();
  //   return;
  // }
  // b_data[0] = data[1];
  // b_data[1] = data[33];
  // if (coder::internal::minimum(b_data) < 0.0) {
  //   *error_code = 3.0;
  //   // '输入错误：兵力数应为非负数'
  //   // quit
  //   // getchar();
  //   return;
  // }
  // tf = false;
  // k = 0;
  // exitg1 = false;
  // while ((!exitg1) && (k < 32)) {
  //   absx = std::abs(data[k] / 2.0);
  //   if ((!std::isinf(absx)) && (!std::isnan(absx))) {
  //     if (absx <= 2.2250738585072014E-308) {
  //       absx = 4.94065645841247E-324;
  //     } else {
  //       frexp(absx, &exponent);
  //       absx = std::ldexp(1.0, exponent - 53);
  //     }
  //   } else {
  //     absx = rtNaN;
  //   }

  //   if ((std::abs(data[k] - t_known) < absx) ||
  //       (std::isinf(t_known) && std::isinf(data[k]) &&
  //        ((t_known > 0.0) == (data[k] > 0.0)))) {
  //     tf = true;
  //     exitg1 = true;
  //   } else {
  //     k++;
  //   }
  // }
  // if (!tf) {
  //   *error_code = 4.0;
  //   // '输入错误：输入数据中未包含已知时间数据'
  //   // quit
  //   // getchar();
  //   return;
  // }

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
  *qr_0 = data[32];
  absx = std::sqrt(*kr * *kb);
  a = std::sqrt(*kb / *kr) * qb_0;
  qtsquare_size[0] = 32;
  b_a = *c1 / *c2;
  b_c2 = *c2 * std::sin(*c3);
  qtfisher_size[0] = 32;
  for (k = 0; k < 32; k++) {
    double d;
    double d1;
    d = data[k];
    t_data[k] = d;
    d1 = absx * d;
    std::cout << "d: " << d << std::endl;
    std::cout << "d1: " << d1 << std::endl;
    std::cout << "absx: " << absx << std::endl;
    std::cout << "kr: " << kr << std::endl;
    std::cout << "kb: " << kb << std::endl;

    qtsquare_data[k] = std::round(data[32] * std::cosh(d1) - a * std::sinh(d1));
    qtfisher_data[k] = std::round(
        ((data[32] - *c1 * d) - *c2 * std::sin(b_a * d + *c3)) + b_c2);
  }
}

//
// File trailer for run_main.cpp
//
// [EOF]
//
