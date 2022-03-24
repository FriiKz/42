/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:33:07 by lbusi             #+#    #+#             */
/*   Updated: 2022/02/03 22:36:38 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_print_alphabet(void)
{
	char	alphabet[26];
	int		counter;
	char	character;

	counter = 0;
	character = 'a';
	while (counter < 26)
	{
		alphabet[counter] = character;
		counter++;
		character++;
	}
	write(1, alphabet, 26);
}
