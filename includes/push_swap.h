/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoldber <agoldber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 19:21:32 by agoldber          #+#    #+#             */
/*   Updated: 2024/08/31 00:33:46 by agoldber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

typedef struct s_stack_node {
	int	value;
	struct s_stack_node *prev;
	struct s_stack_node *next;
}	t_stack_node;

typedef struct s_verif_num {
	long int value;
	int err;
}	t_verif;

void	ft_exit(char *str, int n);
void	ft_freexit(void *pointer, char *str, int i);
void	ft_free_stack(t_stack_node **stack);
void	check_av(int ac, char **av);
void	stack_init(t_stack_node **a, char **av);
t_verif	ft_atol(char *str);

//Movements
void	sa(t_stack_node **a);

#endif