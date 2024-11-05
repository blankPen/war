//
// File: run_main.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 03-Nov-2024 23:50:41
//

// Include Files
#include "run_main.h"
#include "metrosquare.h"
#include "metrosquare_data.h"
#include "metrosquare_initialize.h"

// Function Definitions
//
// 一、数据导入（实现参数赋值）
//
// Arguments    : const double data[64]
//                double qb_0
//                double t_known
//                double *kr
//                double *kb
// Return Type  : void
//
void run_main(const double data[64], double qb_0, double t_known, double *kr,
              double *kb)
{
  if (!isInitialized_metrosquare) {
    metrosquare_initialize();
  }
  //   二、运算分析（模型的数值运算）
  metrosquare(data, qb_0, t_known, kr, kb);
  // 平方律模型参数计算
}

//
// File trailer for run_main.cpp
//
// [EOF]
//
