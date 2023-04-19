/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:50:28 by lbusi             #+#    #+#             */
/*   Updated: 2023/04/19 16:47:47 by lbusi            ###   ########.fr       */
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
	struct s_data	*t;
}t_input;

typedef struct s_data
{
	int			i;
	int			x;
	int			y;
	int			z;
	int			cmd;
	int			flag;
	int			quotes;
	int			apici;
	int			closed;
	char		*parsed;
	char		*command;
	char		**matrix;
	char		*path;
	char		**my_env;
	t_input		*input;
}t_data;

size_t		ft_strlen(const char *str);
size_t		word_count(char const *s, char c, t_data *t);
int			ft_atoi(const char *str);
int			count_env(char **env);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			index_finder(char *str);
int			check_dollar(char *str);
void		unparser(t_data *t);
int			env_strncmp(const char *s1, const char *s2, size_t n, int j);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		**ft_split(char const *s, char c, t_data *t);
void		ft_free(t_data *t);
void		pwd(t_data *t);
void		cd(t_data *t);
int			find_dollar(t_data *t, char *str);
void		check_env_value(t_data *t, char *str, int len);
void		expander(t_data *t, char *str, int i);
void		echo(t_data *t);
void		check_echo(t_data *t);
void		check_cmd(t_data *t);
void		ft_env(char **env);
void		ft_export(char **env);
void		command_into_parsed(t_data *t, char *tmp_command);
void		ft_exit(t_data *t);
void		create_env(t_data *t, char **env);
void		echo_flag(t_data *t);
void		sig_handler(int sig);
void		ctrl_d(t_data *t);
void		ft_print_matrix(t_data *t);
void		struct_init(t_data *t);
void		apici_quotes(t_data *t);
extern void	rl_replace_line(const char *text, int clear_undo);
void		ft_sig_handling(t_sig_handling_opcode opcode);
void		quote_counter(char *s, t_data *t);
void		echo_component_one(t_data *t);
void		echo_component_two(t_data *t);

#endif