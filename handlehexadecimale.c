#include "ft_printf.h"

int handle_hexa(va_list args)
{
    return(ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef"));
}
int handle_HEXA(va_list args)
{
    return(ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF"));
}