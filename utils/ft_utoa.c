/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrstein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 22:48:58 by chrstein          #+#    #+#             */
/*   Updated: 2023/11/13 22:50:59 by chrstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	rec(unsigned int nb, char *ptr, int len)
{
	if (nb > 9)
		rec(nb / 10, ptr, len - 1);
	ptr[len - 1] = nb % 10 + 48;
}

char	*ft_utoa(unsigned int n)
{
	unsigned int	nb;
	char			str[12];
	char			*ptr;
	int				len;

	ft_bzero(str, 12);
	ptr = str;
	nb = n;
	len = (n == 0);
	while (n && ++len)
		n /= 10;
	rec(nb, ptr, len);
	return (ft_strdup(str));
}
