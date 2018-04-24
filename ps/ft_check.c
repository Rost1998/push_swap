/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 15:21:45 by rtulchiy          #+#    #+#             */
/*   Updated: 2017/12/26 17:32:40 by rtulchiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

_Bool		ft_check_sort(t_list *stack_a, t_list *stack_b)
{
	int		prev_num;

	if (stack_b || !stack_a)
		return (FALSE);
	prev_num = *(int*)(stack_a->content);
	stack_a = stack_a->next;
	while (stack_a)
	{
		if (*(int*)(stack_a->content) < prev_num)
			return (FALSE);
		prev_num = *(int*)(stack_a->content);
		stack_a = stack_a->next;
	}
	return (TRUE);
}
