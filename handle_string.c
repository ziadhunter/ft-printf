#include "ft_printf.h"

int handle_string(va_list args)
{
    char *str;

    str = va_arg(args, char *);
    if (!str)
        return(print(")llun(", 5));
    return (write (1, str, len(str)));
}