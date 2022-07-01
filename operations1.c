/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 16:28:23 by ede-alme          #+#    #+#             */
/*   Updated: 2022/07/01 20:34:30 by ede-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_lists *lists)
{
	int	temp;

	if (lists->args_a >= 2)
	{
		temp = lists->stack_a[0];
		lists->stack_a[0] = lists->stack_a[1];
		lists->stack_a[1] = temp;
		printf("sa\n");
	}
}

void	ft_sb(t_lists *lists)
{
	int	temp;

	if (lists->args_b >= 2)
	{
		temp = lists->stack_b[0];
		lists->stack_b[0] = lists->stack_b[1];
		lists->stack_b[1] = temp;
		printf("sb\n");
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

void	ft_pa(t_lists *lists)
{
	int	*temp_list;
	int	i;

	i = 0;
	if (lists->args_b >= 1)
	{
		if (lists->stack_a)
		{
			temp_list = lists->stack_a;
			lists->stack_a = malloc(sizeof(int) * (lists->args_a + 1));
			lists->stack_a[i] = lists->stack_a[i];
			i++;
			while (i + 1 <= lists->args_a)
			{
				lists->stack_a[i + 1] = temp_list[i];
				i++;
			}
			free (temp_list);
			i = 0;
		}
		else
		{
			lists->stack_a = malloc(sizeof(int) * 1);
			lists->stack_a[i] = lists->stack_b[i];
		}
		temp_list = lists->stack_b;
		free (lists->stack_b);
		lists->stack_b = malloc(sizeof(int) * (lists->args_b - 1));
		while (i < lists->args_b)
		{
			lists->stack_b[i] = temp_list[i + 1];
			i++;
		}
		lists->args_b--;
		printf("pa\n");
	}
}

void	ft_pb(t_lists *lists)
{
	int	*temp_list;
	int	i;

	i = 0;
	if (lists->args_a >= 1)
	{
		if (lists->args_b >= 1)
		{
			temp_list = ft_stackcpy(lists->stack_b, lists->args_b, lists);
			free (lists->stack_b);
		}
		lists->stack_b = malloc(sizeof(int) * (lists->args_b + 1));
		lists->stack_b[i] = lists->stack_a[i];
		i++;
		while (i <= lists->args_b)
		{
			lists->stack_b[i] = temp_list[i - 1];
			i++;
		}
		lists->args_b++;
		if (lists->temp_args >= 1)
			free (temp_list);
		i = 0;
		temp_list = ft_stackcpy(lists->stack_a, lists->args_a, lists);
		free(lists->stack_a);
		if (lists->args_a > 1)
		{
			lists->stack_a = malloc(sizeof(int) * (lists->args_a - 1));
			while (i < lists->args_a - 1)
			{
				printf("chegou aqui\n\n\n\n");
				lists->stack_a[i] = temp_list[i + 1];
				i++;
			}
			if (lists->temp_args >= 1)
				free (temp_list);
		}
		lists->args_a--;
		printf("pb\n");
	}
}

int	*ft_stackcpy(int *src, int size, t_lists *lists)
{
	int	i;
	int	*temp_list;

	i = 0;
	lists->temp_args = size;
	temp_list = malloc(sizeof(int) * (size));
	while (i < size)
	{
		temp_list[i] = src[i];
		i++;
	}
	return (temp_list);
}
