/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_unsort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 17:43:18 by rtulchiy          #+#    #+#             */
/*   Updated: 2018/02/02 18:02:46 by rtulchiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_check_unsort(t_list *stack_a, t_list *stack_b)
{
	int		n;
	int		tmp;

	n = 0;
	tmp = 1;
	while (stack_a->next)
	{
		++tmp;
		if (ft_isbetween(stack_a, stack_b, *(int*)(stack_a->content),\
										*(int*)(stack_a->next->content)))
		{
			n += tmp;
			tmp = 0;
		}
		stack_a = stack_a->next;
	}
	return (n);
}
