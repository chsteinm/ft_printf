/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrstein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 22:48:26 by chrstein          #+#    #+#             */
/*   Updated: 2023/11/13 22:48:38 by chrstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(size_t nb, char *base, size_t base_len)
{
	int	count;

	count = 1;
	if (nb >= base_len)
		count += ft_putnbr_base(nb / base_len, base, base_len);
	ft_putchar_fd(base[nb % base_len], 1);
	return (count);
}
