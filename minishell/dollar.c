/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:31:19 by lbusi             #+#    #+#             */
/*   Updated: 2023/04/19 12:34:33 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	find_dollar(t_data *t)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (t->command[i])
	{
		if (t->command[i] == '$')
		{
			i++;
			while (t->command[i] && t->command[i] != ' ')
			{
				i++;
				len++;
			}
			check_env_value(t, len);
		}
		else
			i++;
	}
}

int	env_strncmp(const char *s1, const char *s2, size_t n, int j)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s2[j] && s1[i] && (i < n - 1) && (s1[i] == s2[j]))
	{
		j++;
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[j]);
}

void	check_env_value(t_data *t, int len)
{
	int	i;
	int	j;
	int	ok;
	int	k;

	i = 0;
	ok = 0;
	j = 0;
	while (t->my_env[i])
	{
		k = index_finder(t);
		if (env_strncmp(t->my_env[i], t->command, len, k) == 0)
		{
			ok = 1;
			expander(t, i);
		}
		i++;
	}
}

int	index_finder(t_data *t)
{
	int	i;

	i = 0;
	while (t->command[i] && t->command[i] != '$')
	{
		i++;
	}
	i++;
	return (i);
}

void	expander(t_data *t, int i)
{
	int		k;
	int		z;
	int		j;
	char	*tmp_env;
	char	*tmp_command;

	tmp_env = malloc(sizeof(char) * ft_strlen(t->my_env[i]));
	if (!tmp_env)
		return ;
	tmp_command = malloc(ft_strlen(t->command) + ft_strlen(t->my_env[i]));
	if (!tmp_command)
		return ;
	j = 0;
	k = 0;
	z = 0;
	while (t->my_env[i][j] != '=')
		j++;
	j++;
	while (t->my_env[i][j])
	{
		tmp_env[k] = t->my_env[i][j];
		k++;
		j++;
	}
	j = 0;
	k = 0;
	while (t->command[j] && t->command[j] != '$')
	{
		tmp_command[k] = t->command[j];
		j++;
		k++;
	}
	while (t->command[j] && t->command[j] != ' ')
		j++;
	while (tmp_env[z])
	{
		tmp_command[k] = tmp_env[z];
		k++;
		z++;
	}
	while (t->command[j])
	{
		tmp_command[k] = t->command[j];
		k++;
		j++;
	}
	command_into_parsed(t, tmp_command);
}

void	command_into_parsed(t_data *t, char *tmp_command)
{
	int	i;

	i = 0;
	t->parsed = malloc(sizeof(char) * ft_strlen(tmp_command) + 1);
	if (!t->parsed)
		return ;
	while (tmp_command[i])
	{
		t->parsed[i] = tmp_command[i];
		i++;
	}
	t->parsed[i] = tmp_command[i];
	printf("%s\n", t->parsed);
}

// void	unparser(t_data *t)
// {
// 	int	i;

// 	i = 0;
// 	free(t->parsed);
// 	t->parsed = malloc(sizeof(char) * ft_strlen(t->command));
// 	if (!t->parsed)
// 		return ;
// 	while (t->command[i])
// 	{
// 		t->parsed[i] = t->command[i];
// 		i++;
// 	}
// 	t->parsed[i] = t->command[i];
// }
