/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrstein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:19:54 by chrstein          #+#    #+#             */
/*   Updated: 2023/11/06 16:20:15 by chrstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_strdup(char *src)
{
	int		len;
	int		i;
	char	*copy;

	len = ft_strlen(src);
	copy = malloc(sizeof(char) * (len + 1));
	if (copy == NULL)
		return (NULL);
	i = -1;
	while (src[++i])
		copy[i] = src[i];
	copy[i] = 0;
	return (copy);
}
