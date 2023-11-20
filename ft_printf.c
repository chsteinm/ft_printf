/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrstein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 22:39:16 by chrstein          #+#    #+#             */
/*   Updated: 2023/11/13 22:40:39 by chrstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_c(va_list args)
{
	return (ft_putchar_fd(va_arg(args, int), 1));
}

int	print_convert(va_list args, const char *str)
{
	int	i;

	i = 0;
	if (*str == 'c')
		i += print_c(args);
	else if (*str == 's')
		i += print_str(args);
	else if (*str == 'd' || *str == 'u' || *str == 'i')
		i += print_n_base10(args, *str);
	else if (*str == 'p')
		i += print_p(args);
	else if (*str == 'x')
		i += ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef", 16);
	else if (*str == 'X')
		i += ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF", 16);
	else if (*str == '%')
		i += write(1, "%%", 1);
	else
		i += ft_putchar_fd(*str, 1);
	return (i);
}

int	print_printable(const char *str)
{
	int	i;

	i = -1;
	while (str[++i] != '%' && str[i])
		if (ft_putchar_fd(str[i], 1) == -1)
			return (-1);
	return (i);
}

int print(va_list args, const char *str)
{
	int	count_printed_char;
	int	i;
	int	check;

	count_printed_char = 0;
	while (*str)
	{
		if (*str == '%')
		{
			check = print_convert(args, str + 1);
			if (check == -1)
				return (-1);
			count_printed_char += check;
			str += 2;
		}
		i = print_printable(str);
		if (i == -1)
			return (-1);
		count_printed_char += i;
		str += i;
	}
	return (count_printed_char);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count_printed_char;

	if (!str)
		return (-1);
	if (!(*str))
		return (0);
	count_printed_char = 0;
	va_start(args, str);
	count_printed_char = print(args, str);
	va_end(args);
	return (count_printed_char);
}
