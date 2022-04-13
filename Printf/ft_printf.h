/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:41:42 by lbusi             #+#    #+#             */
/*   Updated: 2022/04/12 18:02:05 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H


# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <string.h>

int		ft_putchar(char c);
int		ft_putnbr(int nb);
int		ft_putstr(char *str);
int		ft_strlen(const char *str);
int	    len(int nb, int base);
int	    long_len(long long nb, int base);

int	    ft_put_uint_nbr(unsigned int nb);

int 	ft_print_char(va_list n);

int		ft_hex_len(uintptr_t num);
int		ft_hex_print(unsigned long long num, const char format);
void	ft_hex(uintptr_t num, const char format);

int		ft_ptr_len(uintptr_t num);
int		ft_ptr_print(uintptr_t num);
void	ft_ptr_conv(uintptr_t num);

#endif
