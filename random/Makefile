# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/18 20:25:03 by rtulchiy          #+#    #+#              #
#    Updated: 2018/01/29 19:03:03 by rtulchiy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJ = random.o ft_memalloc.o ft_putnbr.o ft_iswhitespaces.o ft_atoi.o\
	  service.o

NAME = rand
CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	gcc -c $<

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(CFLAGS) -o $(NAME) $(OBJ)
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all
