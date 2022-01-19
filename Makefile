# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phaslan <phaslan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/17 18:38:16 by phaslan           #+#    #+#              #
#    Updated: 2022/01/18 20:34:51 by phaslan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
FLAGS = -Llibft -lft -Lminilibx -lmlx -framework OpenGL -framework AppKit
RM = rm -f

GAME_FILES = render \
	     movement \
	     game_start \
	     main \

MAP_FILES = get_map \
		is_map_valid \
		map_utils \
		read_map \

GNL_FILES = get_next_line \
	    get_next_line_utils \

LIBFT_DIR = libft/
GNL_DIR = gnl/
MAP_DIR = map/
GAME_SRCS = $(addsuffix .c, $(GAME_FILES)) \
	$(addprefix $(GNL_DIR), $(addsuffix .c, $(GNL_FILES))) \
	$(addprefix $(MAP_DIR), $(addsuffix .c, $(MAP_FILES))) \

OBJS =	$(addsuffix .o, $(GAME_FILES)) \
	$(addprefix $(GNL_DIR), $(addsuffix .o, $(GNL_FILES))) \
	$(addprefix $(MAP_DIR), $(addsuffix .o, $(MAP_FILES))) \

.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	make -C libft
	make -C minilibx
	$(CC) $(CFLAGS) -o $@ $^ $(FLAGS)

all: $(NAME)

clean:
	make clean -C libft
	$(RM) $(OBJS)

fclean: clean
	make fclean -C libft
	$(RM) $(NAME)

norminette:
	norminette $(addsuffix .c, $(GAME_FILES)) $(LIBFT_DIR) $(GNL_DIR) $(MAP_DIR) so_long.h

re: clean all

.PHONY: bonus all clean fclean re