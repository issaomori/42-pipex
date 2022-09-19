# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gissao-m <gissao-m@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/24 12:22:25 by gissao-m          #+#    #+#              #
#    Updated: 2022/09/19 17:18:03 by gissao-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = cc
INCLUDE = -I ./include/
CFLAGS = -Wall -Werror -Wextra -g $(INCLUDE)

RM = rm -rf

PATH_SRC = ./src/
PATH_MAIN = $(PATH_SRC)main/
PATH_MY_FUNCS_AUX = $(PATH_SRC)my_funcs_aux/
PATH_OBJS = ./objs/

SRC =	$(PATH_MAIN)main.c\
		$(PATH_MAIN)ft_split.c\
		$(PATH_MAIN)libft_utils1.c\
		$(PATH_MAIN)libft_utils2.c\
		$(PATH_MAIN)find_cmd.c\
		$(PATH_MAIN)find_path.c\
		$(PATH_MAIN)process.c\

OBJS = $(patsubst $(PATH_SRC)%.c, $(PATH_OBJS)%.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS)  $(OBJS) -o $(NAME) $(MLXFLAGS)

$(PATH_OBJS)%.o: $(PATH_SRC)%.c
	@mkdir -p $(PATH_OBJS)
	@mkdir -p $(PATH_OBJS)main/
	@mkdir -p $(PATH_OBJS)my_funcs_aux/
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) ./objs

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all $(PATH_OBJS) clean fclean re