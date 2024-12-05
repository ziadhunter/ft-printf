//#include "../includes/ft_printf.h"
#include "ft_printf.h"

int handle_num(va_list args)
{
    int i;

    i = va_arg(args, int);
    return(ft_putnbr(i));
}

int handle_unnum(va_list args)
{
    unsigned int i;

    i = va_arg(args, unsigned int);
    return(ft_putnbr_base(i, "0123456789"));
}