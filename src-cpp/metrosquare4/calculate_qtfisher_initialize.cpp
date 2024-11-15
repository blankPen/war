//
// File: calculate_qtfisher_initialize.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 15-Nov-2024 21:35:36
//

// Include Files
#include "calculate_qtfisher_initialize.h"
#include "calculate_qtfisher_data.h"
#include "eml_rand_mt19937ar_stateful.h"
#include "rt_nonfinite.h"

// Function Definitions
//
// Arguments    : void
// Return Type  : void
//
void calculate_qtfisher_initialize()
{
  eml_rand_mt19937ar_stateful_init();
  isInitialized_calculate_qtfisher = true;
}

//
// File trailer for calculate_qtfisher_initialize.cpp
//
// [EOF]
//
