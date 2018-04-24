/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 12:34:50 by rtulchiy          #+#    #+#             */
/*   Updated: 2018/02/04 19:37:36 by rtulchiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line2.h"

static t_list	*ft_search_lst(t_list **lst, const int fd)
{
	t_list		*tmp;
	int			*intfd;

	if (!(intfd = (int*)ft_memalloc((BUFF_SIZE + 5) * sizeof(char))))
		return (0);
	*intfd = fd;
	if (!(*lst))
	{
		tmp = ft_lstnew(intfd, BUFF_SIZE + 5);
		ft_lstadd(lst, tmp);
		free(intfd);
		return (tmp);
	}
	tmp = *lst;
	while (tmp)
	{
		if (fd == *(int*)(tmp->content))
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew(intfd, BUFF_SIZE + 5);
	free(intfd);
	ft_lstadd(lst, tmp);
	*lst = tmp;
	return (tmp);
}

static int		re_strs(char **line, char *str, t_list *tmp, int len)
{
	char	*nl;

	nl = ft_memchr(str, '\n', ft_strlen(str));
	nl ? ft_strcpy((char*)(tmp->content + 4), nl + 1) : 0;
	ft_bzero(nl, ft_strlen(nl));
	*line = str;
	return (*(char*)(tmp->content + 4) || *str ? 1 : 0);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*lst;
	t_list			*tmp;
	char			*str;
	int				len;
	int				n;

	n = 0;
	str = (char*)ft_memalloc((BUFF_SIZE + 1) * sizeof(char));
	tmp = ft_search_lst(&lst, fd);
	if (*(char*)(tmp->content + 4) &&\
		ft_strcpy(str, (char*)(tmp->content + 4)) && (n += ft_strlen(str)))
		ft_bzero(tmp->content + 4, BUFF_SIZE);
	while (!ft_memchr(str, '\n', ft_strlen(str)))
	{
		if (!(str = (char*)ft_realloc(str, BUFF_SIZE + 1 + n)))
			return (-1);
		if ((len = read(fd, str + n, BUFF_SIZE)) == -1)
			return (-1);
		if (len < BUFF_SIZE || !len)
			break ;
		n += BUFF_SIZE;
	}
	return (re_strs(line, str, tmp, len));
}
