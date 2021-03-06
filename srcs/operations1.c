/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 16:28:23 by ede-alme          #+#    #+#             */
/*   Updated: 2022/07/18 11:34:10 by ede-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sa_sb(int *stack, int args, char *operation)
{
	int	temp;

	if (args >= 2)
	{
		temp = stack[0];
		stack[0] = stack[1];
		stack[1] = temp;
		write(1, operation, 2);
		write(1, "\n", 1);
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
		write(1, "ss\n", 3);
	}
}

void	ft_pa_pb(t_lists *lists, char *operation)
{
	if (operation[1] == 'a' && exec_pa_pb(lists->stack_a, lists->stack_b,
			&lists->args_a, &lists->args_b))
		write(1, operation, 2);
	if (operation[1] == 'b' && exec_pa_pb(lists->stack_b, lists->stack_a,
			&lists->args_b, &lists->args_a))
		write(1, operation, 2);
	if (operation[1] == 'a' || operation[1] == 'b')
		write(1, "\n", 1);
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

void	ft_ra_rb(int *stack, int args, char *operation)
{
	int	temp;
	int	i;

	if (args >= 2)
	{
		i = 0;
		temp = stack[0];
		while (i < args - 1)
		{
			stack[i] = stack[i + 1];
			i++;
		}
		stack[i] = temp;
		if (operation)
		{
			write(1, operation, 2);
			write(1, "\n", 1);
		}
	}
}
