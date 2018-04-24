/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 12:27:12 by rtulchiy          #+#    #+#             */
/*   Updated: 2018/02/04 19:37:10 by rtulchiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# define BUFF_SIZE 4

typedef struct	s_d
{
	size_t		num;
	int			fd;
	char		*buff;
	struct s_d	*next;
	struct s_d	*prev;
}				t_dptr;

int				get_next_line(const int fd, char **line);

#endif
