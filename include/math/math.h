#ifndef     _MATH_H
#define     _MATH_H 1

#define __GLIBC_INTERNAL_STARTING_HEADER_IMPLEMENTATION
#include <bits/libc-header-start.h>

#if defined log && defined __GNUC__
# warning A macro called log was already defined when <math.h> was included.
# warning This will cause compilation problems.
#endif

__BEGIN_DECLS

/* Get definitions of __intmax_t and __uintmax_t.  */
//#include <bits/types.h> (not yet)
/* Get machine-dependent vector math functions declarations.  */
//#include <bits/math-vector.h> (not yet)
/* Gather machine dependent type support.  */
//#include <bits/floatn.h> (not yet)

/* The file <bits/mathcalls.h> contains the prototypes for all the
   actual math functions.  These macros are used for those prototypes,
   so we can easily declare each function as both `name' and `__name',
   and can declare the float versions `namef' and `__namef'.  */

#define __SIMD_DECL(function) __CONCAT (__DECL_SIMD_, function)

#define __MATHCALL_VEC(function, suffix, args)         \
  __SIMD_DECL (__MATH_PRECNAME (function, suffix)) \
  __MATHCALL (function, suffix, args)

#define __MATHDECL_VEC(type, function,suffix, args) \
  __SIMD_DECL (__MATH_PRECNAME (function, suffix)) \
  __MATHDECL(type, function,suffix, args)
  
#define __MATHCALL(function,suffix, args)        \
  __MATHDECL (_Mdouble_,function,suffix, args)
#define __MATHDECL(type, function,suffix, args) \
  __MATHDECL_1(type, function,suffix, args); \
  __MATHDECL_1(type, __CONCAT(__,function),suffix, args)
#define __MATHCALLX(function,suffix, args, attrib)        \
  __MATHDECLX (_Mdouble_,function,suffix, args, attrib)
#define __MATHDECLX(type, function,suffix, args, attrib) \
  __MATHDECL_1(type, function,suffix, args) __attribute__ (attrib); \
  __MATHDECL_1(type, __CONCAT(__,function),suffix, args) __attribute__ (attrib)
#define __MATHDECL_1(type, function,suffix, args) \
  extern type __MATH_PRECNAME(function,suffix) args __THROW

#define _Mdouble_   double
#define _MATH_PRECNAME(name,r)  __CONCAT(name,r)
#define _MATH_DECLARING_DOUBLE 1
#define _MATH_DECLARING_FLOATN 0
//#include <bits/mathcalls-helper-functions.h>
#include <bits/mathcalls.h>
#undef  _Mdouble_
#undef  __MATH_PRECNAME
#undef __MATH_DECLARING_DOUBLE
#undef __MATH_DECLARING_FLOATN

__END_DECLS

#endif