/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoldber <agoldber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 19:50:48 by agoldber          #+#    #+#             */
/*   Updated: 2024/09/04 14:23:45 by agoldber         ###   ########.fr       */
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

static void    rotate(t_stack_node **stack)
{
    t_stack_node    *current;

    current = find_last_node(*stack);
    if (current == NULL)
        return ;
    current->next = *stack;
    *stack = (*stack)->next;
    (*stack)->prev = NULL;
    current->next->prev = current;
    current->next->next = NULL;
}

void	ra(t_stack_node **a)
{
	rotate(&a);
}

void	rb(t_stack_node **b)
{
	rotate(&b);
}

void	rr(t_stack_node **a, t_stack_node **b)
{
	ra(&a);
	rb(&b);
}
