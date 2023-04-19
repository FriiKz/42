/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:50:15 by lbusi             #+#    #+#             */
/*   Updated: 2023/04/19 18:53:26 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}

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
		if (!find_dollar(&t, t.command))
			unparser(&t);
		apici_quotes(&t);
		if (t.closed != 1)
		{
			printf("unclosed quotes\n");
			t.closed = 0;
		}
		t.matrix = malloc(sizeof(char *) * 100);
		t.matrix = ft_split(t.parsed, ' ', &t);
		check_cmd(&t);
		if (!strcmp(t.matrix[0], "echo") && t.cmd == 1)
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
	}
	return (0);
}
