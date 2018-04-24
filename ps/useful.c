/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 13:29:02 by rtulchiy          #+#    #+#             */
/*   Updated: 2018/02/02 18:48:11 by rtulchiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_count_useful(t_list **stack, int piv, _Bool code)
{
	int		n;

	n = 0;
	while (*stack)
	{
		if (!code && *(int*)((*stack)->content) <= piv)
			++n;
		else if (code && *(int*)((*stack)->content) > piv)
			++n;
		else
			return (-1);
		*stack = (*stack)->next;
	}
	return (n);
}

static int	ft_count_unuseful(t_list **stack, int piv, _Bool code)
{
	int		n;

	n = 0;
	while (*stack)
	{
		if (!code && *(int*)((*stack)->content) > piv)
			++n;
		else if (code && *(int*)((*stack)->content) <= piv)
			++n;
		else
			break ;
		*stack = (*stack)->next;
	}
	return (n);
}

_Bool		ft_isuseful_rrr(t_list *stack, int piv, _Bool code)
{
	int		unusfl;
	int		usfl;

	while (stack)
	{
		unusfl = ft_count_unuseful(&stack, piv, code);
		usfl = ft_count_useful(&stack, piv, code);
	}
	if (unusfl > usfl)
		return (1);
	else
		return (0);
}
