#include <stdio.h>

int print_string(char *s)
{
    while(*s != '\0')
        printf("%c", *s++);
}
