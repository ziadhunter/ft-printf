//#include "../includes/ft_printf.h"
#include "ft_printf.h"

int handle_char(va_list args, flags found)
{
    char c;

    (void)found;
    c = va_arg(args, int);
    return(write(1, &c,1));
}