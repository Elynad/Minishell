# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mameyer <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/18 12:11:53 by mameyer           #+#    #+#              #
#    Updated: 2017/08/24 23:11:18 by mameyer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC =	main.c \
		set_default_env.c \
		other.c \
		other_1.c \
		parsing_0.c \
		core.c \
		check_command.c \
		free.c \
		exit_command.c \
		env_command.c \
		unsetenv_command.c \
		setenv_command.c \
		cd_command.c \
		echo_command.c \
		errors.c \
		fork.c \
		shlvl_funcs.c \
		put_prompt.c \
		str_split.c \
		str_split_whitespaces.c

OBJ = $(SRC:.c=.o)

SRC_PATH = srcs/

SRC_POS = $(addprefix $(SRC_PATH),$(SRC))

INC = -I includes

LIBFT = libft/libft.a

CC = clang

FLAGS = -Wall -g -Wextra -Werror

all: $(NAME)

$(NAME):	$(OBJ) $(LIBFT)
			$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(LIBFT)

%.o :		$(SRC_PATH)/%.c
			$(CC) -o $@ -c $< $(FLAGS)

$(LIBFT):
			make -C ./libft/

clean:
			rm -rf $(OBJ)
			make clean -C ./libft/

fclean:		clean
			rm -rf $(NAME)
			make fclean -C ./libft/

re:			fclean all

.PHONY : all re clean fclean
