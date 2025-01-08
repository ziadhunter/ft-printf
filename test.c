#include "stdio.h"
#include "ft_printf.h"

// int main(void)
// {
//     // Test %d with flags
//     printf("|Original: |% d|\n", 42);
//     ft_printf("|Custom:   |% d|\n", 42);

//     printf("|Original: |%+d|\n", 42);
//     ft_printf("|Custom:   |%+d|\n", 42);

//     printf("|Original: |%#x|\n", 42);
//     ft_printf("|Custom:   |%#x|\n", 42);

//     printf("|Original: |%#o|\n", 42);
//     ft_printf("|Custom:   |%#o|\n", 42);

//     // Test combined flags
//     printf("|Original: |%+ d|\n", 42);
//     ft_printf("|Custom:   |%+ d|\n", 42);

//     printf("|Original: |%#+x|\n", 42);
//     ft_printf("|Custom:   |%#+x|\n", 42);

//     printf("|Original: |%# x|\n", 42);
//     ft_printf("|Custom:   |%# x|\n", 42);

//     // Edge cases with 0
//     printf("|Original: |% d|\n", 0);
//     ft_printf("|Custom:   |% d|\n", 0);

//     printf("|Original: |%+d|\n", 0);
//     ft_printf("|Custom:   |%+d|\n", 0);

//     printf("|Original: |%#x|\n", 0);
//     ft_printf("|Custom:   |%#x|\n", 0);

//     return 0;
// }

#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
    // Test %d with flags
    printf("|Original: |% d|\n", 42);
    ft_printf("|Custom:   |% d|\n", 42);

    printf("|Original: |%+d|\n", 42);
    ft_printf("|Custom:   |%+d|\n", 42);

    printf("|Original: |% d|\n", -42);
    ft_printf("|Custom:   |% d|\n", -42);

    printf("|Original: |%+d|\n", -42);
    ft_printf("|Custom:   |%+d|\n", -42);

    // Edge case: 0 with %d
    printf("|Original: |% d|\n", 0);
    ft_printf("|Custom:   |% d|\n", 0);

    printf("|Original: |%+d|\n", 0);
    ft_printf("|Custom:   |%+d|\n", 0);

    // Test %x and %X with #
    printf("|Original: |%#x|\n", 42);
    ft_printf("|Custom:   |%#x|\n", 42);

    printf("|Original: |%#X|\n", 42);
    ft_printf("|Custom:   |%#X|\n", 42);

    // Edge case: 0 with %x and %X
    printf("|Original: |%#x|\n", 0);
    ft_printf("|Custom:   |%#x|\n", 0);

    printf("|Original: |%#X|\n", 0);
    ft_printf("|Custom:   |%#X|\n", 0);

    return 0;
}

