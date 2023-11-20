/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_conversions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrstein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 22:37:22 by chrstein          #+#    #+#             */
/*   Updated: 2023/11/13 22:39:02 by chrstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	if (!str)
		return (ft_putstr_fd("(null)", 1));
	return (ft_putstr_fd(str, 1));
}

int	print_p(va_list args)
{
	int		i;
	int		i2;
	size_t	p;

	p = va_arg(args, size_t);
	i2 = 0;
	if (p)
	{
		i = ft_putstr_fd("0x", 1);
		i2 = ft_putnbr_base(p, "0123456789abcdef", 16);
		if (i == -1 || i2 == -1)
			return (-1);
	}
	else
		i = ft_putstr_fd("(nil)", 1);
	return (i + i2);
}

int	print_n_base10(va_list args, char c)
{
	int		i;
	char	*str;

	if (c == 'u')
		str = ft_utoa(va_arg(args, unsigned int));
	else
		str = ft_itoa(va_arg(args, int));
	if (!str)
		return (0);
	i = ft_putstr_fd(str, 1);
	free(str);
	return (i);
}
