/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoldber <agoldber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 18:39:37 by agoldber          #+#    #+#             */
/*   Updated: 2024/09/23 20:28:58 by agoldber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check(t_stack_node *node)
{
	int	i;

	i = 0;
	while (node != NULL)
	{
		node = node->next;
		i++;
	}
	if (i >= 2)
		return (1);
	else
		return (0);
}

static int	swap(t_stack_node **stack)
{
	t_stack_node	*first;
	t_stack_node	*second;
	t_stack_node	*current;

	current = *stack;
	first = NULL;
	second = NULL;
	if (check(*stack))
	{
		first = current;
		second = current->next;
		first->prev = first->next;
		if (second->next)
		{
			first->next = second->next;
			first->next->prev = first;
		}
		else
			first->next = NULL;
		second->next = first;
		second->prev = NULL;
		*stack = second;
		return (1);
	}
	return (0);
}

int	sa(t_stack_node **a)
{
	if (swap(a))
	{
		ft_printf("sa\n");
		return (1);
	}
	return (0);
}

int	sb(t_stack_node **b)
{
	if (swap(b))
	{
		ft_printf("sb\n");
		return (1);
	}
	return (0);
}

int	ss(t_stack_node **a, t_stack_node **b)
{
	if (swap(a) && swap(b))
	{
		ft_printf("ss\n");
		return (1);
	}
	return (0);
}
