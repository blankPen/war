//
// File: _coder_calculate_qtfisher_api.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 15-Nov-2024 21:35:36
//

// Include Files
#include "_coder_calculate_qtfisher_api.h"
#include "_coder_calculate_qtfisher_mex.h"
#include "coder_array_mex.h"

// Variable Definitions
emlrtCTX emlrtRootTLSGlobal{nullptr};

emlrtContext emlrtContextGlobal{
    true,                                                 // bFirstTime
    false,                                                // bInitialized
    131611U,                                              // fVersionInfo
    nullptr,                                              // fErrorFunction
    "calculate_qtfisher",                                 // fFunctionName
    nullptr,                                              // fRTCallStack
    false,                                                // bDebugMode
    {2045744189U, 2170104910U, 2743257031U, 4284093946U}, // fSigWrd
    nullptr                                               // fSigMem
};

// Function Declarations
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<real_T, 1U> &ret);

static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *v,
                                   const char_T *identifier))[2];

static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[2];

static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<real_T, 2U> &ret);

static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *v,
                                   const char_T *identifier))[3];

static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[3];

static real_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId);

static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[2];

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *t,
                             const char_T *identifier,
                             coder::array<real_T, 1U> &y);

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             coder::array<real_T, 1U> &y);

static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *c1,
                               const char_T *identifier);

static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId);

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *data,
                             const char_T *identifier,
                             coder::array<real_T, 2U> &y);

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             coder::array<real_T, 2U> &y);

static const mxArray *emlrt_marshallOut(const coder::array<real_T, 1U> &u);

static const mxArray *emlrt_marshallOut(const real_T u);

static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[3];

// Function Definitions
//
// Arguments    : const emlrtStack *sp
//                const mxArray *src
//                const emlrtMsgIdentifier *msgId
//                coder::array<real_T, 1U> &ret
// Return Type  : void
//
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<real_T, 1U> &ret)
{
  static const int32_T dims{-1};
  int32_T i;
  const boolean_T b{true};
  emlrtCheckVsBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                            false, 1U, (void *)&dims, &b, &i);
  ret.prealloc(i);
  ret.set_size(i);
  ret.set((real_T *)emlrtMxGetData(src), ret.size(0));
  emlrtDestroyArray(&src);
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *v
//                const char_T *identifier
// Return Type  : real_T (*)[2]
//
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *v,
                                   const char_T *identifier))[2]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[2];
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(v), &thisId);
  emlrtDestroyArray(&v);
  return y;
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *u
//                const emlrtMsgIdentifier *parentId
// Return Type  : real_T (*)[2]
//
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[2]
{
  real_T(*y)[2];
  y = e_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *src
//                const emlrtMsgIdentifier *msgId
//                coder::array<real_T, 2U> &ret
// Return Type  : void
//
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<real_T, 2U> &ret)
{
  static const int32_T dims[2]{-1, 2};
  int32_T iv[2];
  const boolean_T bv[2]{true, false};
  emlrtCheckVsBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                            false, 2U, (void *)&dims[0], &bv[0], &iv[0]);
  ret.prealloc(iv[0] * iv[1]);
  ret.set_size(iv[0], iv[1]);
  ret.set((real_T *)emlrtMxGetData(src), ret.size(0), ret.size(1));
  emlrtDestroyArray(&src);
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *u
//                const emlrtMsgIdentifier *parentId
// Return Type  : real_T (*)[3]
//
static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[3]
{
  real_T(*y)[3];
  y = f_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *v
//                const char_T *identifier
// Return Type  : real_T (*)[3]
//
static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *v,
                                   const char_T *identifier))[3]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[3];
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  y = c_emlrt_marshallIn(sp, emlrtAlias(v), &thisId);
  emlrtDestroyArray(&v);
  return y;
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *src
//                const emlrtMsgIdentifier *msgId
// Return Type  : real_T
//
static real_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims{0};
  real_T ret;
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 0U, (void *)&dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *src
//                const emlrtMsgIdentifier *msgId
// Return Type  : real_T (*)[2]
//
static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[2]
{
  static const int32_T dims[2]{1, 2};
  real_T(*ret)[2];
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 2U, (void *)&dims[0]);
  ret = (real_T(*)[2])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *data
