#ifndef _KERNEL_IO_H
#define _KERNEL_IO_H

#include <stddef.h>
#include <stdint.h>

inline void outb(uint16_t port, uint8_t value)
{
    __asm("outb %b0, %w1"
        :: "a"(value), "d"(port));
}

static inline uint8_t inb(uint16_t port)
{
    uint8_t ret;
    asm volatile ( "inb %1, %0"
                   : "=a"(ret)
                   : "Nd"(port) );
    return ret;
}

#endif