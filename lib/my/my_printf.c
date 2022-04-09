/*
** EPITECH PROJECT, 2021
** my_printf.c
** File description:
** displays format
*/

#include <stdarg.h>
#include "my.h"

int big_s(char *str)
{
    int size = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 32 || str[i] >= 127) {
            size += my_putchar('\\');
            size += put_octal_base(str[i]);
        } else
            size += my_putchar(str[i]);
    }
    return size;
}

int print_flag(const char *format, int i, va_list va)
{
    if (format[i + 1] == 'S')
        return big_s(va_arg(va, char *));
    if (format[i + 1] == 'x' || format[i + 1] == 'X')
        return put_hex_base(va_arg(va, int), format[i + 1]);
    if (format[i + 1] == 'o')
        return put_octal_base(va_arg(va, int));
    if (format[i + 1] == 'b')
        return put_bin_base(va_arg(va, int));
    if (format[i + 1] == 'd' || format[i + 1] == 'i' || format[i + 1] == 'u')
        return my_put_nbr(va_arg(va, int));
    if (format[i + 1] == 'c')
        return my_putchar(va_arg(va, int));
    if (format[i + 1] == 's')
        return my_putstr(va_arg(va, char *));
    if (format[i + 1] == '%')
        return my_putchar('%');
    if (format[i + 1] == '\0')
        return my_putchar(format[i]);
    return 0;
}

int my_printf(const char *format, ...)
{
    va_list va;
    int res = 0;
    int temp = 0;

    va_start(va, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] != '%')
            res += my_putchar(format[i]);
        else if (print_flag(format, i, va))
            i++;
    }
    va_end(va);
    return res;
}
