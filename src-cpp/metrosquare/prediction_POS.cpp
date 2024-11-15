//
// File: prediction_POS.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Nov-2024 23:16:58
//

// Include Files
#include "prediction_POS.h"
#include "find.h"
#include "metrosquare_data.h"
#include "metrosquare_initialize.h"
#include "minOrMax.h"
#include "prediction_my_error.h"
#include "rand.h"
#include "rt_nonfinite.h"
#include <algorithm>
#include <cmath>

// Function Definitions
//
// %%%%%%%%%% 用粒子群算法拟合模型的参数Lr、C2、Nr 和 T %%%%%%%%%%%%%%%%%%%
//
// Arguments    : const double data[]
//                double t_known
//                double *c1
//                double *c2
//                double *c3
// Return Type  : void
//
void prediction_POS(const double data[], int size, double t_known, double *c1,
                    double *c2, double *c3)
{
  double p_best_x[1500];
  double v[1500];
  double x[1500];
  double fit[500];
  double b[3];
  double b_x[3];
  double b_i;
  double g_best;
  double g_best_past1;
  double g_best_past2;
  double minval;
  int tmp_data[500];
  int tmp_size[2];
  int circle;
  int i;
  boolean_T b_fit[500];
  if (!isInitialized_metrosquare) {
    metrosquare_initialize();
  }
  //  个体学习参数
  //  种群学习参数
  //  粒子数
  circle = 10000;
  //  每个阶段循环的次数
  // 初始随机赋值
  coder::d_rand(x);
  for (i = 0; i < 1500; i++) {
    x[i] *= 100.0;
  }
  //  前四列记录粒子当前的位置（c1,c2,c3），并为c1,c2,c3随机赋初值
  coder::d_rand(v);
  for (i = 0; i < 1500; i++) {
    v[i] *= 100.0;
  }
  //  N个粒子的速度，每个速度有3个分量
  //  计算适应度函数
  //  每个粒子搜索过的最好的值
  for (i = 0; i < 500; i++) {
    b_x[0] = x[i];
    b_x[1] = x[i + 500];
    b_x[2] = x[i + 1000];
    fit[i] = prediction_my_error(b_x, data, t_known, size);
  }
  std::copy(&x[0], &x[1500], &p_best_x[0]);
  //  每个粒子搜索过的最好的位置
  minval = coder::internal::minimum(fit);
  for (i = 0; i < 500; i++) {
    b_fit[i] = (fit[i] == minval);
  }
  //  搜索所有粒子最好的位置
  coder::b_eml_find(b_fit, tmp_data, tmp_size);
  *c1 = x[tmp_data[0] - 1];
  *c2 = x[tmp_data[0] + 499];
  *c3 = x[tmp_data[0] + 999];
  //  所有粒子最好的位置
  g_best = fit[tmp_data[0] - 1];
  //  所有粒子最好的位置对应的适应度函数
  g_best_past1 = 0.0;
  g_best_past2 = 100.0;
  //     %% 权重
  //     %% 收缩因子
  //     %% 循环
  b_i = 0.0;
  while (std::abs(g_best_past1 - g_best_past2) > 1.0) {
    double d;
    double w_tmp;
    int j;
    //  && g_best > 0
    //  while i < circle
    b_i++;
    //  更新粒子速度
    for (j = 0; j < 500; j++) {
      //  自适应权重
      minval = fit[0];
      for (i = 0; i < 499; i++) {
        minval += fit[i + 1];
      }
      if (fit[j] <= minval / 500.0) {
        w_tmp = coder::internal::minimum(fit);
        minval = fit[0];
        for (i = 0; i < 499; i++) {
          minval += fit[i + 1];
        }
        minval =
            0.70000000000000007 * (fit[j] - w_tmp) / (minval / 500.0 - w_tmp) +
            0.4;
      } else {
        minval = 1.1;
      }
      coder::e_rand(b_x);
      coder::e_rand(b);
      d = x[j];
      v[j] =
          (minval * v[j] + b_x[0] * (p_best_x[j] - d)) + 1.8 * b[0] * (*c1 - d);
      d = x[j + 500];
      v[j + 500] = (minval * v[j + 500] + b_x[1] * (p_best_x[j + 500] - d)) +
                   1.8 * b[1] * (*c2 - d);
      d = x[j + 1000];
      v[j + 1000] = (minval * v[j + 1000] + b_x[2] * (p_best_x[j + 1000] - d)) +
                    1.8 * b[2] * (*c3 - d);
    }
    for (i = 0; i < 1500; i++) {
      x[i] += v[i];
    }
    //  更新粒子位置
    // %%%
    // 为了避免粒子群算法陷入局部最优解，每间隔一段时间就将其中不好的解舍掉，重新赋值
    if (std::isinf(b_i)) {
      d = rtNaN;
    } else {
      d = std::fmod(b_i, static_cast<double>(circle));
    }
    if (d == 0.0) {
      circle = 500;
      // 初始随机赋值
      coder::d_rand(x);
      //  前四列记录粒子当前的位置（c1,c2,c3），并为c1,c2,c3随机赋初值
      for (i = 0; i < 1500; i++) {
        x[i] *= 100.0;
        v[i] = 0.0;
      }
      //  N个粒子的速度，每个速度有3个分量
      x[0] = *c1;
      x[500] = *c2;
      x[1000] = *c3;
      //  计算适应度函数
      //  每个粒子搜索过的最好的值
      for (j = 0; j < 500; j++) {
        b_x[0] = x[j];
        b_x[1] = x[j + 500];
        b_x[2] = x[j + 1000];
        fit[j] = prediction_my_error(b_x, data, t_known, size);
      }
      std::copy(&x[0], &x[1500], &p_best_x[0]);
      //  每个粒子搜索过的最好的位置
      if (std::isinf(b_i)) {
        d = rtNaN;
      } else {
        d = std::fmod(b_i, 1000.0);
      }
      if (d == 0.0) {
        g_best_past2 = g_best_past1;
        g_best_past1 = g_best;
        //  迭代次数
        //  精度
      }
    }
    //  计算适应度函数,并更新每个粒子自身的最优位置
    for (j = 0; j < 500; j++) {
      double d1;
      d = x[j + 1000];
      if (d > 50.0) {
        d = 50.0;
        x[j + 1000] = 50.0;
      } else if (d < -50.0) {
        d = -50.0;
        x[j + 1000] = -50.0;
      }
      minval = x[j];
      b_x[0] = minval;
      w_tmp = x[j + 500];
      b_x[1] = w_tmp;
      b_x[2] = d;
      d1 = prediction_my_error(b_x, data, t_known, size);
      if (d1 < fit[j]) {
        p_best_x[j] = minval;
        p_best_x[j + 500] = w_tmp;
        p_best_x[j + 1000] = d;
        fit[j] = d1;
      }
      d = coder::internal::minimum(fit);
      if (d < g_best) {
        for (i = 0; i < 500; i++) {
          b_fit[i] = (fit[i] == d);
        }
        coder::b_eml_find(b_fit, tmp_data, tmp_size);
        *c1 = p_best_x[tmp_data[0] - 1];
        *c2 = p_best_x[tmp_data[0] + 499];
        *c3 = p_best_x[tmp_data[0] + 999];
        g_best = fit[tmp_data[0] - 1];
      }
    }
  }
  //  将周期性常数放到一个周期中
  while (std::abs(*c3) > 3.1415926535897931) {
    if (*c3 > 0.0) {
      *c3 -= 6.2831853071795862;
    } else if (*c3 < 0.0) {
      *c3 += 6.2831853071795862;
    }
  }
  //      fprintf('本项目模型最小二范数')
  //      g_best_x_show;
  //      fprintf('本项目模型参数值')
  //      g_best;
}

//
// File trailer for prediction_POS.cpp
//
// [EOF]
//
