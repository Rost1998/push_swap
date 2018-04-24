/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 16:18:43 by rtulchiy          #+#    #+#             */
/*   Updated: 2018/02/03 14:56:31 by rtulchiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int		get_fd(t_args *args, char ***av)
{
	int		fd;

	fd = 0;
	if (args->file)
	{
		if ((fd = open(**av, O_RDONLY)) < 0)
			error_fd();
		(*av)++;
	}
	return (fd);
}

static void		print_res(t_list *stack_a, t_list *stack_b)
{
	write(1, "\033[1m", 4);
	if (ft_check_sort(stack_a, stack_b))
		write(1, "\033[032mOK\n\033[0m", 13);
	else
		write(1, "\033[031mKO\n\033[0m", 13);
	write(1, "\033[0m", 4);
}

static void		ft_memfree(t_list *stack_a, t_list *stack_b, char **av,\
															t_args *args)
{
	t_list	*tmp;
	int		i;

	while (stack_a)
	{
		tmp = stack_a;
		stack_a = stack_a->next;
		free(tmp->content);
		free(tmp);
	}
	while (stack_b)
	{
		tmp = stack_b;
		stack_b = stack_b->next;
		free(tmp->content);
		free(tmp);
	}
	free(args);
	i = 0;
	if (args->heap)
	{
		while (av[i])
			free(av[i++]);
		free(av);
	}
}

static void		fork_arg(char ***av, char **argv, t_args *args)
{
	if (!((*av)[1]))
	{
		free(**av);
		free(*av);
		*av = argv;
	}
	else if ((args->heap = 1) && argv[1])
		ft_error();
}

int				main(int argc, char **argv)
{
	t_args		*args;
	t_list		*stack_a;
	t_list		*stack_b;
	char		**av;
	int			fd;

	if ((++argv) && argc == 1 && !(stack_b = 0))
		return (0);
	args = ft_handle_args(&argv);
	fd = get_fd(args, &argv);
	if (!(*argv))
		return (0);
	av = ft_strsplit(*argv, ' ');
	fork_arg(&av, argv, args);
	ft_validator(av);
	ft_create_stack(av, &stack_a);
	ft_handle_operations(&stack_a, &stack_b, fd, args);
	print_res(stack_a, stack_b);
	ft_memfree(stack_a, stack_b, av, args);
	return (0);
}
