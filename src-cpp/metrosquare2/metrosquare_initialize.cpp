//
// File: metrosquare_initialize.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Nov-2024 23:16:58
//

// Include Files
#include "metrosquare_initialize.h"
#include "eml_rand_mt19937ar_stateful.h"
#include "metrosquare_data.h"
#include "rt_nonfinite.h"

// Function Definitions
//
// Arguments    : void
// Return Type  : void
//
void metrosquare_initialize()
{
  eml_rand_mt19937ar_stateful_init();
  isInitialized_metrosquare = true;
}

//
// File trailer for metrosquare_initialize.cpp
//
// [EOF]
//
