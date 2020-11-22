#include <stdio.h>
#include <kernel/keyboard_input.h>

int string_size(const char* restrict str)
{
    int Size = 0;
    while (str[Size] != '\0') Size++;
    return Size;
}

int send_command(const char* restrict format, ...)
{
    int sent = 0;

    if (format[0] == 'h' && format[1] == 'l' && format[2] == 'w' && format[3] == 'l' && format[4] == 'd')
    {
        printf("Hello World!");
        clear_chars(0);
    }

    if (format[0] == 'e' && format[1] == 'c' && format[2] == 'h' && format[3] == 'o')
    {
        char phrase[255];

        for (int i = 5; i < string_size(format); i++)
        {
            phrase[i-5] = format[i];
        }

        printf(phrase);

        for (int i = 0; i < string_size(phrase); i++)
        {
            phrase[i] = ' ';
        }
        clear_chars(1);
    }

    printf("\n>");

    return sent;
}