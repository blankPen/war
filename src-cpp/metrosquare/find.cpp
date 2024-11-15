//
// File: find.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Nov-2024 23:16:58
//

// Include Files
#include "find.h"
#include "rt_nonfinite.h"

// Function Definitions
//
// Arguments    : const boolean_T x[500]
//                int i_data[]
//                int i_size[2]
// Return Type  : void
//
namespace coder {
void b_eml_find(const boolean_T x[500], int i_data[], int i_size[2])
{
  int idx;
  int ii;
  boolean_T exitg1;
  idx = 0;
  i_size[0] = 1;
  ii = 0;
  exitg1 = false;
  while ((!exitg1) && (ii < 500)) {
    if (x[ii]) {
      idx++;
      i_data[idx - 1] = ii + 1;
      if (idx >= 500) {
        exitg1 = true;
      } else {
        ii++;
      }
    } else {
      ii++;
    }
  }
  if (1 > idx) {
    i_size[1] = 0;
  } else {
    i_size[1] = idx;
  }
}

//
// Arguments    : const boolean_T x[]
//                int i_data[]
//                int *i_size
//                int j_data[]
//                int *j_size
// Return Type  : void
//
void eml_find(const boolean_T x[], int x_size, int i_data[], int *i_size, int j_data[],
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
      if (idx >= x_size) {
        exitg1 = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }
    if (guard1) {
      ii++;
      if (ii > x_size / 2) {
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
