/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 13:12:44 by rtulchiy          #+#    #+#             */
/*   Updated: 2018/01/31 19:17:42 by rtulchiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int		ft_check_pos_num(t_list *stack, char *op)
{
	int		nn;

	if (op[0] == 's')
		nn = 2;
	else if (op[0] == 'p' || op[1] == 'r')
		nn = 1;
	else if (op[0] == 'r')
		nn = ft_lstlen(stack);
	return (nn);
}

static void		psa(t_list *stack_a, char *op, t_args *args)
{
	int		n;
	int		flag;

	write(1, "(A)>> : ", 8);
	n = 0;
	flag = -1;
	if (args->color && op && op[ft_strlen(op) - 1] == 'a')
		flag = ft_check_pos_num(stack_a, op);
	while (stack_a && ++n)
	{
		if (args->color && n == flag)
			write(1, "\033[035m", 6);
		ft_putnbr(*(int*)(stack_a->content));
		if (args->color && n == flag)
			write(1, "\033[0m", 4);
		stack_a = stack_a->next;
		if (stack_a)
			write(1, " ! ", 3);
	}
	write(1, "\n", 1);
}

static void		psb(t_list *stack_b, char *op, t_args *args)
{
	int		n;
	int		flag;

	write(1, "(B)>> : ", 8);
	n = 0;
	flag = -1;
	if (args->color && op && op[ft_strlen(op) - 1] == 'b')
		flag = ft_check_pos_num(stack_b, op);
	while (stack_b && ++n)
	{
		if (args->color && n == flag)
			write(1, "\033[035m", 6);
		ft_putnbr(*(int*)(stack_b->content));
		if (args->color && n == flag)
			write(1, "\033[0m", 4);
		stack_b = stack_b->next;
		if (stack_b)
			write(1, " ! ", 3);
	}
	write(1, "\n\n", 2);
}

void			ft_visual(t_list *stack_a, t_list *stack_b, char *op,\
															t_args *args)
{
	if (args->ops && op)
	{
		write(1, "\033[033m", 6);
		ft_putstr(op);
		write(1, "\033[0m\n", 5);
	}
	psa(stack_a, op, args);
	psb(stack_b, op, args);
}
