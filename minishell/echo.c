/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:45:45 by lbusi             #+#    #+#             */
/*   Updated: 2023/03/31 11:49:47 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_echo(t_data *t)
{
	int	i;

	i = 2;
	while (t->matrix[1][i])
	{
		if (t->matrix[1][i] == 'n')
			i++;
		else
		{
			t->flag = 0;
			return ;
		}
	}
	t->flag = 1;
}

void	echo(t_data *t)
{
	int	i;

	i = 1;
	if (!t->matrix[1])
		printf("\n");
	else if (strncmp(t->matrix[1], "-n", 2) == 0)
	{
		check_echo(t);
		if (t->flag == 1)
		{
			i = 2;
			while (t->matrix[i])
			{
				if (t->matrix[i + 1])
					printf("%s ", t->matrix[i]);
				else
					printf("%s", t->matrix[i]);
				i++;
			}
		}
		else if (t->flag == 0)
		{
			while (t->matrix[i])
			{
				printf("%s ", t->matrix[i]);
				i++;
			}
			printf("\n");
		}
	}
	else
	{
		while (t->matrix[i])
		{
			printf("%s ", t->matrix[i]);
			i++;
		}
		printf("\n");
	}
	ft_free(t);
}

void	echo_flag(t_data *t)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (t->matrix[i])
	{
		if (strchr(&t->matrix[i][j], '-'))
		{
			j = 1;
			while (strchr(&t->matrix[i][j], 'n'))
				j++;
			while (!strcmp(t->matrix[i], "-n ") )
			{
				printf("%s", t->matrix[i]);
				i++;
			}
			i++;
		}
		else
		{
			while (t->matrix[i])
			{
				printf("%s ", t->matrix[i]);
				i++;
			}
			printf("\n");
		}
	}
	ft_free(t);
}

// size_t	n_times(char **arg)
// {
// 	size_t	i;
// 	size_t	j;

// 	i = 0;
// 	while (arg[++i])
// 	{
// 		j = 0;
// 		if (arg[i][j++] == '-' && arg[i][j] == 'n' && arg[i][j])
// 		{
// 			while (arg[i][j] == 'n')
// 				j++;
// 			if (arg[i][j] && arg[i][j] != 'n')
// 				return (1);
// 		}
// 		else
// 			return (i);
// 	}
// 	return (i);
// }
