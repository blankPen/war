//
// File: metrosquare.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Nov-2024 23:16:58
//

// Include Files
#include "metrosquare.h"
#include "find.h"
#include "metrosquare_data.h"
#include "metrosquare_initialize.h"
#include "minOrMax.h"
#include "my_error_square.h"
#include "rand.h"
#include "rt_nonfinite.h"
#include <algorithm>
#include <cmath>
#include <iostream>

// Function Definitions
//
// %%%%%%%%%% 用粒子群算法拟合模型的参数Lr、C2、Nr 和 T %%%%%%%%%%%%%%%%%%%
//
// Arguments    : const double data[]
//                double qb_0
//                double t_known
//                double *kr
//                double *kb
// Return Type  : void
//
void metrosquare(const double data[], int size, double qb_0, double t_known, double *kr,
                 double *kb)
{
  double p_best_x[1000];
  double v[1000];
  double x[1000];
  double fit[500];
  double b[2];
  double b_x[2];
  double b_i;
  double delta;
  double g_best;
  double g_best_past1;
  double g_best_past2;
  double g_best_x_idx_0;
  double g_best_x_idx_1;
  double kb_max;
  double kr_max;
  double unit_t;
  int tmp_data[500];
  int tmp_size[2];
  int circle;
  int i;
  boolean_T b_fit[500];
  if (!isInitialized_metrosquare) {
    metrosquare_initialize();
  }
  delta = data[size/2] / qb_0;
  unit_t = data[1] - data[0];
  kr_max = qb_0 / unit_t * delta;
  kb_max = data[size/2] / unit_t * delta;
  //  个体学习参数
  //  种群学习参数
  //  粒子数
  circle = 10000;
  //  每个阶段循环的次数
  // 初始随机赋值
  coder::b_rand(x);
  //  前四列记录粒子当前的位置（c1,c2,c3），并为c1,c2,c3随机赋初值
  coder::b_rand(v);
  //  N个粒子的速度，每个速度有3个分量
  //  计算适应度函数
  //  每个粒子搜索过的最好的值
  for (i = 0; i < 500; i++) {
    b_x[0] = x[i] / delta;
    b_x[1] = x[i + 500] / delta;
    fit[i] = my_error_square(b_x, data, qb_0, t_known, size);
  }
  std::copy(&x[0], &x[1000], &p_best_x[0]);
  //  每个粒子搜索过的最好的位置
  unit_t = coder::internal::minimum(fit);
  for (i = 0; i < 500; i++) {
    b_fit[i] = (fit[i] == unit_t);
  }
  //  搜索所有粒子最好的位置
  coder::b_eml_find(b_fit, tmp_data, tmp_size);
  g_best_x_idx_0 = x[tmp_data[0] - 1];
  g_best_x_idx_1 = x[tmp_data[0] + 499];
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
      unit_t = fit[0];
      for (i = 0; i < 499; i++) {
        unit_t += fit[i + 1];
      }
      if (fit[j] <= unit_t / 500.0) {
        w_tmp = coder::internal::minimum(fit);
        unit_t = fit[0];
        for (i = 0; i < 499; i++) {
          unit_t += fit[i + 1];
        }
        unit_t =
            0.70000000000000007 * (fit[j] - w_tmp) / (unit_t / 500.0 - w_tmp) +
            0.4;
      } else {
        unit_t = 1.1;
      }
      coder::c_rand(b_x);
      coder::c_rand(b);
      d = x[j];
      v[j] = (unit_t * v[j] + b_x[0] * (p_best_x[j] - d)) +
             1.8 * b[0] * (g_best_x_idx_0 - d);
      d = x[j + 500];
      v[j + 500] = (unit_t * v[j + 500] + b_x[1] * (p_best_x[j + 500] - d)) +
                   1.8 * b[1] * (g_best_x_idx_1 - d);
    }
    for (i = 0; i < 1000; i++) {
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
      coder::b_rand(x);
      //  前四列记录粒子当前的位置（c1,c2,c3），并为c1,c2,c3随机赋初值
      for (i = 0; i < 1000; i++) {
        x[i] *= delta;
        v[i] = 0.0;
      }
      //  N个粒子的速度，每个速度有3个分量
      x[0] = g_best_x_idx_0;
      x[500] = g_best_x_idx_1;
      //  计算适应度函数
      //  每个粒子搜索过的最好的值
      for (j = 0; j < 500; j++) {
        b_x[0] = x[j] / delta;
        b_x[1] = x[j + 500] / delta;
        fit[j] = my_error_square(b_x, data, qb_0, t_known, size);
      }
      std::copy(&x[0], &x[1000], &p_best_x[0]);
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
      d = x[j];
      if (d > kr_max) {
        d = kr_max;
        x[j] = kr_max;
      } else if (d < 0.0) {
        d = 0.0;
        x[j] = 0.0;
      }
      unit_t = x[j + 500];
      if (unit_t > kb_max) {
        unit_t = kb_max;
        x[j + 500] = kb_max;
      } else if (unit_t < 0.0) {
        unit_t = 0.0;
        x[j + 500] = 0.0;
      }
      b_x[0] = d / delta;
      b_x[1] = unit_t / delta;
      w_tmp = my_error_square(b_x, data, qb_0, t_known, size);
      if (w_tmp < fit[j]) {
        p_best_x[j] = d;
        p_best_x[j + 500] = unit_t;
        fit[j] = w_tmp;
      }
      d = coder::internal::minimum(fit);
      if (d < g_best) {
        for (i = 0; i < 500; i++) {
          b_fit[i] = (fit[i] == d);
        }
        coder::b_eml_find(b_fit, tmp_data, tmp_size);
        g_best_x_idx_0 = p_best_x[tmp_data[0] - 1];
        g_best_x_idx_1 = p_best_x[tmp_data[0] + 499];
        g_best = fit[tmp_data[0] - 1];
      }
    }
  }
  
  std::cout << "=====================" << std::endl;
  std::cout << "p_best_x: " << p_best_x << std::endl;
  std::cout << "g_best_x_idx_0: " << g_best_x_idx_0 << std::endl;
  std::cout << "g_best_x_idx_1: " << g_best_x_idx_1 << std::endl;
  //  将周期性常数放到一个周期中
  *kr = g_best_x_idx_0 / delta;
  *kb = g_best_x_idx_1 / delta;
}

//
// File trailer for metrosquare.cpp
//
// [EOF]
//
