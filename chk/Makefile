# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/18 20:25:03 by rtulchiy          #+#    #+#              #
#    Updated: 2018/02/04 19:37:29 by rtulchiy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJ = checker.o ft_create_stack.o ft_handle_operations.o ft_check.o\
	  ft_validator.o ft_error.o o_operations.o get_next_line2.o ft_handle_args.o\
	  ft_error_invalid.o ft_lstlen.o visual.o

INCLUDES = checker.h get_next_line.h libft.h
NAME = checker
CFLAGS = -Wall -Wextra -Werror
LIBFT = ../libft

%.o: %.c
	gcc -c $< -I ../includes

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT)
	gcc $(CFLAGS) -o $(NAME) $(OBJ) -L$(LIBFT) -lft -I ../includes
clean:
	make clean -C $(LIBFT)
	rm -f $(OBJ)
fclean: clean
	make fclean -C $(LIBFT)
	rm -f $(NAME)
re: fclean all
