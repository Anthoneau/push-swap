/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoldber <agoldber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 20:03:58 by agoldber          #+#    #+#             */
/*   Updated: 2024/09/28 18:49:46 by agoldber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	do_rev_min(t_stack_node **stack, int min, int count)
{
	int				node;
	t_stack_node	*current;

	node = 0;
	current = *stack;
	while (node < count)
	{
		if (current->pos == min)
		{
			if (node <= count / 2)
				return (1);
			else
				return (0);
		}
		if (current->next)
			current = current->next;
		node++;
	}
	return (1);
}

static int	search_pos(t_stack_node **stack, int pos)
{
	t_stack_node	*current;

	current = *stack;
	while (current)
	{
		if (current->pos == pos)
			return (1);
		if (current->next)
			current = current->next;
		else
			break ;
	}
	return (0);
}

static void	put_above(t_stack_node **a, t_stack_node **b, int *pos)
{
	while ((*b)->pos != *pos)
	{
		if ((*b)->pos == *pos + 2 || (*b)->pos == *pos + 1)
			pa(a, b);
		if ((*b)->pos != *pos && do_rev_min(b, *pos, count_node(b)))
			rb(b);
		else if ((*b)->pos != *pos)
			rrb(b);
	}
	pa(a, b);
	ra(a);
	*pos += 1;
}

void	rotate_sort(t_stack_node **a, t_stack_node **b, int tot_elem)
{
	int	pos;

	pos = 0;
	while (!real_sorted(a) || count_node(a) != tot_elem)
	{
		if ((*a)->pos == pos || ((*a)->next && (*a)->next->pos == pos))
		{
			if ((*a)->next && (*a)->next->pos == pos)
				sa(a);
			ra(a);
			pos++;
		}
		if ((*b) && search_pos(b, pos))
			put_above(a, b, &pos);
		else if ((*a)->pos == pos)
		{
			ra(a);
			pos++;
		}
		else if ((*a)->pos != 0)
			pb(b, a);
	}
}
