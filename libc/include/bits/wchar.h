#ifndef _BITS_WCHAR_H
#define _BITS_WCHAR_H        1
/* The fallback definitions, for when __WCHAR_MAX__ or __WCHAR_MIN__
   are not defined, give the right value and type as long as both int
   and wchar_t are 32-bit types.  Adding L'\0' to a constant value
   ensures that the type is correct; it is necessary to use (L'\0' +
   0) rather than just L'\0' so that the type in C++ is the promoted
   version of wchar_t rather than the distinct wchar_t type itself.
   Because wchar_t in preprocessor #if expressions is treated as
   intmax_t or uintmax_t, the expression (L'\0' - 1) would have the
   wrong value for WCHAR_MAX in such expressions and so cannot be used
   to define __WCHAR_MAX in the unsigned case.  */
#ifdef __WCHAR_MAX__
# define __WCHAR_MAX        __WCHAR_MAX__
#elif L'\0' - 1 > 0
# define __WCHAR_MAX        (0xffffffffu + L'\0')
#else
# define __WCHAR_MAX        (0x7fffffff + L'\0')
#endif
#ifdef __WCHAR_MIN__
# define __WCHAR_MIN        __WCHAR_MIN__
#elif L'\0' - 1 > 0
# define __WCHAR_MIN        (L'\0' + 0)
#else
# define __WCHAR_MIN        (-__WCHAR_MAX - 1)
#endif
#endif        /* bits/wchar.h */