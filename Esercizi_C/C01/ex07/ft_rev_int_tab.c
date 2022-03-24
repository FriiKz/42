/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:55:39 by lbusi             #+#    #+#             */
/*   Updated: 2022/02/14 11:40:49 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_tab_int(int *tab, int size)
{
	int	count;
	int	t;

	count = 0;
	while (count < size / 2)
	{
		t = tab[count];
		tab[count] = tab[size - 1 - t];
		tab[size - 1 - t] = t;
		count++;
	}
}
