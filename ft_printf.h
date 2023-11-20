/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrstein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 23:05:15 by chrstein          #+#    #+#             */
/*   Updated: 2023/11/13 23:05:27 by chrstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>

int		ft_printf(const char *str, ...);
int		print_str(va_list args);
int		print_n_base10(va_list args, char c);
int		print_p(va_list args);
int		ft_putnbr_base(size_t nb, char *base, size_t base_len);
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
char	*ft_utoa(unsigned int n);
char	*ft_itoa(int n);
int		ft_strlen(char *str);
void	*ft_bzero(void *str, int size);
char	*ft_strdup(char *src);

#endif
