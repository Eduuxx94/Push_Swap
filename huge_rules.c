/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   huge_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:51:25 by ede-alme          #+#    #+#             */
/*   Updated: 2022/07/13 11:35:21 by ede-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_renumber(t_lists *lists)
{
	lists->stack_temp = malloc(sizeof(int) * lists->args_a);
	lists->i = -1;
	lists->count = 0;
	while (++lists->i < lists->args_a)
		lists->stack_temp[lists->i] = 0;
	while (lists->count < lists->args_a)
	{
		lists->i = 0;
		lists->lower = 2147483647;
		while (lists->i < lists->args_a)
		{
			if (lists->stack_a[lists->i] < lists->lower && lists->stack_temp
				[lists->i] == 0)
			{
				lists->lower = lists->stack_a[lists->i];
				lists->incase = lists->i;
			}
			lists->i++;
		}
		lists->stack_temp[lists->incase] = 1;
		lists->count++;
		lists->stack_a[lists->incase] = lists->count;
	}
	free (lists->stack_temp);
}

void	ft_check_biggest(t_lists *lists, int *stack, int args)
{
	int	i;

	i = 0;
	lists->biggest = -2147483648;
	while (i < args)
	{
		if (stack[i] > lists->biggest)
			lists->biggest = stack[i];
		i++;
	}
}

void	ft_orderhuge(t_lists *lists)
{
	while (lists->stack_a[0] != (lists->biggest + 1) && lists->count
		!= lists->args_a + lists->args_b)
	{
		if ((ft_check_front(lists, lists->stack_b, lists->args_b, "b"))
			- (ft_check_back(lists, lists->stack_b, lists->args_b, "b"))
			> 0 && lists->stack_b[0] != lists->biggest)
			ft_rrr(lists, "rrr");
		else if (lists->stack_b[0] != lists->biggest)
			ft_rr(lists, "rr");
		else
			ft_ra_rb(lists->stack_a, lists->args_a, "ra");
	}
	while (lists->args_b > 0 && lists->divisor++ && lists->count--)
	{	
		ft_check_biggest(lists, lists->stack_b, lists->args_b);
		while (lists->stack_b[0] != lists->biggest)
		{
			if ((ft_check_front(lists, lists->stack_b, lists->args_b, "b"))
				- ft_check_back(lists, lists->stack_b, lists->args_b, "b") > 0)
				ft_rra_rrb(lists->stack_b, lists->args_b, "rrb");
			else
				ft_ra_rb(lists->stack_b, lists->args_b, "rb");
		}
		ft_pa_pb(lists, "pa");
	}
}

void	ft_start(t_lists *lists, int argc, char **argv)
{
	int		i;
	int		reverse;

	i = 0;
	lists->stack_a = malloc(sizeof(int) * (argc - 1));
	lists->stack_b = malloc(sizeof(int) * (argc - 1));
	lists->args_a = argc - 1;
	lists->args_b = 0;
	lists->remaing = lists->args_a;
	while (i < (argc - 1))
	{
		reverse = i;
		lists->stack_a[i] = ft_toint(argv[i + 1], lists);
		i++;
		while (--reverse >= 0)
			if (lists->stack_a[i - 1] == lists->stack_a[reverse])
				ft_exit("Error duplicate argument!", lists);
	}
	if (lists->args_a >= 90 && lists->args_a < 300)
		lists->volume = 35;
	else
		lists->volume = 85;
	lists->divisor = lists->volume;
}

void	ft_keepshortlist_five(t_lists *lists)
{
	if (lists->args_a == 5)
	{
		if (!ft_checkisorder(lists->stack_a, lists->args_a))
			return ;
		while (lists->args_a > 3)
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
		}
		ft_short_three_list(lists);
		while (lists->args_b >= 1)
			ft_pa_pb(lists, "pa");
	}
}
