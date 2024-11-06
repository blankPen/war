//
// File: _coder_metrosquare_api.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Nov-2024 23:16:58
//

// Include Files
#include "_coder_metrosquare_api.h"
#include "_coder_metrosquare_mex.h"

// Variable Definitions
emlrtCTX emlrtRootTLSGlobal{nullptr};

emlrtContext emlrtContextGlobal{
    true,                                                 // bFirstTime
    false,                                                // bInitialized
    131611U,                                              // fVersionInfo
    nullptr,                                              // fErrorFunction
    "metrosquare",                                        // fFunctionName
    nullptr,                                              // fRTCallStack
    false,                                                // bDebugMode
    {2045744189U, 2170104910U, 2743257031U, 4284093946U}, // fSigWrd
    nullptr                                               // fSigMem
};

// Function Declarations
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *qb_0,
                                 const char_T *identifier);

static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId);

static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *v,
                                   const char_T *identifier))[2];

static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[2];

static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *v,
                                   const char_T *identifier))[3];

static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[3];

static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[64];

static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *data,
                                 const char_T *identifier))[64];

static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId))[64];

static const mxArray *emlrt_marshallOut(const real_T u_data[],
                                        const int32_T *u_size);

static const mxArray *emlrt_marshallOut(const real_T u);

static real_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId);

static real_T (*g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[2];

static real_T (*h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[3];

// Function Definitions
//
// Arguments    : const emlrtStack *sp
//                const mxArray *qb_0
//                const char_T *identifier
// Return Type  : real_T
//
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *qb_0,
                                 const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  real_T y;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(qb_0), &thisId);
  emlrtDestroyArray(&qb_0);
  return y;
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *u
//                const emlrtMsgIdentifier *parentId
// Return Type  : real_T
//
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = f_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *v
//                const char_T *identifier
// Return Type  : real_T (*)[2]
//
static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *v,
                                   const char_T *identifier))[2]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[2];
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  y = c_emlrt_marshallIn(sp, emlrtAlias(v), &thisId);
  emlrtDestroyArray(&v);
  return y;
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *u
//                const emlrtMsgIdentifier *parentId
// Return Type  : real_T (*)[2]
//
static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[2]
{
  real_T(*y)[2];
  y = g_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *v
//                const char_T *identifier
// Return Type  : real_T (*)[3]
//
static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *v,
                                   const char_T *identifier))[3]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[3];
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(sp, emlrtAlias(v), &thisId);
  emlrtDestroyArray(&v);
  return y;
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *u
//                const emlrtMsgIdentifier *parentId
// Return Type  : real_T (*)[3]
//
static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[3]
{
  real_T(*y)[3];
  y = h_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *src
//                const emlrtMsgIdentifier *msgId
// Return Type  : real_T (*)[64]
//
static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[64]
{
  static const int32_T dims[2]{32, 2};
  real_T(*ret)[64];
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 2U, (void *)&dims[0]);
  ret = (real_T(*)[64])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *data
//                const char_T *identifier
// Return Type  : real_T (*)[64]
//
static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *data,
                                 const char_T *identifier))[64]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[64];
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  y = emlrt_marshallIn(sp, emlrtAlias(data), &thisId);
  emlrtDestroyArray(&data);
  return y;
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *u
//                const emlrtMsgIdentifier *parentId
// Return Type  : real_T (*)[64]
//
static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId))[64]
{
  real_T(*y)[64];
  y = e_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

//
// Arguments    : const real_T u_data[]
//                const int32_T *u_size
// Return Type  : const mxArray *
//
static const mxArray *emlrt_marshallOut(const real_T u_data[],
                                        const int32_T *u_size)
{
  static const int32_T i{0};
  const mxArray *m;
  const mxArray *y;
  y = nullptr;
  m = emlrtCreateNumericArray(1, (const void *)&i, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)&u_data[0]);
  emlrtSetDimensions((mxArray *)m, u_size, 1);
  emlrtAssign(&y, m);
  return y;
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
// Arguments    : const emlrtStack *sp
//                const mxArray *src
//                const emlrtMsgIdentifier *msgId
// Return Type  : real_T
//
static real_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
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
static real_T (*g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
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
//                const mxArray *src
//                const emlrtMsgIdentifier *msgId
// Return Type  : real_T (*)[3]
//
static real_T (*h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
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
// Arguments    : const mxArray * const prhs[3]
//                int32_T nlhs
//                const mxArray *plhs[2]
// Return Type  : void
//
void metrosquare_api(const mxArray *const prhs[3], int32_T nlhs,
                     const mxArray *plhs[2])
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  real_T(*data)[64];
  real_T kb;
  real_T kr;
  real_T qb_0;
  real_T t_known;
  st.tls = emlrtRootTLSGlobal;
  // Marshall function inputs
  data = emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "data");
  qb_0 = b_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "qb_0");
  t_known = b_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "t_known");
  // Invoke the target function
  metrosquare(*data, qb_0, t_known, &kr, &kb);
  // Marshall function outputs
  plhs[0] = emlrt_marshallOut(kr);
  if (nlhs > 1) {
    plhs[1] = emlrt_marshallOut(kb);
  }
}

