/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_swap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 15:34:49 by rtulchiy          #+#    #+#             */
/*   Updated: 2018/01/31 19:04:59 by rtulchiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static t_list	*get_prelast_elem(t_list *lst)
{
	if (lst && lst->next)
		while (lst->next->next)
			lst = lst->next;
	return (lst);
}

void			o_swap(t_list **head)
{
	t_list		*sec_elem;

	if (head && *head && (*head)->next)
	{
		sec_elem = (*head)->next;
		(*head)->next = sec_elem->next;
		sec_elem->next = *head;
		*head = sec_elem;
	}
}

void			o_push(t_list **dst, t_list **src)
{
	t_list		*tmp_next_src;

	if (src && *src)
	{
		tmp_next_src = (*src)->next;
		ft_lstadd(dst, *src);
		*src = tmp_next_src;
	}
}

void			o_rotate(t_list **head)
{
	t_list		*tmp_first;
	t_list		*tmp_tail;

	if (head && *head && (*head)->next)
	{
		tmp_tail = get_prelast_elem(*head)->next;
		tmp_first = *head;
		*head = tmp_first->next;
		tmp_tail->next = tmp_first;
		tmp_first->next = 0;
	}
}

void			o_rev_rotate(t_list **head)
{
	t_list		*tmp_prelast;

	if (head && *head && (*head)->next)
	{
		tmp_prelast = get_prelast_elem(*head);
		tmp_prelast->next->next = *head;
		*head = tmp_prelast->next;
		tmp_prelast->next = 0;
	}
}
