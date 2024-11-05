//
// File: rand.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 03-Nov-2024 23:50:41
//

// Include Files
#include "rand.h"
#include "eml_rand_mt19937ar.h"
#include "metrosquare_data.h"

// Function Definitions
//
// Arguments    : double r[2000]
// Return Type  : void
//
namespace coder {
void b_rand(double r[2000])
{
  for (int k{0}; k < 2000; k++) {
    r[k] = eml_rand_mt19937ar(state);
  }
}

//
// Arguments    : double r[2]
// Return Type  : void
//
void c_rand(double r[2])
{
  r[0] = eml_rand_mt19937ar(state);
  r[1] = eml_rand_mt19937ar(state);
}

} // namespace coder

//
// File trailer for rand.cpp
//
// [EOF]
//
