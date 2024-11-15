//
// File: run_main.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 15-Nov-2024 22:44:42
//

// Include Files
#include "run_main.h"
#include "calculate_qtfisher.h"
#include "calculate_qtfisher_data.h"
#include "calculate_qtfisher_initialize.h"
#include "calculate_qtsquare.h"
#include "metrosquare.h"
#include "minOrMax.h"
#include "prediction_POS.h"
#include "probability_PIMC.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>
#include <math.h>

// Function Definitions
//
// 一、测试函数
//
// Arguments    : const coder::array<double, 2U> &data
//                double qb_0
//                double t_known
//                double *kr
//                double *kb
//                double *c1
//                double *c2
//                double *c3
//                double *probability
//                coder::array<double, 1U> &t
//                double *qr_0
//                coder::array<double, 1U> &qtsquare
//                coder::array<double, 1U> &qtfisher
//                double *error_code
// Return Type  : void
//
void run_main(const coder::array<double, 2U> &data, double qb_0, double t_known,
              double *kr, double *kb, double *c1, double *c2, double *c3,
              double *probability, coder::array<double, 1U> &t, double *qr_0,
              coder::array<double, 1U> &qtsquare,
              coder::array<double, 1U> &qtfisher, double *error_code)
{
  double b_data[2];
  int exponent;
  if (!isInitialized_calculate_qtfisher) {
    calculate_qtfisher_initialize();
  }
  *kr = rtNaN;
  *kb = rtNaN;
  *c1 = rtNaN;
  *c2 = rtNaN;
  *c3 = rtNaN;
  *probability = rtNaN;
  t.set_size(1);
  t[0] = rtNaN;
  *qr_0 = rtNaN;
  qtsquare.set_size(1);
  qtsquare[0] = rtNaN;
  qtfisher.set_size(1);
  qtfisher[0] = rtNaN;
  *error_code = rtNaN;
  if (qb_0 < 0.0) {
    *error_code = 1.0;
    // quit
  } else {
    b_data[0] = data[0];
    b_data[1] = data[data.size(0)];
    if (coder::internal::minimum(b_data) < 0.0) {
      *error_code = 2.0;
      // quit
    } else {
      b_data[0] = data[1];
      b_data[1] = data[data.size(0) + 1];
      if (coder::internal::minimum(b_data) < 0.0) {
        *error_code = 3.0;
        // quit
      } else {
        double absx;
        int k;
        boolean_T exitg1;
        boolean_T tf;
        tf = false;
        k = 0;
        exitg1 = false;
        while ((!exitg1) && (k <= data.size(0) - 1)) {
          double b;
          b = data[k];
          absx = std::abs(b / 2.0);
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
              (std::isinf(t_known) && std::isinf(b) &&
               ((t_known > 0.0) == (data[k] > 0.0)))) {
            tf = true;
            exitg1 = true;
          } else {
            k++;
          }
        }
        if (tf) {
          //   二、数据导入（实现参数赋值）
          //   三、运算分析（模型的数值运算）
          metrosquare(data, qb_0, t_known, kr, kb);
          // 平方律模型参数计算
          prediction_POS(data, t_known, c1, c2, c3);
          // 本项目模型参数计算
          *probability =
              probability_PIMC(*kr, *kb, data, qb_0, t_known,
                               std::round(data[data.size(0)] / 100.0) * 20.0);
          // 路径积分概率计算
          k = data.size(0);
          t.set_size(data.size(0));
          for (exponent = 0; exponent < k; exponent++) {
            t[exponent] = data[exponent];
          }
          *qr_0 = data[data.size(0)];
          //  初始化数组来存储结果
          qtsquare.set_size(data.size(0));
          k = data.size(0);
          for (exponent = 0; exponent < k; exponent++) {
            qtsquare[exponent] = 0.0;
          }
          qtfisher.set_size(data.size(0));
          k = data.size(0);
          for (exponent = 0; exponent < k; exponent++) {
            qtfisher[exponent] = 0.0;
          }
          //  fprintf('kr：%.9f\n', length(t));
          //  循环计算
          exponent = data.size(0) - 1;
          for (k = 0; k <= exponent; k++) {
            //  当前时间点
            //  fprintf('kr：%.9f\n', ti);
            //  计算每个时间点的 qtsquare 和 qtfisher
            absx = data[k];
            qtsquare[k] = calculate_qtsquare(*kr, *kb, absx, *qr_0, qb_0);
            qtfisher[k] = calculate_qtfisher(*c1, *c2, *c3, absx, *qr_0);
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
