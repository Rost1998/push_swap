/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iswhitespaces.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 19:22:38 by rtulchiy          #+#    #+#             */
/*   Updated: 2017/11/01 19:25:18 by rtulchiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iswhitespaces(int c)
{
	char	i;

	i = (unsigned char)c;
	if (i == ' ' || i == '\n' ||
		i == '\t' || i == '\v' ||
		i == '\f' || i == '\r')
		return (1);
	return (0);
}
