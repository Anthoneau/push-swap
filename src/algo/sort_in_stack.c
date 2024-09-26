/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_in_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoldber <agoldber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 20:04:58 by agoldber          #+#    #+#             */
/*   Updated: 2024/09/26 16:45:03 by agoldber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	do_rev_max(t_stack_node **stack, int above, int count)
{
	int				node;
	t_stack_node	*current;
	int				pos1;
	int				pos2;

	node = 0;
	current = *stack;
	pos1 = 0;
	pos2 = 0;
	while (node < count)
	{
		if (current->pos >= above && node <= count / 2 && current->pos >= pos1)
			pos1 = current->pos;
		else if (current->pos >= above && current->pos >= pos2)
			pos2 = current->pos;
		if (current->next)
			current = current->next;
		else
			break ;
		node++;
	}
	if (pos1 >= pos2)
		return (1);
	return (0);
}

static int	change_median(t_stack_node **stack, int median)
{
	t_stack_node	*current;

	current = *stack;
	if (!current)
		return (0);
	while (current->next)
	{
		if (current->pos >= median)
			return (0);
		current = current->next;
	}
	return (1);
}

int	sort_in_stack(t_stack_node **a, t_stack_node **b, int tot_elem)
{
	int	count;
	int	median;

	count = 0;
	median = tot_elem / 10;
	while (*b)
	{
		if ((*b)->pos >= tot_elem - median)
			count += pa(a, b);
		else
		{
			if (do_rev_max(b, tot_elem - median, count_node(b)))
				count += rb(b);
			else
				count += rrb(b);
		}
		if (change_median(b, tot_elem - median))
			median += tot_elem / 10;
		if (count_node(b) <= tot_elem / 20)
			break ;
	}
	return (count);
}
