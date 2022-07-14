/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 10:10:41 by ede-alme          #+#    #+#             */
/*   Updated: 2022/07/13 11:22:50 by ede-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_hugeshortlist(t_lists *lists)
{
	if (lists->args_a >= 90 && ft_checkisorder(lists->stack_a, lists->args_a))
	{	
		while (lists->count > 0)
		{
			ft_check_biggest(lists, lists->stack_a, lists->args_a);
			if ((lists->stack_a[0] > (lists->args_a + lists->args_b - lists
						->divisor)) && (lists->stack_a[0] <= lists->count
					&& lists->remaing--))
				ft_pa_pb(lists, "pb");
			else
				ft_rra_rrb(lists->stack_a, lists->args_a, "rra");
			if (lists->args_b == lists->volume || lists->remaing == 0)
			{
				ft_check_biggest(lists, lists->stack_b, lists->args_b);
				ft_orderhuge(lists);
			}
		}
	}
}

void	ft_check_lowest(t_lists *lists, int *stack, int args)
{
	int	i;

	i = 0;
	lists->lowest = 2147483647;
	while (i < args)
	{
		if (stack[i] < lists->lowest)
			lists->lowest = stack[i];
		i++;
	}
}

int	ft_check_front(t_lists *lists, int *stack, int args, char *step)
{
	int	i;

	i = 0;
	if (step[0] == 'l')
	{
		while (i < args - 1)
		{
			if (stack[i++] == lists->lowest)
				return (i);
		}
	}
	else if (step[0] == 'b')
	{
		while (i < args - 1)
		{
			if (stack[i++] == lists->biggest)
				return (i);
		}
	}
	return (i);
}

int	ft_check_back(t_lists *lists, int *stack, int args, char *step)
{
	int	i;

	i = args - 1;
	if (step[0] == 'l')
	{
		while (i > 0)
		{
			if (stack[i--] == lists->lowest)
				return ((args - 1) - i);
		}
	}
	else if (step[0] == 'b')
	{
		while (i > 0)
		{
			if (stack[i--] == lists->biggest)
				return ((args - 1) - i);
		}
	}
	return ((args - 1) - i);
}

int	ft_checkisorder(int *stack, int args)
{
	int	i;

	i = 0;
	while (i < args - 1)
	{
		if (stack[i] < stack[i + 1])
			i++;
		else
			return (1);
	}
	return (0);
}
