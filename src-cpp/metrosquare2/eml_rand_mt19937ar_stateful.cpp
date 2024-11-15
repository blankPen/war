//
// File: eml_rand_mt19937ar_stateful.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Nov-2024 23:16:58
//

// Include Files
#include "eml_rand_mt19937ar_stateful.h"
#include "metrosquare_data.h"
#include "rt_nonfinite.h"
#include <cstring>

// Function Definitions
//
// Arguments    : void
// Return Type  : void
//
void eml_rand_mt19937ar_stateful_init()
{
  unsigned int r;
  std::memset(&state[0], 0, 625U * sizeof(unsigned int));
  r = 5489U;
  state[0] = 5489U;
  for (int mti{0}; mti < 623; mti++) {
    r = ((r ^ r >> 30U) * 1812433253U + mti) + 1U;
    state[mti + 1] = r;
  }
  state[624] = 624U;
}

//
// File trailer for eml_rand_mt19937ar_stateful.cpp
//
// [EOF]
//
