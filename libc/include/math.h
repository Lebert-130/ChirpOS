#ifndef		_MATH_H

#include <math/math.h>

#if !(defined __FINITE_MATH_ONLY__ && __FINITE_MATH_ONLY > 0)
#   ifndef NO_MATH_REDIRECT
/* Declare some functions for use within GLIBC.  Compilers typically
   inline those functions as a single instruction.  Use an asm to
   avoid use of PLTs if it doesn't.  */
#   define MATH_REDIRECT(FUNC, PREFIX, ARGS)    \
 float (FUNC ## f) (ARGS (float)) asm (PREFIX #FUNC "f");   \
 double (FUNC) (ARGS (double)) asm(PREFIX #FUNC);   \
 MATH_REDIRECT_LDBL (FUNC, PREFIX, ARGS)    \
 MATH_REDIRECT_F128 (FUNC, PREFIX, ARGS)
#   ifdef __NO_LONG_DOUBLE_MATH
#    define MATH_REDIRECT_LDBL(FUNC, PREFIX, ARGS)
#   else
#    define MATH_REDIRECT_LDBL(FUNC, PREFIX, ARGS)  \
 long double (FUNC ## l) (ARGS (long double)) asm (PREFIX #FUNC "l");
#   endif
#   if __HAVE_DISTINCT_FLOAT128
#    define MATH_REDIRECT_F128(FUNC, PREFIX, ARGS)  \
 _Float128 (FUNC ## f128) (ARGS (_Float128)) asm (PREFIX #FUNC "f128");
#   else
#    define MATH_REDIRECT_F128(FUNC, PREFIX, ARGS)
#   endif
#   define MATH_REDIRECT_UNARY_ARGS(TYPE) TYPE
#   define MATH_REDIRECT_BINARY_ARGS(TYPE) TYPE, TYPE
MATH_REDIRECT (sqrt, "__ieee754_", MATH_REDIRECT_UNARY_ARGS)
MATH_REDIRECT (ceil, "__", MATH_REDIRECT_UNARY_ARGS)
MATH_REDIRECT (floor, "__", MATH_REDIRECT_UNARY_ARGS)
MATH_REDIRECT (rint, "__", MATH_REDIRECT_UNARY_ARGS)
MATH_REDIRECT (trunc, "__", MATH_REDIRECT_UNARY_ARGS)
MATH_REDIRECT (round, "__", MATH_REDIRECT_UNARY_ARGS)
MATH_REDIRECT (copysign, "__", MATH_REDIRECT_BINARY_ARGS)
#endif
#endif

#endif