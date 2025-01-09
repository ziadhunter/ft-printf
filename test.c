#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	a;
	int	b;

	int *p;

	a = printf("%#x %#X\n", 15, 15);
	b = ft_printf("%#x %#X\n", 15, 15);
	printf("%d - %d\n", a, b);


	a = printf("%#x %#X\n", 0, 0);
	b = ft_printf("%#x %#X\n", 0, 0);
	printf("%d - %d\n", a, b);


	a = printf("%+d\n", 15);
	b = ft_printf("%+d\n", 15);
	printf("%d - %d\n", a, b);


	a = printf("% d\n", 15);
	b = ft_printf("% d\n", 15);
	printf("%d - %d\n", a, b);

	a = printf("%s\n", "dwkayfd");
	b = ft_printf("%s\n", "dwkayfd");
	printf("%d - %d\n", a, b);

	a = printf("%d\n", -247483648);
	b = ft_printf("%i\n", -2147483648);
	printf("%d - %d\n", a, b);
}
