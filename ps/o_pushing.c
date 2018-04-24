/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_pushing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 15:38:49 by rtulchiy          #+#    #+#             */
/*   Updated: 2018/01/27 20:27:27 by rtulchiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_swap(t_list **stack, t_vars *vars, char *operation)
{
	(vars->opers)[(vars->index)++] = ft_strdup(operation);
	o_swap(stack);
}

void	get_push(t_list **dst, t_list **src, t_vars *vars, char *operation)
{
	(vars->opers)[(vars->index)++] = ft_strdup(operation);
	o_push(dst, src);
}

void	get_rotate(t_list **stack, t_vars *vars, char *operation)
{
	(vars->opers)[(vars->index)++] = ft_strdup(operation);
	o_rotate(stack);
}

void	get_rev_rotate(t_list **stack, t_vars *vars, char *operation)
{
	(vars->opers)[(vars->index)++] = ft_strdup(operation);
	o_rev_rotate(stack);
}
