/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:51:40 by lbusi             #+#    #+#             */
/*   Updated: 2023/03/23 15:06:52 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_cmd(t_data *t)
{
	int	l;

	l = 0;
	if (t->matrix[0] != NULL)
	{
		l = ft_strlen(t->matrix[0]);
		if (strncmp("echo", t->matrix[0], l) == 0 && l == 4)
			t->cmd = 1;
		else if (strncmp("cd", t->matrix[0], l) == 0 && l == 2)
			t->cmd = 1;
		else if (strncmp("pwd", t->matrix[0], l) == 0 && l == 3)
			t->cmd = 1;
		else if (strncmp("export", t->matrix[0], l) == 0 && l == 6)
			t->cmd = 1;
		else if (strncmp("unset", t->matrix[0], l) == 0 && l == 5)
			t->cmd = 1;
		else if (strncmp("env", t->matrix[0], l) == 0 && l == 3)
			t->cmd = 1;
		else if (strncmp("exit", t->matrix[0], l) == 0 && l == 4)
			t->cmd = 1;
	}
	else
		t->cmd = 0;
}
