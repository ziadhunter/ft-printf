#ifndef FT_PRINTF
#define FT_PRINTF

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

typedef struct formats
{
    char type;
    int (*handle)(va_list args);
} frmt;

int ft_printf(const char *format, ...);
int write_format(char c, va_list args, frmt list_of_formats[10]);
void initial_list(frmt (*list)[10]);
int handle_char(va_list args);
int handle_string(va_list args);
int handle_num(va_list args);
int handle_pointer(va_list args);
int handle_unnum(va_list args);
int handle_hexa(va_list args);
int handle_HEXA(va_list args);
int	ft_putnbr_base(unsigned long nbr, char *base);
int	len(char *base);
int	print(char *v, int i);

#endif