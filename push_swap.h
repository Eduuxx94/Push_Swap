/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 16:29:55 by ede-alme          #+#    #+#             */
/*   Updated: 2022/07/03 10:45:29 by ede-alme         ###   ########.fr       */
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
	int		args_a;
	int		args_b;
	int		lowest;
}			t_lists;

//Push Swap functions					->
int		main(int argc, char **argv);
int		ft_toint(char *str, t_lists *lists);
void	ft_exit(char *str, t_lists *lists);
void	ft_shortlist(t_lists *lists);
void	ft_check_lowest(t_lists *lists);

//Push Swap operations1					->
void	ft_sa_sb(int *stack, int args, char *operation);
void	ft_ss(t_lists *lists);
void	ft_pa_pb(t_lists *lists, char *operation);
int		exec_pa_pb(int *stack_in, int *stack_out, int *args_in, int *args_out);
void	ft_ra_rb(int *stack, int args, char *operation);

//Push Swap operations2					->
void	ft_rr(t_lists *lists, char *operation);
void	ft_rra_rrb(int *stack, int args, char *operation);
void	ft_rrr(t_lists *lists, char *operation);

#endif
