/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:45:00 by lbusi             #+#    #+#             */
/*   Updated: 2023/04/17 17:45:26 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	if (!s)
		return (0);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	i = 0;
	j = 0;
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (0);
	while (s[i])
	{
		if (i >= start && j < len)
		{
			ptr[j] = s[i];
			j++;
		}
		i++;
	}
	ptr[j] = '\0';
	return (ptr);
}

int	check_build_in(char *cmd)
{
	if (!ft_strcmp_s("pwd", ft_strlen("pwd"), cmd, ft_strlen(cmd)))
		return (1);
	else if (!ft_strcmp_s("cd", ft_strlen("cd"), cmd, ft_strlen(cmd)))
		return (1);
	else if (!ft_strcmp_s("export", ft_strlen("export"), cmd, ft_strlen(cmd)))
		return (1);
	else if (!ft_strcmp_s("unset", ft_strlen("unset"), cmd, ft_strlen(cmd)))
		return (1);
	else if (!ft_strcmp_s("echo", ft_strlen("echo"), cmd, ft_strlen(cmd)))
		return (1);
	else if ((!ft_strcmp_s("exit", ft_strlen("exit"), cmd, ft_strlen(cmd))))
		return (1);
	else if (!ft_strcmp_s("env", ft_strlen("env"), cmd, ft_strlen(cmd)))
		return (1);
	return (0);
}
