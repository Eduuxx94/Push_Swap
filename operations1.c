/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 16:28:23 by ede-alme          #+#    #+#             */
/*   Updated: 2022/07/02 15:45:27 by ede-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa_sb(int *stack, int args, char *operation)
{
	int	temp;

	if (args >= 2)
	{
		temp = stack[0];
		stack[0] = stack[1];
		stack[1] = temp;
		printf("%s\n", operation);
	}
}

void	ft_ss(t_lists *lists)
{
	int	temp;

	if (lists->args_a >= 2 && lists->args_b >= 2)
	{
		temp = lists->stack_a[0];
		lists->stack_a[0] = lists->stack_a[1];
		lists->stack_a[1] = temp;
		temp = lists->stack_b[0];
		lists->stack_b[0] = lists->stack_b[1];
		lists->stack_b[1] = temp;
		printf("ss\n");
	}
}

void	ft_pa_pb(t_lists *lists, char *operation)
{
	if (operation[1] == 'a' && exec_pa_pb(lists->stack_a, lists->stack_b,
			&lists->args_a, &lists->args_b))
		printf("%s\n", operation);
	if (operation[1] == 'b' && exec_pa_pb(lists->stack_b, lists->stack_a,
			&lists->args_b, &lists->args_a))
		printf("%s\n", operation);
}

int	exec_pa_pb(int *stack_in, int *stack_out, int *args_in, int *args_out)
{
	int	i;

	i = *args_in;
	if (*args_out >= 1)
	{
		while (i > 0)
		{
			stack_in[i] = stack_in[i - 1];
			i--;
		}
		stack_in[i] = stack_out[i];
		while (i < *args_out - 1)
		{
			stack_out[i] = stack_out[i + 1];
			i++;
		}
		stack_out[i] = 0;
		(*args_out)--;
		(*args_in)++;
		return (1);
	}
	return (0);
}

void	ft_ra(t_lists *lists)
{
	
}