# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aflorido <aflorido@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/26 03:30:33 by aflorido          #+#    #+#              #
#    Updated: 2023/07/27 02:04:40 by aflorido         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
# ar -> create or maintain library archives
# -r -> replace or add
# -c -> expect to create archive (to avoid warnings)
LIBC	= ar -rcs
LIBR	= ranlib
NAME	= libft.a
SRCS	= srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c srcs/ft_swap.c
OBJS	= ${SRCS:.c=.o}
INCS	= includes
RM		= rm -f

# Pattern rule to compile every .c file into a .o file
# $< -> prerequisite name
# $@ -> target name
.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I${INCS}

all: ${OBJS}
	${LIBC} ${NAME} ${OBJS}
	${LIBR} ${NAME}

${NAME}: all

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: .c.o all clean fclean re
