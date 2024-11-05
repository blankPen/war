//
// File: metrosquare.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 03-Nov-2024 23:50:41
//

// Include Files
#include "metrosquare.h"
#include "metrosquare_data.h"
#include "metrosquare_initialize.h"
#include "my_error_square.h"
#include "rand.h"
#include <algorithm>
#include <cmath>

// Function Definitions
//
// %%%%%%%%%% 用粒子群算法拟合模型的参数Lr、C2、Nr 和 T %%%%%%%%%%%%%%%%%%%
//
// Arguments    : const double data[64]
//                double qb_0
//                double t_known
//                double *kr
//                double *kb
// Return Type  : void
//
void metrosquare(const double data[64], double qb_0, double t_known, double *kr,
                 double *kb)
{
  double g_data[2000];
  double p[2000];
  double v[2000];
  double x[2000];
  double x_data[2000];
  double fit[1000];
  double b[2];
  double b_x[2];
  double d;
  double ex;
  int g_size[2];
  int i;
  int i1;
  int idx;
  int k;
  int nx;
  short ii_data[1000];
  boolean_T exitg1;
  if (!isInitialized_metrosquare) {
    metrosquare_initialize();
  }
  // 初始随机赋值
  coder::b_rand(x);
  //  20个粒子当前的位置
  coder::b_rand(v);
  //  20个粒子的速度
  std::copy(&x[0], &x[2000], &p[0]);
  //  20个粒子自身最好的位置
  // 适应度函数
  for (nx = 0; nx < 1000; nx++) {
    b_x[0] = x[nx];
    b_x[1] = x[nx + 1000];
    fit[nx] = my_error_square(b_x, data, qb_0, t_known);
  }
  if (!std::isnan(fit[0])) {
    idx = 1;
  } else {
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 1001)) {
      if (!std::isnan(fit[k - 1])) {
        idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  if (idx == 0) {
    ex = fit[0];
  } else {
    ex = fit[idx - 1];
    i = idx + 1;
    for (k = i; k < 1001; k++) {
      d = fit[k - 1];
      if (ex > d) {
        ex = d;
      }
    }
  }
  idx = 0;
  nx = 0;
  exitg1 = false;
  while ((!exitg1) && (nx < 1000)) {
    if (fit[nx] == ex) {
      idx++;
      ii_data[idx - 1] = static_cast<short>(nx + 1);
      if (idx >= 1000) {
        exitg1 = true;
      } else {
        nx++;
      }
    } else {
      nx++;
    }
  }
  if (1 > idx) {
    nx = 0;
  } else {
    nx = idx;
  }
  g_size[0] = nx;
  g_size[1] = 2;
  for (i = 0; i < 2; i++) {
    for (i1 = 0; i1 < nx; i1++) {
      g_data[i1 + nx * i] = x[(ii_data[i1] + 1000 * i) - 1];
    }
  }
  //  所有粒子最好的位置
  // 记录最小适应度的变化
  //  线性权重
  //  收缩因子
  //  循环
  for (nx = 0; nx < 500; nx++) {
    int j;
    //  更新粒子的速度
    ex = 0.70000000000000007 * (500.0 - (static_cast<double>(nx) + 1.0)) /
             500.0 +
         0.4;
    idx = g_size[0];
    k = g_size[0];
    for (j = 0; j < 1000; j++) {
      coder::c_rand(b);
      coder::c_rand(b_x);
      for (i = 0; i < 2; i++) {
        for (i1 = 0; i1 < idx; i1++) {
          int i2;
          i2 = j + 1000 * i;
          d = x[i2];
          x_data[i1 + k * i] =
              1.0000000000000002 *
              ((ex * v[i2] + 1.2 * b[i] * (p[i2] - d)) +
               1.8 * b_x[i] * (g_data[i1 + g_size[0] * i] - d));
        }
      }
      v[j] = x_data[0];
      v[j + 1000] = x_data[1];
    }
    //  更新位置
    for (i = 0; i < 2000; i++) {
      x[i] += v[i];
    }
    for (j = 0; j < 1000; j++) {
      //  更新每个粒子自身的最优位置
      d = x[j];
      b_x[0] = d;
      b[0] = p[j];
      ex = x[j + 1000];
      b_x[1] = ex;
      b[1] = p[j + 1000];
      if (my_error_square(b_x, data, qb_0, t_known) <
          my_error_square(b, data, qb_0, t_known)) {
        //  更新种群的最优位置(放到里面的循环里减少计算量)
        p[j] = d;
        b_x[0] = d;
        p[j + 1000] = ex;
        b_x[1] = ex;
        if (my_error_square(b_x, data, qb_0, t_known) <
            b_my_error_square(g_data, g_size, data, qb_0, t_known)) {
          g_size[0] = 1;
          g_size[1] = 2;
          g_data[0] = d;
          g_data[1] = ex;
        }
      }
    }
    //  记录种群的最优位置
  }
  idx = g_size[0] * 2;
  if (0 <= idx - 1) {
    std::copy(&g_data[0], &g_data[idx], &x_data[0]);
  }
  nx = g_size[0] << 1;
  for (k = 0; k < nx; k++) {
    g_data[k] = std::abs(x_data[k]);
  }
  *kr = g_data[0];
  *kb = g_data[g_size[0]];
}

//
// File trailer for metrosquare.cpp
//
// [EOF]
//
