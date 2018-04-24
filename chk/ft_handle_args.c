/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 15:48:23 by rtulchiy          #+#    #+#             */
/*   Updated: 2018/02/03 13:05:03 by rtulchiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static _Bool	ft_isnumber(char *num)
{
	if (*num == '-')
		++num;
	while (*num)
		if (!ft_isdigit(*num++))
			return (FALSE);
	return (*(num - 1) == '-' ? FALSE : TRUE);
}

static void		ft_check_symb(t_args *args, char symb)
{
	int		exist;

	exist = 0;
	if (symb == 'v' && (exist = 1))
		args->vis = 1;
	if (symb == 'c' && (exist = 1))
		args->color = 1;
	if (symb == 'o' && (exist = 1))
		args->ops = 1;
	if (symb == 'f' && (exist = 1))
		args->file = 1;
	if (!exist)
		ft_error_invalid_option();
}

t_args			*ft_handle_args(char ***av)
{
	t_args		*args;

	if (!(args = ft_memalloc(sizeof(args))))
		return (0);
	args->vis = 0;
	args->color = 0;
	args->ops = 0;
	args->file = 0;
	args->heap = 0;
	while (**av && !ft_isnumber(**av) && ***av == '-' &&\
									!ft_isdigit(*(**av + 1)))
	{
		if (***av == '-')
			while (*++(**av))
				ft_check_symb(args, ***av);
		if (*(**av - 1) == '-')
			ft_error_invalid_option();
		++(*av);
	}
	return (args);
}
