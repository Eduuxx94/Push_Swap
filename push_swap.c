/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 09:57:07 by ede-alme          #+#    #+#             */
/*   Updated: 2022/07/02 15:40:36 by ede-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_shortlist(t_lists *lists)
{
	if (lists)
		lists++;
}

void	ft_exit(char *str, t_lists *lists)
{
	if (str)
		printf("%s\n", str);
	if (lists->stack_a)
		free(lists->stack_a);
	if (lists->stack_b)
		free(lists->stack_b);
	exit(0);
}

int	ft_toint(char *str, t_lists *lists)
{
	long long int	value;
	int				signal;

	signal = (*str != '-') - (*str == '-');
	value = 0;
	if (*str == '-' || *str == '+')
		str++;
	while (*str && (*str >= '0' && *str <= '9'))
		value = (value * 10) + (*str++ - 48);
	if (*str)
		ft_exit("Error insert int arg", lists);
	if ((value * signal) > 2147483647 || (value * signal) < -2147483648)
		ft_exit("Error, to long size arg", lists);
	return (value * signal);
}

int	main(int argc, char **argv)
{
	t_lists	lists;
	int		i;
	int		reverse;

	i = 0;
	if (argc < 2)
		return (0);
	lists.stack_a = malloc(sizeof(int) * (argc - 1));
	lists.stack_b = malloc(sizeof(int) * (argc - 1));
	lists.args_a = argc - 1;
	lists.args_b = 0;
	while (i < (argc - 1))
	{
		reverse = i;
		lists.stack_a[i] = ft_toint(argv[i + 1], &lists);
		i++;
		while (--reverse >= 0)
			if (lists.stack_a[i - 1] == lists.stack_a[reverse])
				ft_exit("Error duplicate argument!", &lists);
	}
	ft_exit(0, &lists);
}
