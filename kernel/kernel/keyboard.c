#include <stdio.h>
#include <kernel/keyboard_input.h>
#include <kernel/io.h>
#include <kernel/tty.h>

void keyboard_input()
{
    char c = 0;
    init_pics(0x20, 0x28);
    do
    {
        if (inb(0x60)!=c)
        {
            c = inb(0x60);
            
            switch (c)
            {
            case 0x29:
                printf("`");
                break;
            case 0x02:
                printf("1");
                break;
            case 0x03:
                printf("2");
                break;
            case 0x04:
                printf("3");
                break;
            case 0x05:
                printf("4");
                break;
            case 0x06:
                printf("5");
                break;
            case 0x07:
                printf("6");
                break;
            case 0x08:
                printf("7");
                break;
            case 0x09:
                printf("8");
                break;
            case 0x0A:
                printf("9");
                break;
            case 0x0B:
                printf("0");
                break;
            case 0x0C:
                printf("-");
                break;
            case 0x0D:
                printf("=");
                break;
            case 0x0E:
                terminal_removechar();
                break;

            case 0x10:
                printf("q");
                break;
            case 0x11:
                printf("w");
                break;
            case 0x12:
                printf("e");
                break;
            case 0x13:
                printf("r");
                break;
            case 0x14:
                printf("t");
                break;
            case 0x15:
                printf("y");
                break;
            case 0x16:
                printf("u");
                break;
            case 0x17:
                printf("i");
                break;
            case 0x18:
                printf("o");
                break;
            case 0x19:
                printf("p");
                break;
            case 0x1A:
                printf("[");
                break;
            case 0x1B:
                printf("]");
                break;

            case 0x1C:
                //Enter key
                break;
            
            case 0x1E:
                printf("a");
                break;
            case 0x1F:
                printf("s");
                break;
            case 0x20:
                printf("d");
                break;
            case 0x21:
                printf("f");
                break;
            case 0x22:
                printf("g");
                break;
            case 0x23:
                printf("h");
                break;
            case 0x24:
                printf("j");
                break;
            case 0x25:
                printf("k");
                break;
            case 0x26:
                printf("l");
                break;
            case 0x27:
                printf(";");
                break;
            case 0x28:
                printf("'");
                break;
            case 0x2B:
                printf("\\");
                break;
            case 0x56:
                printf("\\");
                break;
            case 0x2C:
                printf("z");
                break;
            case 0x2D:
                printf("x");
                break;
            case 0x2E:
                printf("c");
                break;
            case 0x2F:
                printf("v");
                break;
            case 0x30:
                printf("b");
                break;
            case 0x31:
                printf("n");
                break;
            case 0x32:
                printf("m");
                break;
            case 0x33:
                printf(",");
                break;
            case 0x34:
                printf(".");
                break;
            case 0x35:
                printf("/");
                break;
            
            case 0x39:
                printf(" ");
                break;
            
            case 0x4F:
                printf("1");
                break;
            case 0x50:
                printf("2");
                break;
            case 0x51:
                printf("3");
                break;
            case 0x4B:
                printf("4");
                break;
            case 0x4C:
                printf("5");
                break;
            case 0x4D:
                printf("6");
                break;
            case 0x47:
                printf("7");
                break;
            case 0x48:
                printf("8");
                break;
            case 0x49:
                printf("9");
                break;
            case 0x52:
                printf("0");
                break;
            case 0x53:
                printf(".");
                break;
            case 0xE035:
                printf("/");
                break;
            case 0x37:
                printf("*");
                break;
            case 0x4A:
                printf("-");
                break;
            case 0x4E:
                printf("+");
                break;
                
            default:
                //do nothing
                break;
            }
        }
    } while (c!=1);
}