# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acocoual <acocoual@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/22 20:26:37 by amandine          #+#    #+#              #
#    Updated: 2025/09/25 13:44:09 by acocoual         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS += ft_atoi.c
SRCS += ft_bzero.c
SRCS += ft_calloc.c
SRCS += ft_isalnum.c
SRCS += ft_isalpha.c
SRCS += ft_isascii.c
SRCS += ft_isdigit.c
SRCS += ft_isprint.c
SRCS += ft_memchr.c
SRCS += ft_memcmp.c
SRCS += ft_memcpy.c
SRCS += ft_memmove.c
SRCS += ft_memset.c
SRCS += ft_strchr.c
SRCS += ft_strdup.c
SRCS += ft_strlcat.c
SRCS += ft_strlcpy.c
SRCS += ft_strlen.c
SRCS += ft_strncmp.c
SRCS += ft_strnstr.c
SRCS += ft_tolower.c
SRCS += ft_toupper.c
SRCS += ft_strrchr.c
SRCS += ft_itoa.c
SRCS += ft_putchar_fd.c
SRCS += ft_putendl_fd.c
SRCS += ft_putnbr_fd.c
SRCS += ft_putstr_fd.c
SRCS += ft_split.c
SRCS += ft_striteri.c
SRCS += ft_strjoin.c
SRCS += ft_strmapi.c
SRCS += ft_strtrim.c
SRCS += ft_substr.c
SRCS += ft_atoll.c

NAME := libft.a

CC := cc

CFLAGS += -Wall
CFLAGS += -Werror
CFLAGS += -Wextra

AR := ar

ARFLAGS := rcs

OBJS := $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re