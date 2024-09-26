/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoldber <agoldber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 18:33:01 by agoldber          #+#    #+#             */
/*   Updated: 2024/09/23 20:28:42 by agoldber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	sort_two(t_stack_node **stack)
{
	if (!sorted(stack))
	{
		if ((*stack)->pos > (*stack)->next->pos)
			sa(stack);
		return (1);
	}
	return (0);
}

static int	sort_three(t_stack_node **s)
{
	int	count;

	count = 0;
	while (!sorted(s))
	{
		if ((*s)->pos < (*s)->next->pos
			&& (*s)->pos < (*s)->next->next->pos)
			count += sa(s);
		else if ((*s)->pos > (*s)->next->pos
			&& (*s)->pos > (*s)->next->next->pos)
			count += ra(s);
		else if ((*s)->pos > (*s)->next->pos)
			count += sa(s);
		else
			count += rra(s);
	}
	return (count);
}

//static int	min_max(t_stack_node **b)
//{
//	if ((*b)->pos == 4 || (*b)->pos == 0)
//		return (1);
//	return (0);
//}

static int	sort_five(t_stack_node **a, t_stack_node **b)
{
	int	count;

	count = 0;
	if (!sorted(a))
	{
		while (count_node(b) != 2)
		{
			if ((*a)->pos == 0 || (*a)->pos == 1)
				count += pb(b, a);
			else
				count += ra(a);
		}
		count += sort_three(a);
		if ((*b)->pos < (*b)->next->pos)
			count += sb(b);
		count += pa(a, b);
		count += pa(a, b);
	}
	return (count);
}

int	tiny_list(t_stack_node **a, t_stack_node **b, int elem)
{
	int	count;

	count = 0;
	if (elem == 2)
		count += sort_two(a);
	else if (elem == 3)
		count += sort_three(a);
	else if (elem == 5)
		count += sort_five(a, b);
	return (count);
}
