//
// File: run_main.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 12-Nov-2024 22:50:14
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
#include "coder_array.h"
#include <cmath>
#include <math.h>

// Function Declarations
static void binary_expand_op(coder::array<double, 1U> &qtsquare, double qr_0,
                             double a, const coder::array<double, 1U> &y);

static void binary_expand_op(coder::array<double, 1U> &qtfisher,
                             const coder::array<double, 2U> &data, double c1,
                             double c2, double x);

// Function Definitions
//
// Arguments    : coder::array<double, 1U> &qtsquare
//                double qr_0
//                double a
//                const coder::array<double, 1U> &y
// Return Type  : void
//
static void binary_expand_op(coder::array<double, 1U> &qtsquare, double qr_0,
                             double a, const coder::array<double, 1U> &y)
{
  coder::array<double, 1U> b_qr_0;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  if (y.size(0) == 1) {
    i = qtsquare.size(0);
  } else {
    i = y.size(0);
  }
  b_qr_0.set_size(i);
  stride_0_0 = (qtsquare.size(0) != 1);
  stride_1_0 = (y.size(0) != 1);
  if (y.size(0) == 1) {
    loop_ub = qtsquare.size(0);
  } else {
    loop_ub = y.size(0);
  }
  for (i = 0; i < loop_ub; i++) {
    b_qr_0[i] = qr_0 * qtsquare[i * stride_0_0] - a * y[i * stride_1_0];
  }
  qtsquare.set_size(b_qr_0.size(0));
  loop_ub = b_qr_0.size(0);
  for (i = 0; i < loop_ub; i++) {
    qtsquare[i] = b_qr_0[i];
  }
}

//
// Arguments    : coder::array<double, 1U> &qtfisher
//                const coder::array<double, 2U> &data
//                double c1
//                double c2
//                double x
// Return Type  : void
//
static void binary_expand_op(coder::array<double, 1U> &qtfisher,
                             const coder::array<double, 2U> &data, double c1,
                             double c2, double x)
{
  coder::array<double, 1U> c_data;
  double b_c2;
  double b_data;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  b_data = data[data.size(0)];
  b_c2 = c2 * x;
  i = data.size(0);
  if (qtfisher.size(0) == 1) {
    stride_0_0 = i;
  } else {
    stride_0_0 = qtfisher.size(0);
  }
  c_data.set_size(stride_0_0);
  stride_0_0 = (i != 1);
  stride_1_0 = (qtfisher.size(0) != 1);
  if (qtfisher.size(0) == 1) {
    loop_ub = i;
  } else {
    loop_ub = qtfisher.size(0);
  }
  for (i = 0; i < loop_ub; i++) {
    c_data[i] =
        ((b_data - c1 * data[i * stride_0_0]) - c2 * qtfisher[i * stride_1_0]) +
        b_c2;
  }
  qtfisher.set_size(c_data.size(0));
  loop_ub = c_data.size(0);
  for (i = 0; i < loop_ub; i++) {
    qtfisher[i] = c_data[i];
  }
}

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
  coder::array<double, 1U> y;
  creal_T dc;
  double b_data[2];
  int nx;
  if (!isInitialized_metrosquare) {
    metrosquare_initialize();
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
    //  '输入错误：兵力数应为非负数'
    // quit
  } else {
    b_data[0] = data[0];
    b_data[1] = data[data.size(0)];
    if (coder::internal::b_minimum(b_data) < 0.0) {
      *error_code = 2.0;
      // '输入错误：时间应为非负数'
      // quit
    } else {
      b_data[0] = data[1];
      b_data[1] = data[data.size(0) + 1];
      if (coder::internal::b_minimum(b_data) < 0.0) {
        *error_code = 3.0;
        // '输入错误：兵力数应为非负数'
        // quit
      } else {
        double absx;
        double b;
        int k;
        boolean_T exitg1;
        boolean_T tf;
        tf = false;
        k = 0;
        exitg1 = false;
        while ((!exitg1) && (k <= data.size(0) - 1)) {
          b = data[k];
          absx = std::abs(b / 2.0);
          if ((!std::isinf(absx)) && (!std::isnan(absx))) {
            if (absx <= 2.2250738585072014E-308) {
              absx = 4.94065645841247E-324;
            } else {
              frexp(absx, &nx);
              absx = std::ldexp(1.0, nx - 53);
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
              probability_PIMC(*kr, *kb, data, t_known,
                               std::round(data[data.size(0)] / 100.0) * 20.0);
          // 路径积分概率计算
          nx = data.size(0);
          t.set_size(data.size(0));
          for (k = 0; k < nx; k++) {
            t[k] = data[k];
          }
          *qr_0 = data[data.size(0)];
          absx = *kr * *kb;
          dc.re = absx;
          dc.im = 0.0;
          coder::b_sqrt(&dc);
          nx = data.size(0);
          qtsquare.set_size(data.size(0));
          for (k = 0; k < nx; k++) {
            qtsquare[k] = dc.re * data[k];
          }
          nx = qtsquare.size(0);
          for (k = 0; k < nx; k++) {
            qtsquare[k] = std::cosh(qtsquare[k]);
          }
          dc.re = absx;
          dc.im = 0.0;
          coder::b_sqrt(&dc);
          nx = data.size(0);
          y.set_size(data.size(0));
          for (k = 0; k < nx; k++) {
            y[k] = dc.re * data[k];
          }
          absx = std::sqrt(*kb / *kr) * qb_0;
          nx = y.size(0);
          for (k = 0; k < nx; k++) {
            y[k] = std::sinh(y[k]);
          }
          if (qtsquare.size(0) == y.size(0)) {
            nx = qtsquare.size(0);
            for (k = 0; k < nx; k++) {
              qtsquare[k] = *qr_0 * qtsquare[k] - absx * y[k];
            }
          } else {
            binary_expand_op(qtsquare, *qr_0, absx, y);
          }
          nx = qtsquare.size(0);
          for (k = 0; k < nx; k++) {
            qtsquare[k] = std::round(qtsquare[k]);
          }
          absx = *c1 / *c2;
          nx = data.size(0);
          qtfisher.set_size(data.size(0));
          for (k = 0; k < nx; k++) {
            qtfisher[k] = absx * data[k] + *c3;
          }
          nx = qtfisher.size(0);
          for (k = 0; k < nx; k++) {
            qtfisher[k] = std::sin(qtfisher[k]);
          }
          absx = std::sin(*c3);
          if (data.size(0) == qtfisher.size(0)) {
            b = data[data.size(0)];
            absx *= *c2;
            nx = data.size(0);
            qtfisher.set_size(data.size(0));
            for (k = 0; k < nx; k++) {
              qtfisher[k] = ((b - *c1 * data[k]) - *c2 * qtfisher[k]) + absx;
            }
          } else {
            binary_expand_op(qtfisher, data, *c1, *c2, absx);
          }
          nx = qtfisher.size(0);
          for (k = 0; k < nx; k++) {
            qtfisher[k] = std::round(qtfisher[k]);
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
