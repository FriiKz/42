/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:31:19 by lbusi             #+#    #+#             */
/*   Updated: 2023/04/19 18:54:36 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_dollar(t_data *t, char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '$')
		{
			i++;
			while (str[i] && str[i] != ' ')
			{
				i++;
				len++;
			}
			check_env_value(t, str, len);
			return (1);
		}
		else
			i++;
	}
	return (0);
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

void	check_env_value(t_data *t, char *str, int len)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (t->my_env[i])
	{
		k = index_finder(str);
		if (env_strncmp(t->my_env[i], str, len, k) == 0)
			expander(t, str, i);
		i++;
	}
}

int	index_finder(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '$')
	{
		i++;
	}
	i++;
	return (i);
}

void	expander(t_data *t, char *str, int i)
{
	int		k;
	int		z;
	int		j;
	char	*tmp_env;
	char	*tmp_command;

	tmp_env = malloc(sizeof(char) * ft_strlen(t->my_env[i]));
	if (!tmp_env)
		return ;
	tmp_command = malloc(ft_strlen(str) + ft_strlen(t->my_env[i]));
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
	while (str[j] && str[j] != '$')
	{
		tmp_command[k] = str[j];
		j++;
		k++;
	}
	while (str[j] && str[j] != ' ')
		j++;
	while (tmp_env[z])
	{
		tmp_command[k] = tmp_env[z];
		k++;
		z++;
	}
	while (str[j])
	{
		tmp_command[k] = str[j];
		k++;
		j++;
	}
	tmp_command[k] = (char) NULL;
	command_into_parsed(t, tmp_command);
	if (check_dollar(t->parsed))
		find_dollar(t, t->parsed);
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
}

void	unparser(t_data *t)
{
	int	i;

	i = 0;
	free(t->parsed);
	t->parsed = malloc(sizeof(char) * ft_strlen(t->command));
	if (!t->parsed)
		return ;
	while (t->command[i])
	{
		t->parsed[i] = t->command[i];
		i++;
	}
	t->parsed[i] = t->command[i];
}

int	check_dollar(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
			return (1);
		i++;
	}
	return (0);
}
