/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:06:25 by lbusi             #+#    #+#             */
/*   Updated: 2022/12/05 10:06:43 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handler(int sig, siginfo_t *info, void *a)
{
	static unsigned char	c = 0;
	static unsigned int		i = 0;
	pid_t					send_pid;

	send_pid = info->si_pid;
	c = c | (sig == SIGUSR1);
	if (++i == 8)
	{
		i = 0;
		write(1, &c, 1);
		if (c == '\n')
			kill(send_pid, SIGUSR1);
		c = 0;
	}
	else
		c = c << 1;
	(void)a;
}

int	main(void)
{
	struct sigaction	ft_sig;

	ft_sig.sa_sigaction = sig_handler;
	ft_sig.sa_flags = SA_SIGINFO;
	ft_putstr_fd("PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	sigaction(SIGUSR1, &ft_sig, 0);
	sigaction(SIGUSR2, &ft_sig, 0);
	while (1)
		pause();
	return (0);
}
