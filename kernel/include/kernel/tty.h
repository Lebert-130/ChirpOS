#ifndef _KERNEL_TTY_H
#define _KERNEL_TTY_H
 
#include <stddef.h>
#include <stdint.h>
 
void terminal_initialize(void);
void terminal_putchar(char c);
void terminal_write(const char* data, size_t size);
void terminal_writestring(const char* data);
void terminal_scroll();
void terminal_removechar();
void enable_cursor(uint8_t cursor_start, uint8_t cursor_end);
void disable_cursor();
void NMI_enable();
void NMI_disable();
void init_pics(int pic1, int pic2);

void reverse(char s[]);
void change_current_pos();

#endif