/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:54:20 by lbusi             #+#    #+#             */
/*   Updated: 2022/11/28 19:14:20 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_doubles(char *str, char c, int len)
{
	int	i;

	i = 0;
	while (str[i] && i < len)
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 3)
	{
		while (argv[1][i])
		{
			if (check_doubles(argv[1], argv[1][i], i))
			{
				write(1, &argv[1][i], 1);
			}
			i++;
		}
		i = 0;
		while (argv[2][i])
		{
			if (check_doubles(argv[2], argv[2][i], i) && check_doubles(argv[1], argv[2][i], ft_strlen(argv[1])))
			{
				write(1, &argv[2][i], 1);
			}	
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