//                const char_T *identifier
//                coder::array<real_T, 2U> &y
// Return Type  : void
//
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *data,
                             const char_T *identifier,
                             coder::array<real_T, 2U> &y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  emlrt_marshallIn(sp, emlrtAlias(data), &thisId, y);
  emlrtDestroyArray(&data);
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *u
//                const emlrtMsgIdentifier *parentId
// Return Type  : real_T
//
static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = d_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *c1
//                const char_T *identifier
// Return Type  : real_T
//
static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *c1,
                               const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  real_T y;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  y = emlrt_marshallIn(sp, emlrtAlias(c1), &thisId);
  emlrtDestroyArray(&c1);
  return y;
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *t
//                const char_T *identifier
//                coder::array<real_T, 1U> &y
// Return Type  : void
//
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *t,
                             const char_T *identifier,
                             coder::array<real_T, 1U> &y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  emlrt_marshallIn(sp, emlrtAlias(t), &thisId, y);
  emlrtDestroyArray(&t);
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *u
//                const emlrtMsgIdentifier *parentId
//                coder::array<real_T, 1U> &y
// Return Type  : void
//
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             coder::array<real_T, 1U> &y)
{
  b_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *u
//                const emlrtMsgIdentifier *parentId
//                coder::array<real_T, 2U> &y
// Return Type  : void
//
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             coder::array<real_T, 2U> &y)
{
  b_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

//
// Arguments    : const real_T u
// Return Type  : const mxArray *
//
static const mxArray *emlrt_marshallOut(const real_T u)
{
  const mxArray *m;
  const mxArray *y;
  y = nullptr;
  m = emlrtCreateDoubleScalar(u);
  emlrtAssign(&y, m);
  return y;
}

//
// Arguments    : const coder::array<real_T, 1U> &u
// Return Type  : const mxArray *
//
static const mxArray *emlrt_marshallOut(const coder::array<real_T, 1U> &u)
{
  static const int32_T i{0};
  const mxArray *m;
  const mxArray *y;
  y = nullptr;
  m = emlrtCreateNumericArray(1, (const void *)&i, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, &(((coder::array<real_T, 1U> *)&u)->data())[0]);
  emlrtSetDimensions((mxArray *)m, ((coder::array<real_T, 1U> *)&u)->size(), 1);
  emlrtAssign(&y, m);
  return y;
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *src
//                const emlrtMsgIdentifier *msgId
// Return Type  : real_T (*)[3]
//
static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[3]
{
  static const int32_T dims[2]{1, 3};
  real_T(*ret)[3];
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 2U, (void *)&dims[0]);
  ret = (real_T(*)[3])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

//
// Arguments    : const mxArray * const prhs[5]
//                const mxArray **plhs
// Return Type  : void
//
void calculate_qtfisher_api(const mxArray *const prhs[5], const mxArray **plhs)
{
  coder::array<real_T, 1U> qtfisher;
  coder::array<real_T, 1U> t;
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  real_T c1;
  real_T c2;
  real_T c3;
  real_T qr_0;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  // Marshall function inputs
  c1 = emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "c1");
  c2 = emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "c2");
  c3 = emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "c3");
  t.no_free();
  emlrt_marshallIn(&st, emlrtAlias(prhs[3]), "t", t);
  qr_0 = emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "qr_0");
  // Invoke the target function
  calculate_qtfisher(c1, c2, c3, t, qr_0, qtfisher);
  // Marshall function outputs
  qtfisher.no_free();
  *plhs = emlrt_marshallOut(qtfisher);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

//
// Arguments    : void
// Return Type  : void
//
void calculate_qtfisher_atexit()
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  calculate_qtfisher_xil_terminate();
  calculate_qtfisher_xil_shutdown();
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

//
// Arguments    : void
// Return Type  : void
//
void calculate_qtfisher_initialize()
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, nullptr);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

//
// Arguments    : void
// Return Type  : void
//
void calculate_qtfisher_terminate()
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

//
// Arguments    : const mxArray * const prhs[5]
//                const mxArray **plhs
// Return Type  : void
//
void calculate_qtsquare_api(const mxArray *const prhs[5], const mxArray **plhs)
{
  coder::array<real_T, 1U> qtsquare;
  coder::array<real_T, 1U> t;
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  real_T kb;
  real_T kr;
  real_T qb_0;
  real_T qr_0;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  // Marshall function inputs
  kr = emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "kr");
  kb = emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "kb");
  t.no_free();
  emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "t", t);
  qr_0 = emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "qr_0");
  qb_0 = emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "qb_0");
  // Invoke the target function
  calculate_qtsquare(kr, kb, t, qr_0, qb_0, qtsquare);
  // Marshall function outputs
  qtsquare.no_free();
  *plhs = emlrt_marshallOut(qtsquare);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

//
// Arguments    : const mxArray * const prhs[3]
//                int32_T nlhs
//                const mxArray *plhs[2]
// Return Type  : void
//
void metrosquare_api(const mxArray *const prhs[3], int32_T nlhs,
                     const mxArray *plhs[2])
{
  coder::array<real_T, 2U> data;
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  real_T kb;
  real_T kr;
  real_T qb_0;
  real_T t_known;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  // Marshall function inputs
  data.no_free();
  emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "data", data);
  qb_0 = emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "qb_0");
  t_known = emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "t_known");
  // Invoke the target function
  metrosquare(data, qb_0, t_known, &kr, &kb);
  // Marshall function outputs
  plhs[0] = emlrt_marshallOut(kr);
  if (nlhs > 1) {
    plhs[1] = emlrt_marshallOut(kb);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

//
// Arguments    : const mxArray * const prhs[4]
//                const mxArray **plhs
// Return Type  : void
//
void my_error_square_api(const mxArray *const prhs[4], const mxArray **plhs)
{
  coder::array<real_T, 2U> data;
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  real_T(*v)[2];
  real_T qb_0;
  real_T t_known;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  // Marshall function inputs
  v = b_emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "v");
  data.no_free();
  emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "data", data);
  qb_0 = emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "qb_0");
  t_known = emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "t_known");
  // Invoke the target function
  qb_0 = my_error_square(*v, data, qb_0, t_known);
  // Marshall function outputs
  *plhs = emlrt_marshallOut(qb_0);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

