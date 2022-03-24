/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:44:48 by lbusi             #+#    #+#             */
/*   Updated: 2022/02/24 14:51:04 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	div;

	div = 2;
	if (nb == 0 || nb == 1)
		return (0);
	if (nb > 2147483647)
		return (0);
	while (div < nb)
	{
		if (nb % div == 0)
			return (0);
		div++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	prime_num;

	prime_num = nb;
	while (prime_num < 2147483647)
	{
		if (ft_is_prime(prime_num))
			return (prime_num);
		else
			prime_num++;
	}
	return (0);
}
