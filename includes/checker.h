/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 15:35:47 by rtulchiy          #+#    #+#             */
/*   Updated: 2018/02/01 19:18:42 by rtulchiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"
# include "get_next_line.h"

# define MAX_ELEMS 10000
# define TRUE 1
# define FALSE 0

typedef struct		s_args
{
	_Bool			vis;
	_Bool			color;
	_Bool			ops;
	_Bool			file;
	_Bool			heap;
}					t_args;

void				o_swap(t_list **head);
void				o_push(t_list **dst, t_list **src);
void				o_rotate(t_list **head);
void				o_rev_rotate(t_list **head);
void				ft_validator(char **av);
void				ft_create_stack(char **av, t_list **stack_a);
void				ft_handle_operations(t_list **stack_a, t_list **stack_b,\
														int	fd, t_args *args);
t_args				*ft_handle_args(char ***av);
_Bool				ft_check_sort(t_list *stack_a, t_list *stack_b);
void				ft_error(void);
void				ft_error_invalid_option(void);
int					ft_getmed(t_list *stack, int len);
size_t				ft_lstlen(t_list *lst);
int					ft_backtrack(t_list **stack_a, int n, int *index,\
																_Bool code);
void				ft_cleanopers(void);
void				get_swap(t_list **stack, int *index, char *operation);
void				get_push(t_list **dst, t_list **src, int *index,\
														char *operation);
void				get_rotate(t_list **stack, int *index, char *operation);
void				get_rev_rotate(t_list **stack, int *index, char *operation);
int					ft_qsort(t_list **stack_a, t_list **stack_b, int *index);
void				ft_visual(t_list *stack_a, t_list *stack_b, char *op,\
															t_args *args);
void				error_fd(void);

#endif
