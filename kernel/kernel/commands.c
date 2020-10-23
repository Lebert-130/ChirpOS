#include <stdio.h>
#include <kernel/keyboard_input.h>

int send_command(const char* restrict format, ...)
{
    int sent = 0;

    if (format[0] == 'h' && format[1] == 'l' && format[2] == 'w' && format[3] == 'l' && format[4] == 'd')
    {
        printf("Hello World!");
        clear_chars(0);
    }

    printf("\n>");

    return sent;
}