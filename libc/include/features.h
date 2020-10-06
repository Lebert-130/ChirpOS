#ifndef _FEATURES_H
#define _FEATURES_H 1

/* Undefine everything, so we get a clean slate.  */
#undef        __USE_ISOC11
#undef        __USE_ISOC99
#undef        __USE_ISOC95
#undef        __USE_ISOCXX11
#undef        __USE_POSIX
#undef        __USE_POSIX2
#undef        __USE_POSIX199309
#undef        __USE_POSIX199506
#undef        __USE_XOPEN
#undef        __USE_XOPEN_EXTENDED
#undef        __USE_UNIX98
#undef        __USE_XOPEN2K
#undef        __USE_XOPEN2KXSI
#undef        __USE_XOPEN2K8
#undef        __USE_XOPEN2K8XSI
#undef        __USE_LARGEFILE
#undef        __USE_LARGEFILE64
#undef        __USE_FILE_OFFSET64
#undef        __USE_MISC
#undef        __USE_ATFILE
#undef        __USE_GNU
#undef        __USE_FORTIFY_LEVEL
#undef        __KERNEL_STRICT_NAMES
#undef        __GLIBC_USE_DEPRECATED_GETS
#undef        __GLIBC_USE_DEPRECATED_SCANF

#if defined __GNUC__ && defined __GNUC_MINOR__
# define __GNU_PREREQ(maj, min) \
    ((__GNUC__ << 16) + __GNUC_MINOR__ >= ((maj) << 16) + (min))
#else
# define __GNUC_PREREQ(maj, min) 0
#endif

/* This is here only because every header file already includes this one.  */
#ifndef __ASSEMBLER__
# ifndef _SYS_CDEFS_H
#  include <sys/cdefs.h>
# endif
#endif

#endif