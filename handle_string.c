#include "ft_printf.h"

int handle_string(va_list args)
{
    char *str;
    int i = 0;

    str = va_arg(args, char *);
    if (!str)
        return(print(")llun(", 6));
    while (str[i])
        write (1, &str[i++], 1);
    return (i);
}