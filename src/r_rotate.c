/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoldber <agoldber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:45:08 by agoldber          #+#    #+#             */
/*   Updated: 2024/09/04 14:45:26 by agoldber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_stack_node    *find_last_node(t_stack_node *stack)
{
    int i;

    i = 0;
    while(stack)
    {
        if (!stack->next && i != 0)
            return (stack);
        stack = stack->next;
        i++;
    }
    return (NULL);
}

static void    r_rotate(t_stack_node **stack)
{
    t_stack_node    *current;

    current = find_last_node(*stack);
    if (current == NULL)
        return ;
     current->prev->next = NULL;
    current->prev = NULL;
    (*stack)->prev = current;
    current->next = *stack;
    *stack = (*stack)->prev;
}

void	rra(t_stack_node **a)
{
	rotate(&a);
}

void	rrb(t_stack_node **b)
{
	rotate(&b);
}

void	rrr(t_stack_node **a, t_stack_node **b)
{
	ra(&a);
	rb(&b);
}
