/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 18:53:21 by rtulchiy          #+#    #+#             */
/*   Updated: 2018/01/31 18:42:18 by rtulchiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rand.h"

static void		to_end(int *nums, int len, int index)
{
	int		i;
	int		tmp_num;

	tmp_num = nums[index];
	while (index < len)
	{
		nums[index] = nums[index + 1];
		index++;
	}
	nums[len - 1] = tmp_num;
}

static void		randomize_nums(int *nums, int i)
{
	int		index;
	int		len;

	len = i;
	srand(time(NULL));
	while (i)
	{
		index = rand() % i--;
		to_end(nums, len, index);
	}
}

int				main(int argc, char **argv)
{
	int		*nums;
	int		i;

	if (argc != 2)
		error_invalid_nums_args();
	check_valid_num(argv[1]);
	i = ft_atoi(argv[1]);
	nums = create_nums(i);
	randomize_nums(nums, i);
	while (i--)
	{
		ft_putnbr(*nums++);
		if (i)
			write(1, " ", 1);
	}
	write(1, "\n", 1);
	return (0);
}