//
// Arguments    : const mxArray * const prhs[2]
//                int32_T nlhs
//                const mxArray *plhs[3]
// Return Type  : void
//
void prediction_POS_api(const mxArray *const prhs[2], int32_T nlhs,
                        const mxArray *plhs[3])
{
  coder::array<real_T, 2U> data;
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  real_T c1;
  real_T c2;
  real_T c3;
  real_T t_known;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  // Marshall function inputs
  data.no_free();
  emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "data", data);
  t_known = emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "t_known");
  // Invoke the target function
  prediction_POS(data, t_known, &c1, &c2, &c3);
  // Marshall function outputs
  plhs[0] = emlrt_marshallOut(c1);
  if (nlhs > 1) {
    plhs[1] = emlrt_marshallOut(c2);
  }
  if (nlhs > 2) {
    plhs[2] = emlrt_marshallOut(c3);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

//
// Arguments    : const mxArray * const prhs[3]
//                const mxArray **plhs
// Return Type  : void
//
void prediction_my_error_api(const mxArray *const prhs[3], const mxArray **plhs)
{
  coder::array<real_T, 2U> data;
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  real_T(*v)[3];
  real_T t_known;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  // Marshall function inputs
  v = c_emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "v");
  data.no_free();
  emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "data", data);
  t_known = emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "t_known");
  // Invoke the target function
  t_known = prediction_my_error(*v, data, t_known);
  // Marshall function outputs
  *plhs = emlrt_marshallOut(t_known);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

//
// Arguments    : const mxArray * const prhs[6]
//                const mxArray **plhs
// Return Type  : void
//
void probability_PIMC_api(const mxArray *const prhs[6], const mxArray **plhs)
{
  coder::array<real_T, 2U> data;
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  real_T kb;
  real_T kr;
  real_T num_grid_points_r;
  real_T qb_0;
  real_T t_known;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  // Marshall function inputs
  kr = emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "kr");
  kb = emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "kb");
  data.no_free();
  emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "data", data);
  qb_0 = emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "qb_0");
  t_known = emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "t_known");
  num_grid_points_r =
      emlrt_marshallIn(&st, emlrtAliasP(prhs[5]), "num_grid_points_r");
  // Invoke the target function
  kr = probability_PIMC(kr, kb, data, qb_0, t_known, num_grid_points_r);
  // Marshall function outputs
  *plhs = emlrt_marshallOut(kr);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

//
// Arguments    : const mxArray * const prhs[3]
//                int32_T nlhs
//                const mxArray *plhs[11]
// Return Type  : void
//
void run_main_api(const mxArray *const prhs[3], int32_T nlhs,
                  const mxArray *plhs[11])
{
  coder::array<real_T, 2U> data;
  coder::array<real_T, 1U> qtfisher;
  coder::array<real_T, 1U> qtsquare;
  coder::array<real_T, 1U> t;
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  real_T c1;
  real_T c2;
  real_T c3;
  real_T error_code;
  real_T kb;
  real_T kr;
  real_T probability;
  real_T qb_0;
  real_T qr_0;
  real_T t_known;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  // Marshall function inputs
  data.no_free();
  emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "data", data);
  qb_0 = emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "qb_0");
  t_known = emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "t_known");
  // Invoke the target function
  run_main(data, qb_0, t_known, &kr, &kb, &c1, &c2, &c3, &probability, t, &qr_0,
           qtsquare, qtfisher, &error_code);
  // Marshall function outputs
  plhs[0] = emlrt_marshallOut(kr);
  if (nlhs > 1) {
    plhs[1] = emlrt_marshallOut(kb);
  }
  if (nlhs > 2) {
    plhs[2] = emlrt_marshallOut(c1);
  }
  if (nlhs > 3) {
    plhs[3] = emlrt_marshallOut(c2);
  }
  if (nlhs > 4) {
    plhs[4] = emlrt_marshallOut(c3);
  }
  if (nlhs > 5) {
    plhs[5] = emlrt_marshallOut(probability);
  }
  if (nlhs > 6) {
    t.no_free();
    plhs[6] = emlrt_marshallOut(t);
  }
  if (nlhs > 7) {
    plhs[7] = emlrt_marshallOut(qr_0);
  }
  if (nlhs > 8) {
    qtsquare.no_free();
    plhs[8] = emlrt_marshallOut(qtsquare);
  }
  if (nlhs > 9) {
    qtfisher.no_free();
    plhs[9] = emlrt_marshallOut(qtfisher);
  }
  if (nlhs > 10) {
    plhs[10] = emlrt_marshallOut(error_code);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

//
// File trailer for _coder_calculate_qtfisher_api.cpp
//
// [EOF]
//
