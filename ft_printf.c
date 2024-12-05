#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct formats
{
    char type;
    int (*handle)(va_list args);
} frmt;
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
    if (!str)
        return(print(")llun(", 6));
    while (str[i])
        write (1, &str[i++], 1);
    return (i);
}


int	len(char *base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

int	ft_putnbr_base(unsigned long nbr, char *base)
{
	int			i;
	char		v[17];

    int count;

    count = 0;

	if (nbr == 0)
	{
		count += write(1, base, 1);
		return count;
	}
	i = 0;
	while (nbr > 0)
	{
		v[i++] = base[nbr % len(base)];
		nbr /= len(base);
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
    if (j ==  0)
        return (print(")lin(", 4));
    count = write(1, "0x", 2);
    count += ft_putnbr_base( j, "0123456789abcdef");
    return count;
}

int	ft_putnbr(int nb)
{
    int count;
    int i;
    char v[12];
    char base[] = "0123456789";

    i = 0;
    count = 0;
	if (nb == -2147483648)
	{
		count += write(1, "-2147483648", 11);
	}
	if (nb < 0)
	{
		count += write(1, "-", 1);
		nb *= -1;
	}
	while(nb > 0)
    {
        v[i++] = base[nb % 10];
		nb /= 10;
    }
    count = print(v, i-1);
    return count;
}

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
#include <stdio.h>

int main()
{
    int i = 15;
    char *p = NULL;
    // printf("%d\n", ft_printf("%%%%%%%c%%%s%%%%s%%%d\n", 'z', "zakaria", 666));
    // printf("%d\n", printf("%%%%%%%c%%%s%%%%s%%%d\n", 'z', "zakaria", 666));
    // printf("%d", ft_printf("%"));
    // printf("\n");
    ft_printf("%s\n", p);
    printf("%s", p);
    printf("\n");
}
