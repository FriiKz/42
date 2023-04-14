/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:45:45 by lbusi             #+#    #+#             */
/*   Updated: 2023/04/14 16:44:13 by lbusi            ###   ########.fr       */
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
	t->i = 1;
	if (!t->matrix[1])
		printf("\n");
	else if (strncmp(t->matrix[1], "-n", 2) == 0)
	{
		check_echo(t);
		if (t->flag == 1)
			echo_component_one(t);
		else if (t->flag == 0)
			echo_component_two(t);
	}
	else
	{
		while (t->matrix[t->i])
		{
			printf("%s ", t->matrix[t->i]);
			t->i++;
		}
		printf("\n");
	}
	ft_free(t);
}

void	echo_component_one(t_data *t)
{
	t->i = 2;
	while (t->matrix[t->i])
	{
		if (t->matrix[t->i + 1])
			printf("%s ", t->matrix[t->i]);
		else
			printf("%s", t->matrix[t->i]);
		t->i++;
	}
}

void	echo_component_two(t_data *t)
{
	while (t->matrix[t->i])
	{
		printf("%s ", t->matrix[t->i]);
		t->i++;
	}
	printf("\n");
}
