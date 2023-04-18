/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:35:49 by lbusi             #+#    #+#             */
/*   Updated: 2023/04/18 19:09:42 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		printf("%s\n", env[i]);
		i++;
	}
}

void	create_env(t_data *t, char **env)
{
	int	i;
	int	len;

	i = 0;
	len = count_env(env);
	t->my_env = malloc(sizeof(char *) * len + 1);
	while (env[i])
	{
		t->my_env[i] = env[i];
		i++;
	}
}

int	count_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
		i++;
	return (i);
}

void	apici_quotes(t_data *t)
{
	int	i;
	int	quote;
	int	apice;

	i = 0;
	quote = 0;
	apice = 0;
	t->closed = 0;
	while (t->command[i])
	{
		if (t->command[i] == '\'')
			apice++;
		else if (t->command[i] == '\"')
			quote++;
		i++;
	}
	if (quote % 2 == 0 && apice % 2 == 0)
		t->closed = !t->closed;
}

// void	mini_parser(t_data *t)
// {
// 	int	i;

// 	i = 0;
// 	t->apici = 0;
// 	while (t->command[i])
// 	{
// 		if (t->command[i] == '\'')
// 			t->apici = !t->apici;
		
// 	}
// }
