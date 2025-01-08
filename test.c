#include "ft_printf.h"
#include <stdio.h>

int main ()
{
   int a;
   int b;

   a = printf("%#x %#X\n", 15, 15);
   b = ft_printf("%#x %#X\n", 15, 15);
   printf("%d - %d\n", a, b);

   a = printf("%+d\n", 15);
   b = ft_printf("%+d\n", 15);
   printf("%d - %d\n", a, b);

      a = printf("% d\n", 15);
   b = ft_printf("% d\n", 15);
   printf("%d - %d\n", a, b);
}