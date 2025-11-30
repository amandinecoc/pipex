# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amandine <amandine@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/23 21:53:09 by amandine          #+#    #+#              #
#    Updated: 2025/11/30 18:51:12 by amandine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_LIBFT:= libft.a
NAME := pipex

#Source#####################################
SOURCES_LIBFT += libft/ft_atoi.c
SOURCES_LIBFT += libft/ft_bzero.c
SOURCES_LIBFT += libft/ft_calloc.c
SOURCES_LIBFT += libft/ft_isalnum.c
SOURCES_LIBFT += libft/ft_isalpha.c
SOURCES_LIBFT += libft/ft_isascii.c
SOURCES_LIBFT += libft/ft_isdigit.c
SOURCES_LIBFT += libft/ft_isprint.c
SOURCES_LIBFT += libft/ft_memchr.c
SOURCES_LIBFT += libft/ft_memcmp.c
SOURCES_LIBFT += libft/ft_memcpy.c
SOURCES_LIBFT += libft/ft_memmove.c
SOURCES_LIBFT += libft/ft_memset.c
SOURCES_LIBFT += libft/ft_strchr.c
SOURCES_LIBFT += libft/ft_strdup.c
SOURCES_LIBFT += libft/ft_strlcat.c
SOURCES_LIBFT += libft/ft_strlcpy.c
SOURCES_LIBFT += libft/ft_strlen.c
SOURCES_LIBFT += libft/ft_strncmp.c
SOURCES_LIBFT += libft/ft_strnstr.c
SOURCES_LIBFT += libft/ft_tolower.c
SOURCES_LIBFT += libft/ft_toupper.c
SOURCES_LIBFT += libft/ft_strrchr.c
SOURCES_LIBFT += libft/ft_itoa.c
SOURCES_LIBFT += libft/ft_putchar_fd.c
SOURCES_LIBFT += libft/ft_putendl_fd.c
SOURCES_LIBFT += libft/ft_putnbr_fd.c
SOURCES_LIBFT += libft/ft_putstr_fd.c
SOURCES_LIBFT += libft/ft_split.c
SOURCES_LIBFT += libft/ft_striteri.c
SOURCES_LIBFT += libft/ft_strjoin.c
SOURCES_LIBFT += libft/ft_strmapi.c
SOURCES_LIBFT += libft/ft_strtrim.c
SOURCES_LIBFT += libft/ft_substr.c
SOURCES_LIBFT += libft/ft_atoll.c

SOURCES_PIPEX += pipex.c
SOURCES_PIPEX += parsing.c
SOURCES_PIPEX += error_handling.c

#Objets#####################################

OBJ := ft_atoi.o \
	ft_atoll.o \
	ft_bzero.o \
	ft_calloc.o \
	ft_isalnum.o \
	ft_isalpha.o \
	ft_isascii.o \
	ft_isdigit.o \
	ft_isprint.o \
	ft_itoa.o \
	ft_memchr.o \
	ft_memcmp.o \
	ft_memcpy.o \
	ft_memmove.o \
	ft_memset.o \
	ft_putchar_fd.o \
	ft_putendl_fd.o \
	ft_putnbr_fd.o \
	ft_putstr_fd.o \
	ft_split.o \
	ft_strchr.o \
	ft_strdup.o \
	ft_striteri.o \
	ft_strjoin.o \
	ft_strlcat.o \
	ft_strlcpy.o \
	ft_strlen.o \
	ft_strmapi.o \
	ft_strncmp.o \
	ft_strnstr.o \
	ft_strrchr.o \
	ft_strtrim.o \
	ft_substr.o \
	ft_tolower.o \
	ft_toupper.o
	
DIR = obj/

#Compilation################################
CC = cc

CFLAGS += -Werror
CFLAGS += -Wextra
CFLAGS += -Wall
CFLAGS += -g3

#Rules######################################
all:
	$(MAKE) all_libft
	$(MAKE) $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SOURCES_PIPEX) $(INCLUDES) $(INCLUDES_LIBFT) $(NAME_LIBFT) -o $(NAME)

clean: fclean_libft

fclean: clean
	rm -rf $(NAME)

re: fclean
	$(MAKE) all

all_libft: $(NAME_LIBFT)

$(NAME_LIBFT): $(SOURCES_LIBFT)
	mkdir ./obj/
	$(CC) $(CFLAGS) -c $(SOURCES_LIBFT) $(INCLUDES_LIBFT)
	ar rcs $(NAME_LIBFT) $(OBJ)
	mv $(OBJ) $(DIR) 

clean_libft:
	rm -rf obj

fclean_libft: clean_libft
	rm -rf $(NAME_LIBFT)

relibft: fclean_libft
	$(MAKE) all_libft

.PHONY : all re clean fclean fclean_libft clean_libft relibft all_libft