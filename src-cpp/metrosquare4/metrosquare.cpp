//
// File: metrosquare.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 15-Nov-2024 21:35:36
//

// Include Files
#include "metrosquare.h"
#include "calculate_qtfisher_data.h"
#include "calculate_qtfisher_initialize.h"
#include "my_error_square.h"
#include "rand.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
//
// %%%%%%%%%% 用粒子群算法拟合模型的参数Lr、C2、Nr 和 T %%%%%%%%%%%%%%%%%%%
//
// Arguments    : const coder::array<double, 2U> &data
//                double qb_0
//                double t_known
//                const double *kr
//                const double *kb
// Return Type  : void
//
void metrosquare(const coder::array<double, 2U> &data, double qb_0,
                 double t_known, const double *, const double *)
{
  double unusedExpr[1000];
  double x[1000];
  double b_x[2];
  double delta;
  if (!isInitialized_calculate_qtfisher) {
    calculate_qtfisher_initialize();
  }
  delta = std::fmax(data[data.size(0)] / qb_0, qb_0 / data[data.size(0)]);
  //  个体学习参数
  //  种群学习参数
  //  粒子数
  //  每个阶段循环的次数
  // 初始随机赋值
  coder::b_rand(x);
  //  前四列记录粒子当前的位置（c1,c2,c3），并为c1,c2,c3随机赋初值
  coder::b_rand(unusedExpr);
  //  N个粒子的速度，每个速度有3个分量
  //  计算适应度函数
  //  每个粒子搜索过的最好的值
  for (int i{0}; i < 500; i++) {
    b_x[0] = x[i] / delta;
    b_x[1] = x[i + 500] / delta;
    my_error_square(b_x, data, qb_0, t_known);
  }
  //  每个粒子搜索过的最好的位置
  //  搜索所有粒子最好的位置
  //  所有粒子最好的位置
  //  所有粒子最好的位置对应的适应度函数
  //     %% 权重
  //     %% 收缩因子
}

//
// File trailer for metrosquare.cpp
//
// [EOF]
//
