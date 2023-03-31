/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:50:28 by lbusi             #+#    #+#             */
/*   Updated: 2023/03/31 14:32:38 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>
# include <signal.h>
# include <string.h>
# include <termios.h>

typedef enum e_sig_handling_opcode
{
	SIG_INITIAL,
	SIG_AT_EXIT
}	t_sig_handling_opcode;

typedef struct s_input
{
	// int				cmd;
	struct s_data	*t;
}t_input;

typedef struct s_data
{
	int			i;
	int			cmd;
	int			flag;
	char		*command;
	char		**matrix;
	char		*path;
	char		**save_env;
	t_input		*input;
}t_data;

size_t		ft_strlen(const char *str);
size_t		word_count(char const *s, char c);
int			ft_atoi(const char *str);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		**ft_split(char const *s, char c);
void		ft_free(t_data *t);
void		pwd(t_data *t);
void		cd(t_data *t);
void		echo(t_data *t);
void		check_echo(t_data *t);
void		check_cmd(t_data *t);
void		ft_env(char **env);
void		ft_export(char **env);
void		ft_exit(t_data *t);
void		echo_flag(t_data *t);
void		sig_handler(int sig);
extern void	rl_replace_line(const char *text, int clear_undo);
void		ft_sig_handling_set(t_sig_handling_opcode opcode);

#endif