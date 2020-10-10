#ifndef _SYS_CDEFS_H
#define _SYS_CDEFS_H 1
 
#define __chirpos_libc 1

/* We are almost always included from features.h. */
#ifndef _FEATURES_H
# include <features.h>
#endif

/* The GNU libc does not support any K&R compilers or the traditional mode
   of ISO C compilers anymore.  Check for some of the combinations not
   anymore supported.  */
#if defined __GNUC__ && !defined __STDC__
# error "You need a ISO C conforming compiler to use the glibc headers"
#endif

/* Some user header file might have defined this before.  */
#undef        __P
#undef        __PMT

#ifdef __GNUC__
/* All functions, except those with callbacks or those that
   synchronize memory, are leaf functions.  */

//C++ stuff missing if we want to
#  define __LEAF
#  define __LEAF_ATTR

/* GCC can always grok prototypes.  For C++ programs we add throw()
   to help it optimize the function calls.  But this works only with
   gcc 2.8.x and egcs.  For gcc 3.2 and up we even mark C functions
   as non-throwing using a function attribute since programs can use
   the -fexceptions options for C code as well.  */

#  define __THROW
#  define __THROWNL
#  define __NTH(fct)  fct
#  define __NTHNL(fct) fct

#else        /* Not GCC.  */
# if (defined __cplusplus                                                \
      || (defined __STDC_VERSION__ && __STDC_VERSION__ >= 199901L))
#  define __inline        inline
# else
#  define __inline                /* No inline functions.  */
# endif
# define __THROW
# define __THROWNL
# define __NTH(fct)        fct
#endif        /* GCC.  */

/* For these things, GCC behaves the ANSI way normally,
   and the non-ANSI way under -traditional.  */

#define __CONCAT(x, y)  x ## y
#define __STRING(x) #x

/* C++ needs to know that types and declarations are C, not C++.  */
#ifdef  __cplusplus
# define __BEGIN_DECLS      extern "C" {
# define __END_DECLS    }
#else
# define __BEGIN_DECLS
# define __END_DECLS
#endif

/* GCC has various useful declarations that can be made with the
   `__attribute__' syntax.  All of the ways we use this do fine if
   they are omitted for compilers that don't understand it. */
#if !defined __GNUC__ || __GNUC__ < 2
# define __attribute__(xyz)        /* Ignore */
#endif

#define __extension__

#endif