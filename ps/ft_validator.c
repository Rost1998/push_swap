/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 15:45:42 by rtulchiy          #+#    #+#             */
/*   Updated: 2018/01/27 14:28:34 by rtulchiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static _Bool	ft_isnumber(char *num)
{
	if (*num == '-')
		++num;
	while (*num)
		if (!ft_isdigit(*num++))
			return (FALSE);
	return (*(num - 1) == '-' ? FALSE : TRUE);
}

static _Bool	ft_isduplicates(char *num, char **av, size_t index)
{
	size_t		i;

	i = 0;
	while (i < index)
		if (!ft_strcmp(num, av[i++]))
			return (TRUE);
	return (FALSE);
}

static _Bool	ft_isbiggerint(char *num)
{
	_Bool	neg;
	size_t	len;

	neg = *num == '-' ? TRUE && ++num : 0;
	len = ft_strlen(num);
	if (len == 10)
	{
		if (neg && ft_strcmp(num, "2147483648") > 0)
			return (TRUE);
		else if (!neg && ft_strcmp(num, "2147483647") > 0)
			return (TRUE);
	}
	else if (len > 10)
		return (TRUE);
	return (FALSE);
}

void			ft_validator(char **av)
{
	char	**tmp;
	size_t	i;

	i = 0;
	tmp = av;
	while (*av && ++i)
	{
		if (!ft_isnumber(*av) || ft_isduplicates(*av, tmp, i - 1) ||
				ft_isbiggerint(*av))
			ft_error();
		av++;
	}
}
