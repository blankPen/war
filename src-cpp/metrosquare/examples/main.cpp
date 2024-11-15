//
// File: main.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 15-Nov-2024 22:44:42
//

/*************************************************************************/
/* This automatically generated example C++ main file shows how to call  */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/

// Include Files
#include "main.h"
#include "calculate_qtfisher.h"
#include "calculate_qtfisher_terminate.h"
#include "calculate_qtsquare.h"
#include "metrosquare.h"
#include "my_error_square.h"
#include "prediction_POS.h"
#include "prediction_my_error.h"
#include "probability_PIMC.h"
#include "rt_nonfinite.h"
#include "run_main.h"
#include "coder_array.h"

// Function Declarations
static void argInit_1x2_real_T(double result[2]);

static void argInit_1x3_real_T(double result[3]);

static coder::array<double, 2U> argInit_Unboundedx2_real_T();

static double argInit_real_T();

static void main_calculate_qtfisher();

static void main_calculate_qtsquare();

static void main_metrosquare();

static void main_my_error_square();

static void main_prediction_POS();

static void main_prediction_my_error();

static void main_probability_PIMC();

static void main_run_main();

// Function Definitions
//
// Arguments    : double result[2]
// Return Type  : void
//
static void argInit_1x2_real_T(double result[2])
{
  // Loop over the array to initialize each element.
  for (int idx1{0}; idx1 < 2; idx1++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[idx1] = argInit_real_T();
  }
}

//
// Arguments    : double result[3]
// Return Type  : void
//
static void argInit_1x3_real_T(double result[3])
{
  // Loop over the array to initialize each element.
  for (int idx1{0}; idx1 < 3; idx1++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[idx1] = argInit_real_T();
  }
}

//
// Arguments    : void
// Return Type  : coder::array<double, 2U>
//
static coder::array<double, 2U> argInit_Unboundedx2_real_T()
{
  coder::array<double, 2U> result;
  // Set the size of the array.
  // Change this size to the value that the application requires.
  result.set_size(2, 2);
  // Loop over the array to initialize each element.
  for (int idx0{0}; idx0 < result.size(0); idx0++) {
    for (int idx1{0}; idx1 < 2; idx1++) {
      // Set the value of the array element.
      // Change this value to the value that the application requires.
      result[idx0 + result.size(0) * idx1] = argInit_real_T();
    }
  }
  return result;
}

//
// Arguments    : void
// Return Type  : double
//
static double argInit_real_T()
{
  return 0.0;
}

//
// Arguments    : void
// Return Type  : void
//
static void main_calculate_qtfisher()
{
  double c1_tmp;
  // Initialize function 'calculate_qtfisher' input arguments.
  c1_tmp = argInit_real_T();
  // Call the entry-point 'calculate_qtfisher'.
  c1_tmp = calculate_qtfisher(c1_tmp, c1_tmp, c1_tmp, c1_tmp, c1_tmp);
}

//
// Arguments    : void
// Return Type  : void
//
static void main_calculate_qtsquare()
{
  double kr_tmp;
  // Initialize function 'calculate_qtsquare' input arguments.
  kr_tmp = argInit_real_T();
  // Call the entry-point 'calculate_qtsquare'.
  kr_tmp = calculate_qtsquare(kr_tmp, kr_tmp, kr_tmp, kr_tmp, kr_tmp);
}

//
// Arguments    : void
// Return Type  : void
//
static void main_metrosquare()
{
  coder::array<double, 2U> data;
  double kr;
  double qb_0_tmp;
  // Initialize function 'metrosquare' input arguments.
  // Initialize function input argument 'data'.
  data = argInit_Unboundedx2_real_T();
  qb_0_tmp = argInit_real_T();
  // Call the entry-point 'metrosquare'.
  metrosquare(data, qb_0_tmp, qb_0_tmp, &kr, &kr);
}

//
// Arguments    : void
// Return Type  : void
//
static void main_my_error_square()
{
  coder::array<double, 2U> data;
  double dv[2];
  double qb_0_tmp;
  // Initialize function 'my_error_square' input arguments.
  // Initialize function input argument 'v'.
  // Initialize function input argument 'data'.
  data = argInit_Unboundedx2_real_T();
  qb_0_tmp = argInit_real_T();
  // Call the entry-point 'my_error_square'.
  argInit_1x2_real_T(dv);
  qb_0_tmp = my_error_square(dv, data, qb_0_tmp, qb_0_tmp);
}

//
// Arguments    : void
// Return Type  : void
//
static void main_prediction_POS()
{
  coder::array<double, 2U> data;
  double c1;
  // Initialize function 'prediction_POS' input arguments.
  // Initialize function input argument 'data'.
  data = argInit_Unboundedx2_real_T();
  // Call the entry-point 'prediction_POS'.
  prediction_POS(data, argInit_real_T(), &c1, &c1, &c1);
}

//
// Arguments    : void
// Return Type  : void
//
static void main_prediction_my_error()
{
  coder::array<double, 2U> data;
  double dv[3];
  double u;
  // Initialize function 'prediction_my_error' input arguments.
  // Initialize function input argument 'v'.
  // Initialize function input argument 'data'.
  data = argInit_Unboundedx2_real_T();
  // Call the entry-point 'prediction_my_error'.
  argInit_1x3_real_T(dv);
  u = prediction_my_error(dv, data, argInit_real_T());
}

//
// Arguments    : void
// Return Type  : void
//
static void main_probability_PIMC()
{
  coder::array<double, 2U> data;
  double kr_tmp;
  // Initialize function 'probability_PIMC' input arguments.
  kr_tmp = argInit_real_T();
  // Initialize function input argument 'data'.
  data = argInit_Unboundedx2_real_T();
  // Call the entry-point 'probability_PIMC'.
  kr_tmp = probability_PIMC(kr_tmp, kr_tmp, data, kr_tmp, kr_tmp, kr_tmp);
}

//
// Arguments    : void
// Return Type  : void
//
static void main_run_main()
{
  coder::array<double, 2U> data;
  coder::array<double, 1U> qtfisher;
  coder::array<double, 1U> qtsquare;
  coder::array<double, 1U> t;
  double c1;
  double c2;
  double c3;
  double error_code;
  double kb;
  double kr;
  double probability;
  double qb_0_tmp;
  double qr_0;
  // Initialize function 'run_main' input arguments.
  // Initialize function input argument 'data'.
  data = argInit_Unboundedx2_real_T();
  qb_0_tmp = argInit_real_T();
  // Call the entry-point 'run_main'.
  run_main(data, qb_0_tmp, qb_0_tmp, &kr, &kb, &c1, &c2, &c3, &probability, t,
           &qr_0, qtsquare, qtfisher, &error_code);
}

//
// Arguments    : int argc
//                char **argv
// Return Type  : int
//
int main(int, char **)
{
  // The initialize function is being called automatically from your entry-point
  // function. So, a call to initialize is not included here. Invoke the
  // entry-point functions.
  // You can call entry-point functions multiple times.
  main_calculate_qtfisher();
  main_calculate_qtsquare();
  main_metrosquare();
  main_my_error_square();
  main_prediction_my_error();
  main_prediction_POS();
  main_probability_PIMC();
  main_run_main();
  // Terminate the application.
  // You do not need to do this more than one time.
  calculate_qtfisher_terminate();
  return 0;
}

//
// File trailer for main.cpp
//
// [EOF]
//
