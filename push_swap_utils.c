/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 10:10:41 by ede-alme          #+#    #+#             */
/*   Updated: 2022/07/04 16:15:28 by ede-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_lowest(t_lists *lists)
{
	int	i;

	i = 0;
	lists->lowest = 2147483647;
	lists->second_lowest = 2147483647;
	while (i < lists->args_a)
	{
		if (lists->stack_a[i] < lists->lowest)
			lists->lowest = lists->stack_a[i];
		i++;
	}
	i = 0;
	while (i < lists->args_a)
	{
		if (lists->stack_a[i] < lists->second_lowest
			&& lists->stack_a[i] != lists->lowest)
			lists->second_lowest = lists->stack_a[i];
		i++;
	}
}

int	ft_check_front(t_lists *lists)
{
	int	i;

	i = 0;
	while (i < lists->args_a - 1)
		if (lists->stack_a[i++] == lists->lowest)
			return (i);
	return (i);
}

int	ft_check_back(t_lists *lists)
{
	int	i;

	i = lists->args_a - 1;
	while (i > 0)
	{
		if (lists->stack_a[i--] == lists->lowest)
			return ((lists->args_a - 1) - i);
	}
	return ((lists->args_a - 1) - i);
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