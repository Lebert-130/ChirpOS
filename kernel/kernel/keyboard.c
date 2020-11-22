#include <stdio.h>
#include <kernel/keyboard_input.h>
#include <kernel/io.h>
#include <kernel/tty.h>

char read_chars[255];

void clear_chars(int commandID)
{
    if (commandID == 0) //hlwld
    {
        for (int i = 0; i < 4; i++)
        {
            read_chars[i] = ' ';
        }
    }

    if (commandID == 1) //echo
    {
        for (int i = 0; i < 50; i++)
        {
            read_chars[i] = ' ';
        }
    }
}

void keyboard_input()
{
    int index = -1;
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
                read_chars[index+1] = '`';
                index += 1;
                break;
            case 0x02:
                printf("1");
                read_chars[index+1] = '1';
                index += 1;
                break;
            case 0x03:
                printf("2");
                read_chars[index+1] = '2';
                index += 1;
                break;
            case 0x04:
                printf("3");
                read_chars[index+1] = '3';
                index += 1;
                break;
            case 0x05:
                printf("4");
                read_chars[index+1] = '4';
                index += 1;
                break;
            case 0x06:
                printf("5");
                read_chars[index+1] = '5';
                index += 1;
                break;
            case 0x07:
                printf("6");
                read_chars[index+1] = '6';
                index += 1;
                break;
            case 0x08:
                printf("7");
                read_chars[index+1] = '7';
                index += 1;
                break;
            case 0x09:
                printf("8");
                read_chars[index+1] = '8';
                index += 1;
                break;
            case 0x0A:
                printf("9");
                read_chars[index+1] = '9';
                index += 1;
                break;
            case 0x0B:
                printf("0");
                read_chars[index+1] = '0';
                index += 1;
                break;
            case 0x0C:
                printf("-");
                read_chars[index+1] = '-';
                index += 1;
                break;
            case 0x0D:
                printf("=");
                read_chars[index+1] = '=';
                index += 1;
                break;
            case 0x0E:
                terminal_removechar();

                if (index > -2)
                {
                    index -= 1;
                }

                break;

            case 0x10:
                printf("q");
                read_chars[index+1] = 'q';
                index += 1;
                break;
            case 0x11:
                printf("w");
                read_chars[index+1] = 'w';
                index += 1;
                break;
            case 0x12:
                printf("e");
                read_chars[index+1] = 'e';
                index += 1;
                break;
            case 0x13:
                printf("r");
                read_chars[index+1] = 'r';
                index += 1;
                break;
            case 0x14:
                printf("t");
                read_chars[index+1] = 't';
                index += 1;
                break;
            case 0x15:
                printf("y");
                read_chars[index+1] = 'y';
                index += 1;
                break;
            case 0x16:
                printf("u");
                read_chars[index+1] = 'u';
                index += 1;
                break;
            case 0x17:
                printf("i");
                read_chars[index+1] = 'i';
                index += 1;
                break;
            case 0x18:
                printf("o");
                read_chars[index+1] = 'o';
                index += 1;
                break;
            case 0x19:
                printf("p");
                read_chars[index+1] = 'p';
                index += 1;
                break;
            case 0x1A:
                printf("[");
                read_chars[index+1] = '[';
                index += 1;
                break;
            case 0x1B:
                printf("]");
                read_chars[index+1] = ']';
                index += 1;
                break;

            case 0x1C:
                printf("\n");
                send_command(read_chars);
                index = -1;
                change_current_pos();
                break;
            
            case 0x1E:
                printf("a");
                read_chars[index+1] = 'a';
                index += 1;
                break;
            case 0x1F:
                printf("s");
                read_chars[index+1] = 's';
                index += 1;
                break;
            case 0x20:
                printf("d");
                read_chars[index+1] = 'd';
                index += 1;
                break;
            case 0x21:
                printf("f");
                read_chars[index+1] = 'f';
                index += 1;
                break;
            case 0x22:
                printf("g");
                read_chars[index+1] = 'g';
                index += 1;
                break;
            case 0x23:
                printf("h");
                read_chars[index+1] = 'h';
                index += 1;
                break;
            case 0x24:
                printf("j");
                read_chars[index+1] = 'j';
                index += 1;
                break;
            case 0x25:
                printf("k");
                read_chars[index+1] = 'k';
                index += 1;
                break;
            case 0x26:
                printf("l");
                read_chars[index+1] = 'l';
                index += 1;
                break;
            case 0x27:
                printf(";");
                read_chars[index+1] = ';';
                index += 1;
                break;
            case 0x28:
                printf("'");
                read_chars[index+1] = '\'';
                index += 1;
                break;
            case 0x2B:
                printf("\\");
                read_chars[index+1] = '\\';
                index += 1;
                break;
            case 0x56:
                printf("\\");
                read_chars[index+1] = '\\';
                index += 1;
                break;
            case 0x2C:
                printf("z");
                read_chars[index+1] = 'z';
                index += 1;
                break;
            case 0x2D:
                printf("x");
                read_chars[index+1] = 'x';
                index += 1;
                break;
            case 0x2E:
                printf("c");
                read_chars[index+1] = 'c';
                index += 1;
                break;
            case 0x2F:
                printf("v");
                read_chars[index+1] = 'v';
                index += 1;
                break;
            case 0x30:
                printf("b");
                read_chars[index+1] = 'b';
                index += 1;
                break;
            case 0x31:
                printf("n");
                read_chars[index+1] = 'n';
                index += 1;
                break;
            case 0x32:
                printf("m");
                read_chars[index+1] = 'm';
                index += 1;
                break;
            case 0x33:
                printf(",");
                read_chars[index+1] = ',';
                index += 1;
                break;
            case 0x34:
                printf(".");
                read_chars[index+1] = '.';
                index += 1;
                break;
            case 0x35:
                printf("/");
                read_chars[index+1] = '/';
                index += 1;
                break;
            
            case 0x39:
                printf(" ");
                read_chars[index+1] = ' ';
                index += 1;
                break;
            
            case 0x4F:
                printf("1");
                read_chars[index+1] = '1';
                index += 1;
                break;
            case 0x50:
                printf("2");
                read_chars[index+1] = '2';
                index += 1;
                break;
            case 0x51:
                printf("3");
                read_chars[index+1] = '3';
                index += 1;
                break;
            case 0x4B:
                printf("4");
                read_chars[index+1] = '4';
                index += 1;
                break;
            case 0x4C:
                printf("5");
                read_chars[index+1] = '5';
                index += 1;
                break;
            case 0x4D:
                printf("6");
                read_chars[index+1] = '6';
                index += 1;
                break;
            case 0x47:
                printf("7");
                read_chars[index+1] = '7';
                index += 1;
                break;
            case 0x48:
                printf("8");
                read_chars[index+1] = '8';
                index += 1;
                break;
            case 0x49:
                printf("9");
                read_chars[index+1] = '9';
                index += 1;
                break;
            case 0x52:
                printf("0");
                read_chars[index+1] = '0';
                index += 1;
                break;
            case 0x53:
                printf(".");
                read_chars[index+1] = '.';
                index += 1;
                break;
            case 0xE035:
                printf("/");
                read_chars[index+1] = '/';
                index += 1;
                break;
            case 0x37:
                printf("*");
                read_chars[index+1] = '*';
                index += 1;
                break;
            case 0x4A:
                printf("-");
                read_chars[index+1] = '-';
                index += 1;
                break;
            case 0x4E:
                printf("+");
                read_chars[index+1] = '+';
                index += 1;
                break;

            default:
                //do nothing
                break;
            }
        }
    } while (c!=1);
}