#include <stdio.h>
#include <sys/wait.h>
#include <stdbool.h>

extern __pid_t wait (int __stat_loc)
{
    bool loop = true;
    double index = 0.0;

    while (loop == true)
    {
        index += 0.0001;

        if (index >= __stat_loc)
        {
            loop = false;
        }
    }
    

    return 0;
}