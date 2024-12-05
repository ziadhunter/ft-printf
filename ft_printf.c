//#include "../includes/ft_printf.h"
#include "ft_printf.h"

void initial_list(frmt (*list)[10]) 
{
    //*list[0] = (frmt){'c', handle_char};
    (*list)[0].type = 'c';
    (*list)[0].handle = handle_char;
    (*list)[1].type = 's';
    (*list)[1].handle = handle_string;
    (*list)[2].type = 'p';
    (*list)[2].handle = handle_pointer;
    (*list)[3].type = 'd';
    (*list)[3].handle = handle_num;
    (*list)[4].type = 'i';
    (*list)[4].handle = handle_num;
    (*list)[5].type = 'u';
    (*list)[5].handle = handle_unnum;
    (*list)[6].type = 'x';
    (*list)[6].handle = handle_hexa;
    (*list)[7].type = 'X';
    (*list)[7].handle = handle_HEXA;
    (*list)[9].type = 0;
    (*list)[9].handle = NULL;

}

int write_format(char c, va_list args, frmt list_of_formats[10])
{
    int i;

    i = 0;
    while(list_of_formats[i].handle)
    {
        if (list_of_formats[i].type == c)
            return(list_of_formats[i].handle(args));
        i++;
    }
    return (0);
}

int ft_printf(const char *format, ...)
{
    va_list args;
    frmt list_of_formats[10];
    int i;
    int count;

    if (write(1, 0, 0) == -1)
        return (-1);
    initial_list(&list_of_formats);
    va_start(args, format);
    i = 0;
    count = 0;
    while(format[i])
    {
        if (format[i] == '%')
        {
            if (format[i+1] == '%')
                count += write(1, "%", 1);
            else
                count += write_format(format[i+1], args, list_of_formats);
            i += 2;
        }
        else
            count += write(1, &format[i++], 1);
    }
    return (count);
}

