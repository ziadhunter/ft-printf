#include "ft_printf.h"

int handle_hexa(va_list args, flags found)
{
    int j;
    int i;

    j = 0;
    i = va_arg(args, unsigned int);
    if (found.hashtage)
    {
        if (i != 0)
            j = write(1, "0x", 2);
    }
    return(ft_putnbr_base(i, "0123456789abcdef") + j);
}
int handle_HEXA(va_list args, flags found)
{
    int j;
    int i;

    j = 0;
    i = va_arg(args, unsigned int);
    if (found.hashtage)
    {
        if (i != 0)
            j = write(1, "0X", 2);
    }
    return(ft_putnbr_base(i, "0123456789ABCDEF") + j);
}