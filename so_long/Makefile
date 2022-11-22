# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aliburdi <aliburdi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/30 15:54:27 by aliburdi          #+#    #+#              #
#    Updated: 2022/11/22 16:46:43 by aliburdi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long
SRCS	=	./get_next_line/get_next_line_utils.c \
			./get_next_line/get_next_line.c \
			so_long.c map.c matrix.c utils.c \
			player_movement.c collisions.c \
			enemy_movement.c ft_itoa.c \
			animations.c ft_strcmp.c
			

OBJS	=	$(patsubst %.c, %.o, $(SRCS))
OBJS_B	=	$(patsubst %.c, %.o, $(SRCS_B))
CC		=	gcc
FLAGS	=	-g -Wall -Wextra -Werror
MINILIBX	=	-lmlx -framework OpenGL -framework AppKit
all: $(NAME)
$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(MINILIBX) $(OBJS) -o $(NAME)
%.o: %.c
	$(CC) $(FLAGS) -c $<  -o $@
clean:
	rm -f $(OBJS) $(OBJS_B)
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re bonus

# NAME	=	so_long

# CC		=	gcc
# CFLAGS	=	-Wall -Wextra -Werror -g

# SL_SRC	= so_long.c move_counter.c so_long.h

# SL_OBJ	= $(SL_SRC:.c=.o)

# %.o: %.c
# 		$(CC) ${CFLAGS} -g -c $< -o $@

# MLX		= -lmlx -framework OpenGL -framework AppKit

# RM		= rm -fr

# $(NAME):	$(SL_OBJ)
# 				@(test -f $(MLX)  && echo "\033[32mMLX already built\033[0m") || (make -C ./mlx && mv mlx/libmlx.dylib .)
# 				$(CC) $(CFLAGS) -o $(NAME) $(SL_OBJ) $(MLX)
# 				@(echo "\033[32mSO_LONG>> Compiled\033[0m")

# all:		$(NAME)
 
# norme:
# 		@norminette $(SL_SRC)

# clean:
# 			make clean -C mlx
# 			rm -f *.o
# 			rm -f ./*/*.o
# 			@echo "\033[33mSO_LONG>> Deleted \".o\" files\033[0m"

# fclean:		clean
# 			rm -rf $(NAME)
# 			@echo "\033[33mSO_LONG>> Project cleaned\033[0m"

# re:			fclean all
# 			@echo "\033[0;92mSO_LONG>> Project cleaned and recompiled\033[0m"

# re.all:		fclean

# .PHONY:		all clean fclean re