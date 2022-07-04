/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 09:57:07 by ede-alme          #+#    #+#             */
/*   Updated: 2022/07/04 20:56:44 by ede-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_keepshortlist(t_lists *lists)
{
	if (lists->args_a == 2)
		if (lists->stack_a[0] > lists->stack_a[1])
			ft_sa_sb(lists->stack_a, lists->args_a, "sa");
	if (lists->args_a > 3 && ft_checkisorder(lists->stack_a, lists->args_a)
		&& lists->args_a < 90)
	{
		while (lists->args_a > 1)
		{
			ft_check_lowest(lists);
			while (lists->stack_a[0] != lists->lowest)
			{
				if ((ft_check_front(lists)) - (ft_check_back(lists)) > 0
					&& lists->stack_a[0] != lists->lowest)
					ft_rra_rrb(lists->stack_a, lists->args_a, "rra");
				else if (lists->stack_a[0] != lists->lowest)
					ft_ra_rb(lists->stack_a, lists->args_a, "ra");
			}
			ft_pa_pb(lists, "pb");
			if (!ft_checkisorder(lists->stack_a, lists->args_a))
				break ;
		}
		while (lists->args_b >= 1)
			ft_pa_pb(lists, "pa");
	}
}

void	ft_shortlist(t_lists *lists)
{
	if (lists->args_a == 3)
	{
		if (lists->stack_a[2] < lists->stack_a[0] && lists->stack_a[0]
			< lists->stack_a[1])
			ft_ra_rb(lists->stack_a, lists->args_a, "rra");
		else if (lists->stack_a[0] > lists->stack_a[1] && lists->stack_a[2]
			> lists->stack_a[0])
			ft_sa_sb(lists->stack_a, lists->args_a, "sa");
		else if (lists->stack_a[0] < lists->stack_a[2] && lists->stack_a[1]
			> lists->stack_a[2])
		{
			ft_rra_rrb(lists->stack_a, lists->args_a, "rra");
			ft_sa_sb(lists->stack_a, lists->args_a, "sa");
		}
		else if (lists->stack_a[0] > lists->stack_a[1] && lists->stack_a[1]
			< lists->stack_a[2])
			ft_ra_rb(lists->stack_a, lists->args_a, "ra");
		else if (lists->stack_a[0] > lists->stack_a[1] && lists->stack_a[1]
			> lists->stack_a[2])
		{
			ft_ra_rb(lists->stack_a, lists->args_a, "ra");
			ft_sa_sb(lists->stack_a, lists->args_a, "sa");
		}
	}
	ft_keepshortlist(lists);
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
	ft_shortlist(&lists);
	//printf("Lista: %i %i %i %i %i %i %i %i %i %i %i %i %i %i\n", lists.stack_a[0], lists.stack_a[1], lists.stack_a[2], lists.stack_a[3], lists.stack_a[4], lists.stack_a[5], lists.stack_a[6], lists.stack_a[7], lists.stack_a[8], lists.stack_a[9], lists.stack_a[10], lists.stack_a[11], lists.stack_a[12], lists.stack_a[13]);
	if (lists.args_a >= 90 && ft_checkisorder(lists.stack_a, lists.args_a))
		ft_hugeshortlist(&lists);
	ft_exit(0, &lists);
}
