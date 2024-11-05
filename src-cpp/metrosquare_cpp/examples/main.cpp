//
// File: main.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 03-Nov-2024 23:50:41
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
#include "metrosquare.h"
#include "metrosquare_terminate.h"
#include "my_error_square.h"
#include "run_main.h"

// Function Declarations
static void argInit_1x2_real_T(double result[2]);

static void argInit_32x2_real_T(double result[64]);

static double argInit_real_T();

static void main_metrosquare();

static void main_my_error_square();

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
// Arguments    : double result[64]
// Return Type  : void
//
static void argInit_32x2_real_T(double result[64])
{
  // Loop over the array to initialize each element.
  for (int idx0{0}; idx0 < 32; idx0++) {
    for (int idx1{0}; idx1 < 2; idx1++) {
      // Set the value of the array element.
      // Change this value to the value that the application requires.
      result[idx0 + (idx1 << 5)] = argInit_real_T();
    }
  }
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
static void main_metrosquare()
{
  double dv[64];
  double kb;
  double kr;
  double qb_0_tmp;
  // Initialize function 'metrosquare' input arguments.
  // Initialize function input argument 'data'.
  qb_0_tmp = argInit_real_T();
  // Call the entry-point 'metrosquare'.
  argInit_32x2_real_T(dv);
  metrosquare(dv, qb_0_tmp, qb_0_tmp, &kr, &kb);
}

//
// Arguments    : void
// Return Type  : void
//
static void main_my_error_square()
{
  double dv1[64];
  double dv[2];
  double qb_0_tmp;
  // Initialize function 'my_error_square' input arguments.
  // Initialize function input argument 'v'.
  // Initialize function input argument 'data'.
  qb_0_tmp = argInit_real_T();
  // Call the entry-point 'my_error_square'.
  argInit_1x2_real_T(dv);
  argInit_32x2_real_T(dv1);
  qb_0_tmp = my_error_square(dv, dv1, qb_0_tmp, qb_0_tmp);
}

//
// Arguments    : void
// Return Type  : void
//
static void main_run_main()
{
  double dv[64];
  double kb;
  double kr;
  double qb_0_tmp;
  // Initialize function 'run_main' input arguments.
  // Initialize function input argument 'data'.
  qb_0_tmp = argInit_real_T();
  // Call the entry-point 'run_main'.
  argInit_32x2_real_T(dv);
  run_main(dv, qb_0_tmp, qb_0_tmp, &kr, &kb);
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
  main_metrosquare();
  main_my_error_square();
  main_run_main();
  // Terminate the application.
  // You do not need to do this more than one time.
  metrosquare_terminate();
  return 0;
}

//
// File trailer for main.cpp
//
// [EOF]
//
