# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/17 17:08:47 by lbusi             #+#    #+#              #
#    Updated: 2023/03/17 17:17:17 by lbusi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SRC = 	main.c eat.c room.c routine.c utils.c \


OBJS = ${SRC:.c=.o}

%.o: %.c
		 $(CC) $(CFLAGS) -g -c $< -o ${<:.c=.o}

CC				= gcc
RM				= rm -rf
CFLAGS = -Wall -Wextra -Werror

$(NAME): ${OBJS}
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
all:	${NAME}

clean:
				${RM} ${OBJS}

fclean: clean
				${RM} ${NAME}
re:				fclean all

.PHONY: clean fclean re bonus