/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   service.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 17:55:17 by rtulchiy          #+#    #+#             */
/*   Updated: 2018/01/31 18:41:07 by rtulchiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rand.h"

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void		error_invalid_nums_args(void)
{
	write(2, "Invalid number of arguments.\n", 29);
	exit(1);
}

void		check_valid_num(char *num)
{
	if (!ft_isnumber(num))
	{
		write(1, "Error: not a number.\n", 21);
		exit(1);
	}
}

int			*create_nums(int size)
{
	int		*nums;

	if (!(nums = (int*)ft_memalloc((size + 1) * sizeof(int))))
	{
		write(1, "Memory allocate error.\n", 22);
		exit(1);
	}
	while (size)
	{
		nums[size - 1] = size;
		--size;
	}
	return (nums);
}

_Bool		ft_isnumber(char *num)
{
	if (*num == '-')
		++num;
	while (*num)
		if (!ft_isdigit(*num++))
			return (0);
	return (*(num - 1) == '-' ? 0 : 1);
}
