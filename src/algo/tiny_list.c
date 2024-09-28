/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoldber <agoldber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 18:33:01 by agoldber          #+#    #+#             */
/*   Updated: 2024/09/28 18:46:53 by agoldber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_two(t_stack_node **stack)
{
	if (!sorted(stack))
	{
		if ((*stack)->pos > (*stack)->next->pos)
			sa(stack);
	}
	return ;
}

static void	sort_three(t_stack_node **s)
{
	while (!sorted(s))
	{
		if ((*s)->pos < (*s)->next->pos
			&& (*s)->pos < (*s)->next->next->pos)
			sa(s);
		else if ((*s)->pos > (*s)->next->pos
			&& (*s)->pos > (*s)->next->next->pos)
			ra(s);
		else if ((*s)->pos > (*s)->next->pos)
			sa(s);
		else
			rra(s);
	}
}

static void	sort_four(t_stack_node **a, t_stack_node **b)
{
	if (!sorted(a))
	{
		while (count_node(b) != 1)
		{
			if (sorted(a))
				break ;
			if ((*a)->pos == 0)
				pb(b, a);
			else
				ra(a);
		}
		if (!sorted(a))
		{
			sort_three(a);
			pa(a, b);
		}
		else
			pa(a, b);
	}
}

static void	sort_five(t_stack_node **a, t_stack_node **b)
{
	if (!sorted(a))
	{
		while (count_node(b) != 2)
		{
			if ((*a)->pos == 0 || (*a)->pos == 1)
				pb(b, a);
			else
				ra(a);
		}
		sort_three(a);
		if ((*b)->pos < (*b)->next->pos)
			sb(b);
		pa(a, b);
		pa(a, b);
	}
}

void	tiny_list(t_stack_node **a, t_stack_node **b, int elem)
{
	if (elem == 2)
		sort_two(a);
	else if (elem == 3)
		sort_three(a);
	else if (elem == 4)
		sort_four(a, b);
	else if (elem == 5)
		sort_five(a, b);
}
