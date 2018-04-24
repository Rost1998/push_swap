/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 15:35:47 by rtulchiy          #+#    #+#             */
/*   Updated: 2018/02/03 12:48:47 by rtulchiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

# define MAX_ELEMS 1000
# define TRUE 1
# define FALSE 0

typedef struct		s_vars
{
	char			**opers;
	int				*parts_a;
	int				*parts_b;
	int				index;
	int				piv;
	_Bool			need_rev;
}					t_vars;

void				o_swap(t_list **head);
void				o_push(t_list **dst, t_list **src);
void				o_rotate(t_list **head);
void				o_rev_rotate(t_list **head);
void				ft_validator(char **av);
void				ft_create_stack(char **av, t_list **stack_a);
void				ft_handle_operations(t_list **stack_a, t_list **stack_b);
_Bool				ft_check_sort(t_list *stack_a, t_list *stack_b);
void				ft_error(void);
void				ft_error_memory(void);
int					ft_getmed(t_list *stack, int len);
size_t				ft_lstlen(t_list *lst);
int					ft_backtrack(t_list **stack_a, int n, t_vars *vars,\
																_Bool code);
void				ft_cleanopers(t_vars *vars);
void				get_swap(t_list **stack, t_vars *vars, char *operation);
void				get_push(t_list **dst, t_list **src, t_vars *vars,\
															char *operation);
void				get_rotate(t_list **stack, t_vars *vars, char *operation);
void				get_rev_rotate(t_list **stack, t_vars *vars,\
															char *operation);
int					ft_qsort(t_list **stack_a, t_list **stack_b, t_vars *vars);
void				shift_part_b(t_vars *vars, _Bool code);
void				ft_sort3(t_list **stack_a, t_vars *vars);
int					ft_random_sort(t_list *stack, int len, _Bool code);
_Bool				ft_isrev(t_list *stack);
_Bool				ft_isbetween(t_list *stack_a, t_list *stack_b,\
														int num1, int num2);
_Bool				ft_isuseful_rrr(t_list *stack, int piv, _Bool code);
int					ft_check_unsort(t_list *stack_a, t_list *stack_b);
void				ft_isneed_swap(t_list **stack_a, t_list **stack_b,\
																t_vars *vars);
void				ft_kost(t_list **stack_a, t_list **stack_b, t_vars *vars);

#endif
