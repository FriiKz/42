/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:50:15 by lbusi             #+#    #+#             */
/*   Updated: 2023/04/19 12:06:44 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_data	t;

	(void)argc;
	(void)argv;
	struct_init(&t);
	ft_sig_handling(SIG_INITIAL);
	while (1)
	{
		t.command = readline("minishell> ");
		ctrl_d(&t);
		create_env(&t, env);
		t.parsed = malloc(sizeof(char) * ft_strlen(t.command));
		find_dollar(&t);
		write(1, "dio\n", 4);
		apici_quotes(&t);
		if (t.closed != 1)
		{
			printf("unclosed quotes\n");
			t.closed = 0;
		}
		t.matrix = ft_split(t.parsed, ' ', &t);
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
		add_history(t.command);
		free(t.command);
		free(t.parsed);
	}
	return (0);
}
