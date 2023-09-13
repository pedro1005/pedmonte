# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pedmonte <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/13 10:16:35 by pedmonte          #+#    #+#              #
#    Updated: 2023/06/13 10:16:40 by pedmonte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c print_c.c print_d.c print_p.c print_s.c print_u.c print_x.c print_X.c
LIBFT_SRC = ft_itoa.c

OBJS = ${SRC:.c=.o}

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
MAKE = make -C
LIBFT_PATH = libft
LIBFT = ${LIBFT_PATH}/libft.a

.o:.c
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		${MAKE} ${LIBFT_PATH} all
		cp ${LIBFT} ${NAME}
		ar rcs ${NAME} ${OBJS}

all:	${NAME}

clean:
		${MAKE} ${LIBFT_PATH} clean
		${RM} ${OBJS}

fclean: clean
		${MAKE} ${LIBFT_PATH} fclean
		${RM} ${NAME}
cc:
	cc ${CFLAGS} ${SRC} ${LIBFT_PATH}/${LIBFT_SRC}
	
re: fclean all
