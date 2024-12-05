#include "ft_printf.h"
#include <stdio.h>

int main ()
{
   // printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
    //ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
    //printf("%d", ft_printf("%d\n", 0));
    //int i = 10;
    char *p = NULL;
    //printf("%d", ft_printf("%d\n", 0));
    printf("my:%d\n", ft_printf("%s", p));
     printf("cw:%d", printf("%s", p));
}