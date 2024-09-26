/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoldber <agoldber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 19:21:32 by agoldber          #+#    #+#             */
/*   Updated: 2024/09/26 13:58:15 by agoldber         ###   ########.fr       */
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

typedef struct s_indicator
{
	int	min_val;
	int	min_pos;
	int	max_val;
	int	max_pos;
	int	tot_elem;
}	t_ind;

void			ft_exit(char *str, int n);
void			ft_freexit(void *pointer, char *str, int i);
void			ft_free_stack(t_stack_node **stack);
t_stack_node	*check_av(int ac, char **av, t_ind *ind);
void			stack_init(t_stack_node **a, char **av, t_stack_node *tab);
t_verif			ft_atol(char *str);
t_ind			complete_indicator(t_stack_node *tab, int tot);
int				sorted(t_stack_node **a);
int				real_sorted(t_stack_node **stack);
int				count_node(t_stack_node **stack);
void			init_tab(int *tab);
void			complete_tab(int tab[10], int elem);
int				in_tab(int elem, int tab[10]);
int				tiny_list(t_stack_node **a, t_stack_node **b, int elem);
void			bubble_sort(t_stack_node *tab, int elem, t_ind *ind);
int				sort_med(t_stack_node **a, t_stack_node **b, int tot, int *tab);
int				sort_in_stack(t_stack_node **a, t_stack_node **b, int tot_elem);
int				rotate_sort(t_stack_node **a, t_stack_node **b, int tot_elem);
int				sort(t_stack_node **a, t_stack_node **b, t_ind ind);

//Movements
int				sa(t_stack_node **a);
int				sb(t_stack_node **b);
int				ss(t_stack_node **a, t_stack_node **b);
int				pa(t_stack_node **a, t_stack_node **b);
int				pb(t_stack_node **b, t_stack_node **a);
int				ra(t_stack_node **a);
int				rb(t_stack_node **b);
int				rr(t_stack_node **a, t_stack_node **b);
int				rra(t_stack_node **a);
int				rrb(t_stack_node **b);
int				rrr(t_stack_node **a, t_stack_node **b);

#endif