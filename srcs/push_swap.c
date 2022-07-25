/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 09:57:07 by ede-alme          #+#    #+#             */
/*   Updated: 2022/07/18 13:29:38 by ede-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_keepshortlist(t_lists *lists)
{
	if (lists->args_a == 2)
		if (lists->stack_a[0] > lists->stack_a[1])
			ft_sa_sb(lists->stack_a, lists->args_a, "sa");
	if (lists->args_a > 5 && ft_checkisorder(lists->stack_a, lists->args_a)
		&& lists->args_a < 90)
	{
		while (lists->args_a > 1)
		{
			ft_check_lowest(lists, lists->stack_a, lists->args_a);
			while (lists->stack_a[0] != lists->lowest)
			{
				if ((ft_check_front(lists, lists->stack_a, lists->args_a, "l"))
					- (ft_check_back(lists, lists->stack_a, lists->args_a, "l"))
					> 0 && lists->stack_a[0] != lists->lowest)
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

void	ft_short_three_list(t_lists *lists)
{
	if (lists->args_a == 3)
	{
		if (lists->stack_a[2] < lists->stack_a[0] && lists->stack_a[0]
			< lists->stack_a[1])
			ft_rra_rrb(lists->stack_a, lists->args_a, "rra");
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
}

void	ft_exit(char *str, t_lists *lists)
{
	if (str && str[5] == '\n')
		write(1, str, 6);
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
	if (!*str)
		ft_exit("Error\n", lists);
	while (*str && (*str >= '0' && *str <= '9'))
		value = (value * 10) + (*str++ - 48);
	if (*str)
		ft_exit("Error\n", lists);
	if ((value * signal) > 2147483647 || (value * signal) < -2147483648)
		ft_exit("Error\n", lists);
	return (value * signal);
}

int	main(int argc, char **argv)
{
	t_lists	lists;

	if (argc < 2)
		return (0);
	ft_start(&lists, argc, argv);
	ft_renumber(&lists);
	ft_short_three_list(&lists);
	ft_keepshortlist_five(&lists);
	ft_keepshortlist(&lists);
	ft_hugeshortlist(&lists);
	ft_exit(0, &lists);
}
