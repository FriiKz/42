/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gramiro- <gramiro-@student.42roma.i>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 12:44:53 by gramiro-          #+#    #+#             */
/*   Updated: 2022/02/06 18:13:52 by gramiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	xmax;
	int	ymax;

	ymax = y;
	xmax = x;
	while (y >= 1)
	{
		x = xmax;
		while (x >= 1)
		{
			if ((x == xmax && y == ymax) || (x == 1 && y == 1))
				ft_putchar('A');
			else if ((x == 1 && y == ymax) || (x == xmax && y == 1))
				ft_putchar('C');
			else if ((x == 1) || (y == 1) || (x == xmax) || (y == ymax))
				ft_putchar('B');
			else
				ft_putchar(' ');
			x--;
		}
		ft_putchar('\n');
		y--;
	}
}
