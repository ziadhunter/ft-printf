#include <stdarg.h>
#include <stdlib.h>

typedef struct formats
{
    char type;
    int (*handle)(va_list args);
} frmt;

int handle_char(va_list args)
{
    char c;

    c = va_arg(args, int);
    return(write(1, &c,1));
}
int handle_string(va_list args)
{
    char *str;
    int i = 0;

    str = va_arg(args, char *);
    while (str[i])
        write (1, &str[i++], 1);
    return (i);
}
int	print(char *v, int i)
{
    int j;

    j = 0;
	while (i >= 0)
	{
		j += write(1, &v[i], 1);
		i--;
	}
    return (j);
}

int	len(char *base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

int	ft_putnbr_base(size_t nbr, char *base)
{
	int			i;
	char		v[17];
	unsigned int	k;
    int count;

	k = nbr;
    count = 0;

	if (k == 0)
	{
		count += write(1, base, 1);
		return count;
	}
	i = 0;
	while (k > 0)
	{
		v[i++] = base[k % len(base)];
		k /= len(base);
	}
	count += print(v, i - 1);
    return count;
}
int handle_hexa(va_list args)
{
    return(ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef"));
}
int handle_HEXA(va_list args)
{
    return(ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF"));
}
int handle_pointer(va_list args)
{
    int count;
    unsigned long j;

    j = va_arg(args, unsigned long);
    if ()
    count = write(1, "0x", 2);
    count += ft_putnbr_base(, "0123456789")
}

void initial_lis(frmt *list[10]) 
{
    //*list[0] = (frmt){'c', handle_char};
    (*list)[0].type = 'c';
    (*list)[0].handle = handle_char;
    (*list)[1].type = 's';
    (*list)[1].handle = handle_string;
    (*list)[2].type = 'p';
    (*list)[2].handle =// handle_pointer;
    (*list)[3].type = 'd';
    (*list)[3].handle =// putchar;
    (*list)[4].type = 'i';
    (*list)[4].handle = putchar;
    (*list)[5].type = 'u';
    (*list)[5].handle = putchar;
    (*list)[6].type = 'x';
    (*list)[6].handle = handle_hexa;
    (*list)[7].type = 'X';
    (*list)[7].handle = handle_HEXA;
    (*list)[8].type = '%';
    (*list)[8].handle = putchar;
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
            count += write_format(format[i++], args, list_of_formats);
    }
}
