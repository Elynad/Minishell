# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mameyer <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/26 14:28:11 by mameyer           #+#    #+#              #
#    Updated: 2017/07/27 23:18:47 by mameyer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		minishell

SRC =		main.c \
			get_env.c \
			free.c \
			print.c \
			core.c \
			get_command.c \
			check_commands.c \
			builtins.c \
			set_env.c \
			unset_env.c \
			change_directory.c

OBJ =		$(SRC:.c=.o)

SRC_PATH =	srcs/

SRC_POS =	$(addprefix $(SRC_PATH),$(SRC))

INC =		-I includes

LIBFT =		libft/libft.a

CC =		clang

FLAGS =		-Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(OBJ) $(LIBFT)
			$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(LIBFT)

%.o:		$(SRC_PATH)/%.c
			$(CC) -o $@ -c $< $(FLAGS)

$(LIBFT):
			make -C ./libft/

clean:
			rm -rf $(OBJ)

fclean:		clean
			rm -rf $(NAME)
			make fclean -C ./libft/

re:			fclean all

.PHONY : all re clean fclean
