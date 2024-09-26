/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoldber <agoldber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 19:50:48 by agoldber          #+#    #+#             */
/*   Updated: 2024/09/26 00:54:39 by agoldber         ###   ########.fr       */
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

static int	rotate(t_stack_node **stack)
{
	t_stack_node	*current;

	current = find_last_node(*stack);
	if (current == NULL)
		return (0);
	current->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	current->next->prev = current;
	current->next->next = NULL;
	return (1);
}

int	ra(t_stack_node **a)
{
	if (rotate(a))
	{
		ft_printf("ra\n");
		return (1);
	}
	return (0);
}

int	rb(t_stack_node **b)
{
	if (rotate(b))
	{
		ft_printf("rb\n");
		return (1);
	}
	return (0);
}

int	rr(t_stack_node **a, t_stack_node **b)
{
	if (rotate(a) && rotate(b))
	{
		ft_printf("rr\n");
		return (1);
	}
	return (0);
}
