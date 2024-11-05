//
// File: rand.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 04-Nov-2024 13:13:25
//

// Include Files
#include "rand.h"
#include "eml_rand_mt19937ar.h"
#include "metrosquare_data.h"
#include "rt_nonfinite.h"

// Function Definitions
//
// Arguments    : double r[1000]
// Return Type  : void
//
namespace coder {
void b_rand(double r[1000])
{
  for (int k{0}; k < 1000; k++) {
    r[k] = eml_rand_mt19937ar(state);
  }
}

//
// Arguments    : double r[1500]
// Return Type  : void
//
void c_rand(double r[1500])
{
  for (int k{0}; k < 1500; k++) {
    r[k] = eml_rand_mt19937ar(state);
  }
}

} // namespace coder

//
// File trailer for rand.cpp
//
// [EOF]
//
