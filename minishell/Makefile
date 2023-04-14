# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/18 16:22:50 by lbusi             #+#    #+#              #
#    Updated: 2023/04/14 18:18:51 by lbusi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		= minishell
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -rf
INCLUDE		= minishell.h
READLINE	= -lreadline -L$(HOME)/.brew/opt/readline/lib -I$(HOME)/.brew/opt/readline/include
SRCS		= main.c echo.c path.c parser.c env.c exit.c export.c signal.c quote_split.c utils.c utils2.c
OBJS		= ${SRCS:.c=.o}

%.o: %.c
	 $(CC) $(CFLAGS) -g -c $< -o ${<:.c=.o}

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I $(INCLUDE) $(OBJS) -o $@ $(READLINE)

all: $(NAME)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

leaks: all
	@leaks --atExit -- ./$(NAME)

.PHONY: all clean fclean re $(NAME)