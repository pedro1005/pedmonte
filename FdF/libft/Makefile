# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pedmonte <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/30 12:19:46 by pedmonte          #+#    #+#              #
#    Updated: 2023/04/30 12:28:24 by pedmonte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Define o nome do arquivo de saída (biblioteca estática)
NAME=libft.a

# Define o compilador e suas flags de compilação
CC=cc
CFLAGS=-Wall -Wextra -Werror

# Define o comando para criar arquivos de biblioteca estática
AR=ar
ARFLAGS=rc

# Define o comando para remover arquivos
RM=rm -f

# Lista dos arquivos fonte da biblioteca
SRCS= ft_atoi.c \
      ft_bzero.c \
      ft_calloc.c \
      ft_isalnum.c \
      ft_isalpha.c \
      ft_isascii.c \
      ft_isdigit.c \
      ft_isprint.c \
      ft_itoa.c \
      ft_memchr.c \
      ft_memcmp.c \
      ft_memcpy.c \
      ft_memmove.c \
      ft_memset.c \
      ft_putchar_fd.c \
      ft_putendl_fd.c \
      ft_putnbr_fd.c \
      ft_putstr_fd.c \
      ft_split.c \
      ft_strchr.c \
      ft_strdup.c \
      ft_strjoin.c \
      ft_strlcat.c \
      ft_strlcpy.c \
      ft_strmapi.c \
      ft_strncmp.c \
      ft_strnstr.c \
      ft_strrchr.c \
      ft_strtrim.c \
      ft_substr.c \
      ft_toupper.c \
      ft_tolower.c \
      ft_striteri.c \
      get_next_line.c \
      get_next_line_utils.c \

# Lista dos arquivos fonte do bonus da biblioteca
BONUS_SRCS	=	ft_lstadd_back.c \
				ft_lstadd_front.c \
				ft_lstclear.c \
				ft_lstdelone.c \
				ft_lstiter.c \
				ft_lstlast.c \
				ft_lstmap.c \
				ft_lstnew.c \
				ft_lstsize.c \

# Cria uma lista de arquivos objetos (binários) para a biblioteca
OBJS		=	$(SRCS:.c=.o)

# Cria uma lista de arquivos objetos (binários) para o bonus da biblioteca
BONUS_OBJS	=	$(BONUS_SRCS:.c=.o)

# Target "all" que compila o programa principal (biblioteca estática)
all: $(NAME)

# Regra para criar a biblioteca estática (arquivo .a)
$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

# Target "bonus" que compila a biblioteca com os arquivos bônus
bonus: $(OBJS) $(BONUS_OBJS)
	$(AR) $(ARFLAGS) $(NAME) $^

# Regra genérica para compilar qualquer arquivo fonte .c em um arquivo objeto .o
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< -fPIE

# Target "clean" para remover os arquivos objetos
clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

# Target "fclean" para remover os arquivos objetos e a biblioteca estática
fclean: clean
	$(RM) $(NAME)

# Target "re" que reconstrói todo o projeto do zero
re: fclean all
