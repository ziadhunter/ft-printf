#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

typedef struct wich_flags
{
    int plus;
    int hashtage;
    int space;
} flags;

typedef struct formats
{
    char type;
    int (*handle)(va_list args, flags found);
} frmt;



int write_format(const char *str, va_list args, frmt list_of_formats[10], int *flag);
void initial_list(frmt (*list)[10]);
int handle_char(va_list args, flags found);
int handle_string(va_list args, flags found);
int handle_num(va_list args, flags found);
int handle_pointer(va_list args, flags found);
int handle_unnum(va_list args, flags found);
int handle_hexa(va_list args, flags found);
int handle_HEXA(va_list args, flags found);
int	ft_putnbr_base(unsigned long nbr, char *base);
int	ft_putnbr(int nb);
int	len(char *base);
int	print(char *v, int i);
int ft_printf(const char *format, ...);

#endif