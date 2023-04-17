/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 13:10:31 by lbusi             #+#    #+#             */
/*   Updated: 2023/04/17 16:31:53 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern void	rl_replace_line(const char *text, int clear_undo);

void	sig_handler(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

void	ft_sig_handling(t_sig_handling_opcode opcode)
{
	struct termios			tty_attrs_new;
	static struct termios	tty_attrs_old;

	if (opcode == SIG_INITIAL)
	{
		tcgetattr(STDIN_FILENO, &tty_attrs_old);
		tty_attrs_new = tty_attrs_old;
		tty_attrs_new.c_lflag &= ~(ECHOCTL);
		tcsetattr(STDIN_FILENO, TCSANOW, &tty_attrs_new);
		signal(SIGINT, sig_handler);
		signal(SIGTERM, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
	}
	else
		tcsetattr(STDIN_FILENO, TCSANOW, &tty_attrs_old);
}

void	ctrl_d(char *str)
{
	if (str == NULL)
	{
		printf("exit\n");
		exit(0);
	}
}
