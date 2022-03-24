/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavolio <gavolio@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 19:04:19 by gavolio           #+#    #+#             */
/*   Updated: 2022/02/06 18:13:40 by gramiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int		maxx;
	int		maxy;

	maxx = x;
	maxy = y;
	while (y >= 1)
	{
		x = maxx;
		while (x >= 1)
		{
			if ((x == maxx && y == maxy) || (x == maxx && y == 1))
				ft_putchar('A');
			else if ((x == 1 && y == maxy) || (x == 1 && y == 1))
				ft_putchar('C');
			else if ((x == maxx) || (y == maxy) || (x == 1) || (y == 1))
				ft_putchar('B');
			else
				ft_putchar(' ');
				x--;
		}
		ft_putchar('\n');
		y--;
	}
}
