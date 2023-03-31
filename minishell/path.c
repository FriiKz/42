/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:34:09 by lbusi             #+#    #+#             */
/*   Updated: 2023/03/21 12:04:42 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pwd(t_data *t)
{
	char	cwd[256];

	if (getcwd(cwd, sizeof(cwd)) == NULL)
		perror("getcwd() error");
	else
		printf("%s\n", cwd);
	t->path = cwd;
}

void	cd(t_data *t)
{
	t->path = t->matrix[1];
	if (!t->matrix[1])
		chdir(getenv("HOME"));
	else if (chdir(t->matrix[1]) != 0)
	{
		write(1, "cd: ", 4);
		perror(t->matrix[1]);
	}
}
