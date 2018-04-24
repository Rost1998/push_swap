/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rand.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 18:10:44 by rtulchiy          #+#    #+#             */
/*   Updated: 2018/01/29 18:11:11 by rtulchiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RAND_H
# define FT_RAND_H

# include <stdlib.h>
# include <unistd.h>
# include <time.h>

void			error_invalid_nums_args(void);
void			check_valid_num(char *num);
int				*create_nums(int size);
_Bool			ft_isnumber(char *num);
int				ft_atoi(const char *str);
void			ft_putnbr(int c);
void			*ft_memalloc(size_t size);
int				ft_iswhitespaces(int c);

#endif
