/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_median.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 14:20:58 by rtulchiy          #+#    #+#             */
/*   Updated: 2018/02/02 12:30:13 by rtulchiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	compare(t_list *stack, int len, int num, _Bool code)
{
	int		less;
	int		greater;

	less = 0;
	greater = 0;
	while (stack && len--)
	{
		if (*(int*)(stack->content) > num)
			++greater;
		else if (*(int*)(stack->content) < num)
			++less;
		stack = stack->next;
	}
	if (!code)
		return (less);
	else
		return (greater);
}

int			ft_getmed(t_list *stack, int len)
{
	t_list	*head;
	int		lss;
	int		grt;
	int		res;
	int		i;

	head = stack;
	i = len;
	res = 0;
	while (stack && i--)
	{
		lss = compare(head, len, *(int*)(stack->content), 0);
		grt = compare(head, len, *(int*)(stack->content), 1);
		if (!(len % 2) && grt == lss + 1)
			res = *(int*)(stack->content);
		else if (len % 2 && lss == grt)
			res = *(int*)(stack->content);
		stack = stack->next;
	}
	return (res);
}
