#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <stddef.h>

int     ft_printf(const char *str, ...);
int     print_str(va_list args);
int     print_n_base10(va_list args, char c);
char    *ft_utoa(unsigned int n);
int     ft_putnbr_base(size_t nb, char *base, size_t base_len);
int     print_p(va_list args);

#endif
