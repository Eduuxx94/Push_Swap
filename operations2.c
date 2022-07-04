/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 16:38:58 by ede-alme          #+#    #+#             */
/*   Updated: 2022/07/04 18:47:59 by ede-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rr(t_lists *lists, char *operation)
{
	if (lists->args_a >= 2 && lists->args_b >= 2)
	{
		ft_ra_rb(lists->stack_a, lists->args_a, NULL);
		ft_ra_rb(lists->stack_b, lists->args_b, NULL);
		printf("%s\n", operation);
	}
}

void	ft_rra_rrb(int *stack, int args, char *operation)
{
	int	temp;
	int	i;

	if (args >= 2)
	{
		i = args - 1;
		temp = stack[args - 1];
		while (i > 0)
		{
			stack[i] = stack[i - 1];
			i--;
		}
		stack[i] = temp;
		if (operation)
			printf("%s\n", operation);
	}
}

void	ft_rrr(t_lists *lists, char *operation)
{
	if (lists->args_a >= 2 && lists->args_b >= 2)
	{
		ft_rra_rrb(lists->stack_a, lists->args_a, NULL);
		ft_rra_rrb(lists->stack_b, lists->args_b, NULL);
		printf("%s\n", operation);
	}
}
