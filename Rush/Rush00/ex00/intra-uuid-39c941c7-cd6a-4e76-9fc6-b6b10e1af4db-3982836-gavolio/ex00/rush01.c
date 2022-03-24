/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gramiro- <gramiro-@student.42roma.i>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 16:33:59 by gramiro-          #+#    #+#             */
/*   Updated: 2022/02/06 18:13:01 by gramiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	ymax;
	int	maxix;

	ymax = y;
	maxix = x;
	while (y >= 1)
	{	
		x = maxix;
		while (x >= 1)
		{		
			if ((x == maxix && y == ymax) || (x == 1 && y == 1))
				ft_putchar('/');
			else if ((x == 1 && y == ymax) || (x == maxix && y == 1))
				ft_putchar('\\');
			else if ((x == maxix) || (y == ymax) || (x == 1) || (y == 1))
				ft_putchar('*');
			else
				ft_putchar(' ');
		x--;
		}
		ft_putchar('\n');
		y--;
	}
}
