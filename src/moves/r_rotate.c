/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoldber <agoldber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:45:08 by agoldber          #+#    #+#             */
/*   Updated: 2024/09/26 00:54:49 by agoldber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack_node	*find_last_node(t_stack_node *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->next)
			stack = stack->next;
		else if (i != 0)
			return (stack);
		else
			break ;
		i++;
	}
	return (NULL);
}

static int	r_rotate(t_stack_node **stack)
{
	t_stack_node	*current;

	current = find_last_node(*stack);
	if (current == NULL)
		return (0);
	current->prev->next = NULL;
	current->prev = NULL;
	(*stack)->prev = current;
	current->next = *stack;
	*stack = (*stack)->prev;
	return (1);
}

int	rra(t_stack_node **a)
{
	if (r_rotate(a))
	{
		ft_printf("rra\n");
		return (1);
	}
	return (0);
}

int	rrb(t_stack_node **b)
{
	if (r_rotate(b))
	{
		ft_printf("rrb\n");
		return (1);
	}
	return (0);
}

int	rrr(t_stack_node **a, t_stack_node **b)
{
	if (r_rotate(a) && r_rotate(b))
	{
		ft_printf("rrr\n");
		return (1);
	}
	return (0);
}
