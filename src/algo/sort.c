/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoldber <agoldber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 17:46:45 by agoldber          #+#    #+#             */
/*   Updated: 2024/09/26 17:11:59 by agoldber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_median(int tot, int divisor, int *tab)
{
	int	median;
	int	i;

	median = tot;
	i = divisor;
	if (divisor == 1)
	{
		median /= 2;
		tab[0] = median;
		return (median);
	}
	while (divisor)
	{
		median /= 2;
		divisor--;
	}
	median = tot - median;
	tab[i - 1] = median;
	return (median);
}

static int	push_lower(t_stack_node **a, t_stack_node **b, int pos, int tot)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (i != tot - pos)
	{
		if ((*a)->pos < pos)
		{
			count += pb(b, a);
			i++;
		}
		else if (count_node(b) >= 2 && (*b)->pos < tot / 4)
			count += rr(a, b);
		else if (count_node(b) >= 4 && (*b)->next->pos < tot / 4)
		{
			count += sb(b);
			count += rr(a, b);
		}
		else
			count += ra(a);
	}
	return (count);
}

int	sort_med(t_stack_node **a, t_stack_node **b, int tot, int *tab)
{
	int		count;
	int		median;
	int		i;

	count = 0;
	i = 1;
	while (count_node(a) > 1)
	{
		median = find_median(tot, i, tab);
		if (count_node(a) >= tot / 20)
			count += push_lower(a, b, median, tot);
		else
			break ;
		i++;
	}
	return (count);
}

int	sort(t_stack_node **a, t_stack_node **b, t_ind ind)
{
	int	count;
	int	tab[20];

	count = 0;
	if (ind.tot_elem <= 5)
		count += tiny_list(a, b, ind.tot_elem);
	else
	{
		if (!real_sorted(a))
		{
			init_tab(tab);
			count += sort_med(a, b, ind.tot_elem, tab);
			complete_tab(tab, ind.tot_elem / 10);
			count += sort_in_stack(a, b, ind.tot_elem);
			count += rotate_sort(a, b, ind.tot_elem);
		}
	}
	return (count);
}