//
// Arguments    : void
// Return Type  : void
//
void metrosquare_atexit()
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
  metrosquare_xil_terminate();
  metrosquare_xil_shutdown();
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

//
// Arguments    : void
// Return Type  : void
//
void metrosquare_initialize()
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
void metrosquare_terminate()
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
// Arguments    : const mxArray * const prhs[4]
//                const mxArray **plhs
// Return Type  : void
//
void my_error_square_api(const mxArray *const prhs[4], const mxArray **plhs)
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  real_T(*data)[64];
  real_T(*v)[2];
  real_T qb_0;
  real_T t_known;
  st.tls = emlrtRootTLSGlobal;
  // Marshall function inputs
  v = c_emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "v");
  data = emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "data");
  qb_0 = b_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "qb_0");
  t_known = b_emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "t_known");
  // Invoke the target function
  qb_0 = my_error_square(*v, *data, qb_0, t_known);
  // Marshall function outputs
  *plhs = emlrt_marshallOut(qb_0);
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
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  real_T(*data)[64];
  real_T c1;
  real_T c2;
  real_T c3;
  real_T t_known;
  st.tls = emlrtRootTLSGlobal;
  // Marshall function inputs
  data = emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "data");
  t_known = b_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "t_known");
  // Invoke the target function
  prediction_POS(*data, t_known, &c1, &c2, &c3);
  // Marshall function outputs
  plhs[0] = emlrt_marshallOut(c1);
  if (nlhs > 1) {
    plhs[1] = emlrt_marshallOut(c2);
  }
  if (nlhs > 2) {
    plhs[2] = emlrt_marshallOut(c3);
  }
}

//
// Arguments    : const mxArray * const prhs[3]
//                const mxArray **plhs
// Return Type  : void
//
void prediction_my_error_api(const mxArray *const prhs[3], const mxArray **plhs)
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  real_T(*data)[64];
  real_T(*v)[3];
  real_T t_known;
  st.tls = emlrtRootTLSGlobal;
  // Marshall function inputs
  v = d_emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "v");
  data = emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "data");
  t_known = b_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "t_known");
  // Invoke the target function
  t_known = prediction_my_error(*v, *data, t_known);
  // Marshall function outputs
  *plhs = emlrt_marshallOut(t_known);
}

//
// Arguments    : const mxArray * const prhs[5]
//                const mxArray **plhs
// Return Type  : void
//
void probability_PIMC_api(const mxArray *const prhs[5], const mxArray **plhs)
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  real_T(*data)[64];
  real_T kb;
  real_T kr;
  real_T num_grid_points_r;
  real_T t_known;
  st.tls = emlrtRootTLSGlobal;
  // Marshall function inputs
  kr = b_emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "kr");
  kb = b_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "kb");
  data = emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "data");
  t_known = b_emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "t_known");
  num_grid_points_r =
      b_emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "num_grid_points_r");
  // Invoke the target function
  kr = probability_PIMC(kr, kb, *data, t_known, num_grid_points_r);
  // Marshall function outputs
  *plhs = emlrt_marshallOut(kr);
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
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  real_T(*data)[64];
  real_T(*qtfisher_data)[32];
  real_T(*qtsquare_data)[32];
  real_T(*t_data)[32];
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
  int32_T qtfisher_size;
  int32_T qtsquare_size;
  int32_T t_size;
  st.tls = emlrtRootTLSGlobal;
  t_data = (real_T(*)[32])mxMalloc(sizeof(real_T[32]));
  qtsquare_data = (real_T(*)[32])mxMalloc(sizeof(real_T[32]));
  qtfisher_data = (real_T(*)[32])mxMalloc(sizeof(real_T[32]));
  // Marshall function inputs
  data = emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "data");
  qb_0 = b_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "qb_0");
  t_known = b_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "t_known");
  // Invoke the target function
  run_main(*data, qb_0, t_known, &kr, &kb, &c1, &c2, &c3, &probability, *t_data,
           *(int32_T(*)[1]) & t_size, &qr_0, *qtsquare_data,
           *(int32_T(*)[1]) & qtsquare_size, *qtfisher_data,
           *(int32_T(*)[1]) & qtfisher_size, &error_code);
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
    plhs[6] = emlrt_marshallOut(*t_data, &t_size);
  }
  if (nlhs > 7) {
    plhs[7] = emlrt_marshallOut(qr_0);
  }
  if (nlhs > 8) {
    plhs[8] = emlrt_marshallOut(*qtsquare_data, &qtsquare_size);
  }
  if (nlhs > 9) {
    plhs[9] = emlrt_marshallOut(*qtfisher_data, &qtfisher_size);
  }
  if (nlhs > 10) {
    plhs[10] = emlrt_marshallOut(error_code);
  }
}

//
// File trailer for _coder_metrosquare_api.cpp
//
// [EOF]
//
