#include <stdio.h>
 
#include <kernel/tty.h>
 
void kernel_main(void) 
{
	terminal_initialize();
	printf("Greetings!\nYou are from the anomalous materials lab, yes, I recognize you.");
}