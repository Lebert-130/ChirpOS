#ifndef _MATH_H
# error "Never include <bits/mathcalls.h> directly; include <math.h> instead."

#include <math/math.h>

/* Trigonometric functions. */

/* Arc cosine of X. */
//__MATHCALL (acos,, (_Mdouble_ __x));
/* Arc sine of X. */
//__MATHCALL (asin,, (_Mdouble_ __x));
/* Arc tangent of X. */
//__MATHCALL (atan,, (_Mdouble_ __x));
/* Arc tangent of Y/X */
//__MATHCALL (atan2,, (_Mdouble_ __y, _Mdouble_ __x));

/* Cosine of X. */
//__MATHCALL_VEC (cos,, (_Mdouble_ __x));
/* Sine of X. */
//__MATHCALL_VEC (sin,, (_Mdouble_ __x));
/* Tangent of X. */
//__MATHCALL (tan,, (_Mdouble_ __x));

/* Hyperbolic functions.  */

/* Hyperbolic cosine of X.  */
//__MATHCALL (cosh,, (_Mdouble_ __x));
/* Hyperbolic sine of X.  */
//__MATHCALL (sinh,, (_Mdouble_ __x));
/* Hyperbolic tangent of X.  */
//__MATHCALL (tanh,, (_Mdouble_ __x));

#ifdef __USE_GNU
/* Cosine and sine of X.  */
//__MATHDECL_VEC (void,sincos,,
//                (_Mdouble_ __x, _Mdouble_ *__sinx, _Mdouble_ *__cosx));
#endif

#if defined __USE_XOPEN_EXTENDED || defined __USE_ISOC99
/* Hyperbolic arc cosine of X.  */
//__MATHCALL (acosh,, (_Mdouble_ __x));

/* Hyperbolic arc sine of X.  */
//__MATHCALL (asinh,, (_Mdouble_ __x));

/* Hyperbolic arc tangent of X.  */
//__MATHCALL (atanh,, (_Mdouble_ __x));
#endif

/* Exponential and logarithmic functions.  */

/* Exponential function of X.  */
//__MATHCALL_VEC (exp,, (_Mdouble_ __x));

/* Break VALUE into a normalized fraction and an integral power of 2.  */
//__MATHCALL (frexp,, (_Mdouble_ __x, int *__exponent));

/* X times (two to the EXP power).  */
//__MATHCALL (ldexp,, (_Mdouble_ __x, int __exponent));

/* Natural logarithm of X.  */
//__MATHCALL_VEC (log,, (_Mdouble_ __x));

/* Base-ten logarithm of X.  */
//__MATHCALL (log10,, (_Mdouble_ __x));

/* Break VALUE into integral and fractional parts.  */
//__MATHCALL (modf,, (_Mdouble_ __x, _Mdouble_ *__iptr)) __nonnull ((2));

//#if __GLIBC_USE (IEC_60559_FUNCS_EXT)
/* Compute exponent to base ten.  */
//__MATHCALL (exp10,, (_Mdouble_ __x));
//#endif

/* Power functions. */

/* Return X to the Y power. */
//__MATHCALL_VEC (pow,, (_Mdouble_ __x, _Mdouble_ __y));

/* Return the square root of X. */
__MATHCALL (sqrt,, (_Mdouble_ __x));

#if defined __USE_XOPEN || defined __USE_ISOC99
/* Return `sqrt(X*X + Y*Y)'.  */
//__MATHCALL (hypot,, (_Mdouble_ __x, _Mdouble_ __y));
#endif

#if defined __USE_XOPEN_EXTENDED || defined __USE_ISOC99
/* Return the cube root of X.  */
//__MATHCALL (cbrt,, (_Mdouble_ __x));
#endif

/* Nearest integer, absolute value, and remainder functions.  */

/* Smallest integral value not less than X.  */
//__MATHCALLX (ceil,, (_Mdouble_ __x), (__const__));

/* Absolute value of X. */
//__MATHCALLX (fabs,, (_Mdouble_ __x), (__const__));

/* Largest integer not greater than X. */
//__MATHCALLX (floor,, (_Mdouble_ __x), (__const__));

/* Floating-point modulo remainder of X/Y. */
//__MATHCALL (fmod,, (_Mdouble_ __x, _Mdouble_ __y));

#if defined __USE_XOPEN_EXTENDED || defined __USE_ISOC99
/* Return the integer nearest X in the direction of the
   prevailing rounding mode.  */
//__MATHCALL (rint,, (_Mdouble_ __x));

/* Return X + epsilon if X < Y, X - epsilon if X > Y.  */
//__MATHCALL (nextafter,, (_Mdouble_ __x, _Mdouble_ __y));
# if defined __USE_ISOC99 && !defined __LDBL_COMPAT && !__MATH_DECLARING_FLOATN
//__MATHCALL (nexttoward,, (_Mdouble_ __x, long double __y));
# endif
#endif

#ifdef __USE_ISOC99
/* Round X to nearest integral value, rounding halfway cases away from
   zero.  */
//__MATHCALLX (round,, (_Mdouble_ __x), (__const__));
/* Round X to the integral value in floating-point format nearest but
   not larger in magnitude.  */
//__MATHCALLX (trunc,, (_Mdouble_ __x), (__const__));
#endif

#ifdef __USE_ISOC99
/* Return X with its signed changed to Y's.  */
//__MATHCALLX (copysign,, (_Mdouble_ __x, _Mdouble_ __y), (__const__));
#endif
#endif