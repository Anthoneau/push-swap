/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoldber <agoldber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 17:46:45 by agoldber          #+#    #+#             */
/*   Updated: 2024/09/30 09:49:45 by agoldber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_median(int tot, int divisor)
{
	int	median;

	median = tot;
	if (divisor == 1)
	{
		median /= 2;
		return (median);
	}
	while (divisor)
	{
		median /= 2;
		divisor--;
	}
	median = tot - median;
	return (median);
}

static int	verif_stack(t_stack_node **a, int pos)
{
	t_stack_node	*current;

	current = *a;
	while (current->next)
	{
		if (current->pos < pos)
			return (1);
		if (current->next)
			current = current->next;
	}
	return (0);
}

static void	push_lower(t_stack_node **a, t_stack_node **b, int pos, int tot)
{
	int	i;

	i = 0;
	while (i != tot - pos)
	{
		if (!verif_stack(a, pos))
			break ;
		if ((*a)->pos < pos)
		{
			pb(b, a);
			i++;
		}
		else if (count_node(b) >= 2 && (*b)->pos < tot / 4)
			rr(a, b);
		else if (count_node(b) >= 4 && (*b)->next->pos < tot / 4)
		{
			sb(b);
			rr(a, b);
		}
		else
			ra(a);
	}
}

void	sort_med(t_stack_node **a, t_stack_node **b, int tot)
{
	int		median;
	int		i;

	i = 1;
	while (count_node(a) > 2)
	{
		median = find_median(tot, i);
		if (median == tot)
			break ;
		if (count_node(a) >= tot / 20)
			push_lower(a, b, median, tot);
		else
			break ;
		i++;
	}
}

void	sort(t_stack_node **a, t_stack_node **b, int tot_elem)
{
	if (tot_elem <= 5)
		tiny_list(a, b, tot_elem);
	else
	{
		if (!real_sorted(a))
		{
			sort_med(a, b, tot_elem);
			sort_in_stack(a, b, tot_elem);
			rotate_sort(a, b, tot_elem);
		}
	}
}
