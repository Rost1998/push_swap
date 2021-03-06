/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 13:51:36 by rtulchiy          #+#    #+#             */
/*   Updated: 2018/01/31 19:04:48 by rtulchiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

size_t		ft_lstlen(t_list *lst)
{
	size_t		len;

	len = 0;
	while (lst && ++len)
		lst = lst->next;
	return (len);
}
