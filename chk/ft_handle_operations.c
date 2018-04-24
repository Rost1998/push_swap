/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 20:06:23 by rtulchiy          #+#    #+#             */
/*   Updated: 2018/01/31 19:04:42 by rtulchiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void		ft_check_op(t_list **stack_a, t_list **stack_b, char *op)
{
	int		exist;

	exist = 0;
	if ((!ft_strcmp(op, "sa") || !ft_strcmp(op, "ss")) && (exist = 1))
		o_swap(stack_a);
	if ((!ft_strcmp(op, "sb") || !ft_strcmp(op, "ss")) && (exist = 1))
		o_swap(stack_b);
	if (!ft_strcmp(op, "pa") && (exist = 1))
		o_push(stack_a, stack_b);
	else if (!ft_strcmp(op, "pb") && (exist = 1))
		o_push(stack_b, stack_a);
	if ((!ft_strcmp(op, "ra") || !ft_strcmp(op, "rr")) && (exist = 1))
		o_rotate(stack_a);
	if ((!ft_strcmp(op, "rb") || !ft_strcmp(op, "rr")) && (exist = 1))
		o_rotate(stack_b);
	if ((!ft_strcmp(op, "rra") || !ft_strcmp(op, "rrr")) && (exist = 1))
		o_rev_rotate(stack_a);
	if ((!ft_strcmp(op, "rrb") || !ft_strcmp(op, "rrr")) && (exist = 1))
		o_rev_rotate(stack_b);
	free(op);
	if (!exist)
		ft_error();
}

void			ft_handle_operations(t_list **stack_a, t_list **stack_b,\
														int fd, t_args *args)
{
	char	*op;
	int		n;

	if (args->vis)
		ft_visual(*stack_a, *stack_b, 0, args);
	n = 0;
	while (get_next_line(fd, &op) && ++n)
	{
		ft_check_op(stack_a, stack_b, op);
		if (args->vis)
			ft_visual(*stack_a, *stack_b, op, args);
	}
	close(fd);
}
