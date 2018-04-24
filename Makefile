# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/18 20:25:03 by rtulchiy          #+#    #+#              #
#    Updated: 2018/02/03 12:46:25 by rtulchiy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PSDIR = ps
CHECKERDIR = chk

all:
	make -C $(PSDIR)
	make -C $(CHECKERDIR)
	mv ./$(PSDIR)/push_swap ./
	mv ./$(CHECKERDIR)/checker ./

clean:
	make clean -C $(PSDIR)
	make clean -C $(CHECKERDIR)
fclean: clean
	rm -f push_swap checker
	make fclean -C libft
re: fclean all
