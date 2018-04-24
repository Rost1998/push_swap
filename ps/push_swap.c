/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 18:21:47 by rtulchiy          #+#    #+#             */
/*   Updated: 2018/02/04 15:05:16 by rtulchiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_vars	*ft_create_vars(t_list *stack_a)
{
	t_vars		*new;
	size_t		size;

	size = ft_lstlen(stack_a) * 20;
	if (!(new = (t_vars*)ft_memalloc(sizeof(t_vars))))
		ft_error_memory();
	if (!(new->opers = (char**)ft_memalloc(size * sizeof(char*))))
		ft_error_memory();
	if (!(new->parts_a = (int*)ft_memalloc(sizeof(int))))
		ft_error_memory();
	if (!(new->parts_b = (int*)ft_memalloc(ft_lstlen(stack_a) * sizeof(int))))
		ft_error_memory();
	new->index = 0;
	new->need_rev = 0;
	new->piv = 0;
	return (new);
}

static void		ft_sort(t_list **stack_a, t_list **stack_b, t_vars *vars)
{
	int		len;
	int		n;

	n = 1;
	len = ft_lstlen(*stack_a);
	if (len <= 6)
		while (!ft_backtrack(stack_a, n, vars, 0))
			++n;
	else
	{
		(vars->parts_a)[0] = ft_lstlen(*stack_a);
		ft_qsort(stack_a, stack_b, vars);
	}
	ft_cleanopers(vars);
}

static void		ft_print_ops(char **ops)
{
	while (*ops)
		ft_putstr(*(ops)++);
}

static void		ft_memfree(t_list *stack_a, t_list *stack_b, t_vars *vars)
{
	int		i;
	t_list	*tmp;

	i = 0;
	while ((vars->opers)[i])
		free((vars->opers)[i++]);
	free(vars->opers);
	free(vars->parts_a);
	free(vars->parts_b);
	free(vars);
	while (stack_a)
	{
		tmp = stack_a;
		stack_a = stack_a->next;
		free(tmp->content);
		free(tmp);
	}
	while (stack_b)
	{
		tmp = stack_b;
		stack_b = stack_b->next;
		free(tmp->content);
		free(tmp);
	}
}

int				main(int argc, char **argv)
{
	t_vars		*vars;
	t_list		*stack_a;
	t_list		*stack_b;
	char		**av;

	if (argc < 2)
		return (0);
	else if (argc == 2)
		av = ft_strsplit(*(argv + 1), ' ');
	else
		av = argv + 1;
	stack_b = 0;
	ft_validator(av);
	ft_create_stack(av, &stack_a);
	vars = ft_create_vars(stack_a);
	ft_sort(&stack_a, &stack_b, vars);
	ft_print_ops(vars->opers);
	ft_memfree(stack_a, stack_b, vars);
	return (0);
}
