/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoldber <agoldber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 19:21:32 by agoldber          #+#    #+#             */
/*   Updated: 2024/09/28 19:12:08 by agoldber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

typedef struct s_stack_node
{
	int					value;
	int					pos;
	struct s_stack_node	*prev;
	struct s_stack_node	*next;
}	t_stack_node;

typedef struct s_verif_num
{
	long int	value;
	int			err;
}	t_verif;

void			ft_exit(char *str, int n);
void			ft_freexit(void *pointer, char *str, int i);
void			ft_free_stack(t_stack_node **stack);
t_verif			ft_atol(char *str);
int				sorted(t_stack_node **a);
int				real_sorted(t_stack_node **stack);
int				count_node(t_stack_node **stack);
t_stack_node	*check_av(int ac, char **av, int *tot_elem);
void			bubble_sort(t_stack_node *tab, int tot_elem);
void			stack_init(t_stack_node **a, char **av, t_stack_node *tab);
void			sort(t_stack_node **a, t_stack_node **b, int tot_elem);
void			tiny_list(t_stack_node **a, t_stack_node **b, int elem);
void			sort_med(t_stack_node **a, t_stack_node **b, int tot);
void			sort_in_stack(t_stack_node **a, t_stack_node **b, int tot_elem);
void			rotate_sort(t_stack_node **a, t_stack_node **b, int tot_elem);

//Movements
void			sa(t_stack_node **a);
void			sb(t_stack_node **b);
void			ss(t_stack_node **a, t_stack_node **b);
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **b, t_stack_node **a);
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);

#endif