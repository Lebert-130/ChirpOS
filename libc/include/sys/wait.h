#ifndef _SYS_WAIT_H
#define _SYS_WAIT_H 1

#include <features.h>

__BEGIN_DECLS

#include <bits/types.h>
#ifndef __pid_t_defined
typedef __pid_t pid_t;
#define __pid_t_defined
#endif

extern __pid_t wait (int __stat_loc);

__END_DECLS

#endif