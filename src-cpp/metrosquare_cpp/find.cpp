//
// File: find.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 03-Nov-2024 23:50:41
//

// Include Files
#include "find.h"

// Function Definitions
//
// Arguments    : const boolean_T x[64]
//                int i_data[]
//                int *i_size
//                int j_data[]
//                int *j_size
// Return Type  : void
//
namespace coder {
void eml_find(const boolean_T x[64], int i_data[], int *i_size, int j_data[],
              int *j_size)
{
  int idx;
  int ii;
  int jj;
  boolean_T exitg1;
  idx = 0;
  ii = 1;
  jj = 1;
  exitg1 = false;
  while ((!exitg1) && (jj <= 2)) {
    boolean_T guard1{false};
    guard1 = false;
    if (x[(ii + ((jj - 1) << 5)) - 1]) {
      idx++;
      i_data[idx - 1] = ii;
      j_data[idx - 1] = jj;
      if (idx >= 64) {
        exitg1 = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }
    if (guard1) {
      ii++;
      if (ii > 32) {
        ii = 1;
        jj++;
      }
    }
  }
  if (1 > idx) {
    *i_size = 0;
    *j_size = 0;
  } else {
    *i_size = idx;
    *j_size = idx;
  }
}

} // namespace coder

//
// File trailer for find.cpp
//
// [EOF]
//
