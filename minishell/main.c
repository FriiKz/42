/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:50:15 by lbusi             #+#    #+#             */
/*   Updated: 2023/03/31 14:31:57 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_data	t;
	char	*command;

	(void)argc;
	(void)argv;
	t.i = 0;
	t.cmd = -1;
	ft_sig_handling_set(SIG_INITIAL);
	while (1)
	{
		command = readline("minishell> ");
		t.matrix = ft_split(command, ' ');
		check_cmd(&t);
		if (strcmp(t.matrix[0], "echo") == 0 && t.cmd == 1)
			echo(&t);
		if (strcmp(t.matrix[0], "pwd") == 0 && t.cmd == 1)
		{
			pwd(&t);
			ft_free(&t);
		}
		if (strcmp(t.matrix[0], "cd") == 0 && t.cmd == 1)
		{
			cd(&t);
			ft_free(&t);
		}
		if (strcmp(t.matrix[0], "exit") == 0)
			ft_exit(&t);
		if (strcmp(t.matrix[0], "env") == 0)
		{
			ft_env(env);
			ft_free(&t);
		}
		if (strcmp(t.matrix[0], "export") == 0)
		{
			ft_export(env);
			ft_free(&t);
		}
		add_history(command);
		free(command);
	}
	return (0);
}
