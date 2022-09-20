# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gissao-m <gissao-m@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/24 12:22:25 by gissao-m          #+#    #+#              #
#    Updated: 2022/09/20 11:14:32 by gissao-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = cc
INCLUDE = -I ./include/
CFLAGS = -Wall -Werror -Wextra -g $(INCLUDE)

RM = rm -rf

PATH_SRC = ./src/
PATH_MAIN = $(PATH_SRC)main/
PATH_UTILS = $(PATH_SRC)utils/
PATH_PATHS = $(PATH_SRC)paths/
PATH_PROCESS = $(PATH_SRC)process/
PATH_OBJS = ./objs/

SRC =	$(PATH_MAIN)main.c\
		$(PATH_UTILS)ft_split.c\
		$(PATH_UTILS)libft_utils1.c\
		$(PATH_UTILS)libft_utils2.c\
		$(PATH_PATHS)find_cmd.c\
		$(PATH_PATHS)find_the_path.c\
		$(PATH_PROCESS)process.c

OBJS = $(patsubst $(PATH_SRC)%.c, $(PATH_OBJS)%.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS)  $(OBJS) -o $(NAME) $(MLXFLAGS)

$(PATH_OBJS)%.o: $(PATH_SRC)%.c
	@mkdir -p $(PATH_OBJS)
	@mkdir -p $(PATH_OBJS)main/
	@mkdir -p $(PATH_OBJS)utils/
	@mkdir -p $(PATH_OBJS)paths/
	@mkdir -p $(PATH_OBJS)process/
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) ./objs

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all $(PATH_OBJS) clean fclean re