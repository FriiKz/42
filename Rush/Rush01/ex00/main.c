/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 19:02:50 by lbusi             #+#    #+#             */
/*   Updated: 2022/02/13 22:34:10 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(char c)
{
	write(1, &c, 1);
}

void	matrice(void)
{
	int	index;
	int	invio;

	invio = 0;
	while (invio < 4)
	{
		index = 0;
		while (index < 4)
		{
			print('0');
			if (index != 3)
			{
				print('|');
			}
			index++;
		}
		print('\n');
		invio++;
	}
}

int	main(void)
{
	matrice();
}
