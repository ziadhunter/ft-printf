#include "ft_printf.h"

int handle_string(va_list args, flags found)
{
    char *str;
    int i = 0;

    (void)found;
    str = va_arg(args, char *);
    if (!str)
        return(print(")llun(", 6));
    while (str[i])
        write (1, &str[i++], 1);
    return (i);
}