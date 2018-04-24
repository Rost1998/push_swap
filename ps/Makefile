# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/18 20:25:03 by rtulchiy          #+#    #+#              #
#    Updated: 2018/02/04 14:20:40 by rtulchiy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJ = push_swap.o ft_backtrack.o ft_check.o ft_cleanopers.o ft_create_stack.o\
	  ft_error.o ft_error_memory.o ft_lstlen.o ft_qsort.o ft_strcmp.o\
	  ft_validator.o get_median.o o_operations.o o_pushing.o\
	  service_funcs.o useful.o check_unsort.o service2_funcs.o

INCLUDES = push_swap.h libft.h
NAME = push_swap
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
