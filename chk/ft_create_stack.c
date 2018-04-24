/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 17:39:22 by rtulchiy          #+#    #+#             */
/*   Updated: 2018/02/01 19:14:11 by rtulchiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		ft_create_stack(char **av, t_list **stack_a)
{
	t_list		*stack_head_tmp;
	void		*content;

	if (!(content = ft_memalloc(sizeof(int))))
		ft_error();
	stack_head_tmp = 0;
	while (*av)
	{
		*((int*)content) = ft_atoi(*av++);
		ft_lstadd(&stack_head_tmp, ft_lstnew(content, sizeof(int)));
	}
	free(content);
	*stack_a = 0;
	while (stack_head_tmp)
		o_push(stack_a, &stack_head_tmp);
}
