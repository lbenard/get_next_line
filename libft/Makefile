# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbenard <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/05 18:02:14 by lbenard           #+#    #+#              #
#    Updated: 2018/11/18 08:17:35 by lbenard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a
SRC			=	ft_memset.c			\
				ft_bzero.c			\
				ft_memcpy.c			\
				ft_memccpy.c		\
				ft_memmove.c		\
				ft_memchr.c			\
				ft_memcmp.c			\
				ft_strlen.c			\
				ft_strdup.c			\
				ft_strcpy.c			\
				ft_strncpy.c		\
				ft_strcat.c			\
				ft_strncat.c		\
				ft_strlcat.c		\
				ft_strchr.c			\
				ft_strrchr.c		\
				ft_strstr.c			\
				ft_strnstr.c		\
				ft_strcmp.c			\
				ft_strncmp.c		\
				ft_atoi.c			\
				ft_isalpha.c		\
				ft_isdigit.c		\
				ft_isalnum.c		\
				ft_isascii.c		\
				ft_isprint.c		\
				ft_toupper.c		\
				ft_tolower.c		\
				ft_memalloc.c		\
				ft_memdel.c			\
				ft_strnew.c			\
				ft_strdel.c			\
				ft_strclr.c			\
				ft_striter.c		\
				ft_striteri.c		\
				ft_strmap.c			\
				ft_strmapi.c		\
				ft_strequ.c			\
				ft_strnequ.c		\
				ft_strsub.c			\
				ft_strjoin.c		\
				ft_strtrim.c		\
				ft_strsplit.c		\
				ft_itoa.c			\
				ft_putchar.c		\
				ft_putstr.c			\
				ft_putendl.c		\
				ft_putnbr.c			\
				ft_putchar_fd.c		\
				ft_putstr_fd.c		\
				ft_putendl_fd.c		\
				ft_putnbr_fd.c		\
				ft_lstnew.c			\
				ft_lstdelone.c		\
				ft_lstdel.c			\
				ft_lstadd.c			\
				ft_lstiter.c		\
				ft_lstmap.c			\
				ft_strndup.c		\
				ft_isspace.c		\
				ft_isupper.c		\
				ft_islower.c		\
				ft_strnlen.c		\
				ft_abs.c			\
				ft_min.c			\
				ft_max.c			\
				ft_nblen.c			\
				ft_lststrjoin.c		\
				ft_lstfind.c		\
				ft_lstpushback.c	\
				ft_lstlast.c		\
				ft_lstfree.c
OBJ			=	$(SRC:.c=.o)
SRC_FOLDER	=	./
INCLUDES	=	./
FLAGS		=	-Wall -Wextra -Werror
NORM_FILES	=	$(shell find . -name "*.c" -o -name "*.h")

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[32m  Creating: \033[0m$(NAME)"
	@ar rcs $(NAME) $(OBJ)

.c.o: $(SRC)
	@printf "\033[32m Compiling: \033[0m$< -> $@\n"
	@gcc -c $< -o $@ -I $(INCLUDES) $(FLAGS)

norm:
	@printf "\033[32mNorminette:\033[0m "
	@if ! norminette $(NORM_FILES) | grep -sB1 -E "Error|Warning";then echo "\033[0mEvery file is following the norm";fi

clean:
	@printf "\033[32m  Cleaning: \033[0m"
	@find . -name "*.o" -exec sh -c 'basename {}' \; | tr "\n" " "
	@echo ""
	@rm -rf $(OBJ)

fclean: clean
	@printf "\033[32m  Removing: \033[0m"
	@find . -name "libft.a" -exec sh -c 'basename {}' \; | tr "\n" " "
	@echo ""
	@rm -rf $(NAME)

re: fclean all
