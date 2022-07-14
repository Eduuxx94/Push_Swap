/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 16:29:55 by ede-alme          #+#    #+#             */
/*   Updated: 2022/07/13 11:27:45 by ede-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_lists {
	int		*stack_a;
	int		*stack_b;
	int		*stack_temp;
	int		args_a;
	int		args_b;
	int		lowest;
	int		biggest;
	int		i;
	int		count;
	int		lower;
	int		incase;
	int		divisor;
	int		remaing;
	int		volume;
}			t_lists;

//Push Swap main functions					->
void	ft_keepshortlist(t_lists *lists);
void	ft_short_three_list(t_lists *lists);
void	ft_exit(char *str, t_lists *lists);
int		ft_toint(char *str, t_lists *lists);
int		main(int argc, char **argv);

//Push Swap operations1						->
void	ft_sa_sb(int *stack, int args, char *operation);
void	ft_ss(t_lists *lists);
void	ft_pa_pb(t_lists *lists, char *operation);
int		exec_pa_pb(int *stack_in, int *stack_out, int *args_in, int *args_out);
void	ft_ra_rb(int *stack, int args, char *operation);

//Push Swap operations2						->
void	ft_rr(t_lists *lists, char *operation);
void	ft_rra_rrb(int *stack, int args, char *operation);
void	ft_rrr(t_lists *lists, char *operation);

//Push Swap utils functions into			->
void	ft_hugeshortlist(t_lists *lists);
void	ft_check_lowest(t_lists *lists, int *stack, int args);
int		ft_check_front(t_lists *lists, int *stack, int args, char *step);
int		ft_check_back(t_lists *lists, int *stack, int args, char *step);
int		ft_checkisorder(int *stack, int args);

//Push Swap Huge Rules to					->
void	ft_renumber(t_lists *lists);
void	ft_check_biggest(t_lists *lists, int *stack, int args);
void	ft_orderhuge(t_lists *lists);
void	ft_start(t_lists *lists, int argc, char **argv);
void	ft_keepshortlist_five(t_lists *lists);

#endif
