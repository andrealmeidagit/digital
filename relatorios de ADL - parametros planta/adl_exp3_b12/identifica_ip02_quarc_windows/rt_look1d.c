/*
 * rt_look1d.c
 *
 * Real-Time Workshop code generation for Simulink model "identifica_ip02.mdl".
 *
 * Model Version              : 1.506
 * Real-Time Workshop version : 7.2  (R2008b)  04-Aug-2008
 * C source code generated on : Wed Oct 03 15:57:19 2018
 *
 */

#include "rt_look1d.h"

/* Function: rt_Lookup ==============================================
 * Abstract:
 *      1D lookup routine for data type of real_T
 */
real_T rt_Lookup(const real_T *x, int_T xlen, real_T u, const real_T *y)
{
  int_T idx = rt_GetLookupIndex(x, xlen, u);
  real_T num = y[idx+1] - y[idx];
  real_T den = x[idx+1] - x[idx];

  /* Due to the way the binary search is implemented
     in rt_look.c (rt_GetLookupIndex), den cannot be
     0.  Equivalently, m cannot be inf or nan. */
  real_T m = num/den;
  return (y[idx] + m * (u - x[idx]));
}
