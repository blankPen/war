//
// File: find.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 15-Nov-2024 21:35:36
//

// Include Files
#include "find.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : const ::coder::array<boolean_T, 2U> &x
//                ::coder::array<int, 1U> &i
//                ::coder::array<int, 1U> &j
// Return Type  : void
//
namespace coder {
void eml_find(const ::coder::array<boolean_T, 2U> &x,
              ::coder::array<int, 1U> &i, ::coder::array<int, 1U> &j)
{
  int nx;
  nx = x.size(0) << 1;
  if (nx == 0) {
    i.set_size(0);
    j.set_size(0);
  } else {
    int idx;
    int ii;
    int jj;
    boolean_T exitg1;
    idx = 0;
    i.set_size(nx);
    j.set_size(nx);
    ii = 1;
    jj = 1;
    exitg1 = false;
    while ((!exitg1) && (jj <= 2)) {
      boolean_T guard1{false};
      guard1 = false;
      if (x[(ii + x.size(0) * (jj - 1)) - 1]) {
        idx++;
        i[idx - 1] = ii;
        j[idx - 1] = jj;
        if (idx >= nx) {
          exitg1 = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }
      if (guard1) {
        ii++;
        if (ii > x.size(0)) {
          ii = 1;
          jj++;
        }
      }
    }
    if (nx == 1) {
      if (idx == 0) {
        i.set_size(0);
        j.set_size(0);
      }
    } else {
      if (1 > idx) {
        nx = 0;
      } else {
        nx = idx;
      }
      i.set_size(nx);
      if (1 > idx) {
        idx = 0;
      }
      j.set_size(idx);
    }
  }
}

} // namespace coder

//
// File trailer for find.cpp
//
// [EOF]
//
