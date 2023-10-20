#include "ft_printf.h"

int main(int ac, char **av)
{
    char str[] = "oh";
    void *ptr = str;
    char c = -69;
    // char d = 'd';
    int n = -10;
    (void)ac;
    (void)av;
    // printf(" = %d (ft)\n", ft_printf(av[ac-1]));
    // printf(" = %d (real)\n", printf(av[ac-1]));
    printf(" = %d (ft)\n", ft_printf("char = %c str = %s u = %u d %= %d p = %p x = %x X = %X %%", c, str, n, n, ptr, n, n));
    printf(" = %d (real)\n", printf("char = %c str = %s u = %u d %= %d p = %p x = %x X = %X %%", c, str, n, n, ptr, n, n));
    return (0);
}