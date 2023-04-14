/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:03:55 by lbusi             #+#    #+#             */
/*   Updated: 2023/03/23 16:36:54 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit(t_data *t)
{
	int	status;

	printf("%s\n", t->matrix[1]);
	if (t->matrix[1])
	{
		status = ft_atoi(t->matrix[1]);
		write (1, "exit\n", 5);
		exit (status);
	}
	else
	{
		write (1, "exit\n", 5);
		exit (0);
	}
}
