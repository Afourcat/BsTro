 /*
 ** EPITECH PROJECT, 2017
 ** error_utils.c
 ** File description:
 ** error functions like my_putstr_error
 */

#include <unistd.h>

int my_putchar_error(char c)
{
    write(2, &c, 1);
    return (0);
}

int my_putstr_error(char *s)
{
    while (*s) {
        my_putchar_error(*s);
        s++;
    }
    return (0);
}
