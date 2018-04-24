/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 14:58:31 by rtulchiy          #+#    #+#             */
/*   Updated: 2017/12/26 17:29:57 by rtulchiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static void		*ft_realloc(void *ptr, size_t size)
{
	void	*newptr;

	if (!(newptr = ft_memalloc(size)))
		return (0);
	if (ptr)
	{
		if (ft_strlen(ptr) < size)
			ft_memcpy(newptr, ptr, ft_strlen(ptr));
		else
			ft_memcpy(newptr, ptr, size);
		free(ptr);
	}
	return (newptr);
}

static int		re_strings(char **line, char *str, char *buff, int len)
{
	char	*tmp;

	if (*buff == 0)
	{
		free(str);
		return (0);
	}
	ft_bzero(buff + len, BUFF_SIZE - len);
	tmp = ft_memchr(buff, '\n', BUFF_SIZE);
	if (!tmp)
	{
		ft_bzero(buff, BUFF_SIZE + 1);
		*line = str;
		return (1);
	}
	tmp += 1;
	ft_memmove(buff, tmp, ft_strlen(tmp));
	ft_bzero(buff + ft_strlen(tmp), BUFF_SIZE - ft_strlen(tmp));
	tmp = ft_memchr(str, '\n', ft_strlen(str));
	*tmp = 0;
	if (!(str = ft_realloc(str, (tmp - str) + 1)))
		return (-1);
	*line = str;
	return (1);
}

static t_dptr	*search(t_dptr *lst, int fd)
{
	t_dptr	*new;

	if (lst && lst->fd == fd)
		return (lst);
	if (lst && lst->next)
		return (search(lst->next, fd));
	if (!(new = (t_dptr*)ft_memalloc(sizeof(t_dptr))))
		return (0);
	new->num = !lst ? 0 : lst->num + 1;
	new->fd = fd;
	new->buff = 0;
	new->next = 0;
	new->prev = lst;
	if (lst)
		lst->next = new;
	return (new);
}

static t_dptr	*prepare_lst(t_dptr *lst, char **str, size_t *addition, int fd)
{
	*addition = 0;
	*str = 0;
	while (lst && lst->num != 0)
		lst = lst->prev;
	if (!(lst = search(lst, fd)))
		return (0);
	if (!(lst->buff) && !(lst->buff = (char*)ft_memalloc(BUFF_SIZE + 1)))
		return (0);
	else if ((*addition = ft_strlen(lst->buff)) || !(*addition))
	{
		*str = ft_strnew(*addition * sizeof(char));
		ft_strcat(*str, lst->buff);
	}
	return (lst);
}

int				get_next_line(const int fd, char **line)
{
	static t_dptr	*lst;
	char			*str;
	int				len;
	size_t			n;
	size_t			addition;

	len = BUFF_SIZE;
	n = 0;
	if (!line || fd == -1 || BUFF_SIZE <= 0)
		return (-1);
	if (!(lst = prepare_lst(lst, &str, &addition, fd)))
		return (-1);
	while (!ft_memchr(lst->buff, '\n', BUFF_SIZE))
	{
		if ((len = read(fd, lst->buff, BUFF_SIZE)) == -1)
			return (-1);
		if (!(str = ft_realloc(str, BUFF_SIZE * n + len + addition + 1)))
			return (-1);
		ft_memcpy(str + addition + BUFF_SIZE * n, lst->buff, len);
		if (len < BUFF_SIZE)
			break ;
		n++;
	}
	return (re_strings(line, str, lst->buff, len));
}
