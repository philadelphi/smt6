# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phaslan <phaslan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/17 18:38:16 by phaslan           #+#    #+#              #
#    Updated: 2022/01/18 16:56:08 by phaslan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CFLAG = -Wextra -Wall -Werror

SRCS = 	ft_isalnum.c    ft_isspace.c    ft_memcpy.c     ft_putnbr_fd.c  ft_strjoin.c    ft_strncmp.c    ft_tolower.c \
		ft_isalpha.c    ft_itoa.c       ft_memmove.c    ft_putstr_fd.c  ft_strlcat.c    ft_strnstr.c    ft_toupper.c		\
		ft_atoi.c       ft_isascii.c    ft_memccpy.c    ft_memset.c     ft_split.c      ft_strlcpy.c    ft_strrchr.c    	\
		ft_bzero.c      ft_isdigit.c    ft_memchr.c     ft_putchar_fd.c ft_strchr.c     ft_strlen.c     ft_strtrim.c    	\
		ft_calloc.c     ft_isprint.c    ft_memcmp.c     ft_putendl_fd.c ft_strdup.c     ft_strmapi.c    ft_substr.c	     	\
		ft_checkext.c	ft_error.c \

OBJ = ${SRCS:.c=.o}

all	: ${NAME}

$(NAME):
	gcc ${CFLAG} -c ${SRCS}
	ar rc ${NAME} ${OBJ}

clean :
	rm -f ${OBJ}

fclean : clean
	rm -f ${NAME}

re: clean all
