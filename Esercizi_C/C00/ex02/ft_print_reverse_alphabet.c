/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 22:43:41 by lbusi             #+#    #+#             */
/*   Updated: 2022/02/03 23:02:15 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_print_reverse_alphabet(void)
{
	char	alphabet[26];
	int		a;
	char	character;

	a = 0;
	character = 'z';
	while (a < 26)
	{
		alphabet[a] = character;
		a++;
		character--;
	}
	write(1, alphabet, 26);
}
