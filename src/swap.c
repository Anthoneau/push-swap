/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoldber <agoldber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 18:39:37 by agoldber          #+#    #+#             */
/*   Updated: 2024/09/04 15:17:49 by agoldber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	check(t_stack_node *node)
{
	int	i;

	i = 0;
	while(node != NULL)
	{
		node = node->next;
		i++;
	}
	if (i >= 2)
		return (1);
	else
		return (0);
}

static void    swap(t_stack_node **a)
{
    t_stack_node    *first;
    t_stack_node    *second;
    t_stack_node    *current;

    current = *a;
    first = NULL;
    second = NULL;
    if (check(*a))
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
    }
	*a = second;
}

void	sa(t_stack_node **a)
{
	swap(a);
}

void	sb(t_stack_node **b)
{
	swap(b);
}

void	ss(t_stack_node **a, t_stack_node **b)
{
	swap(a);
	swap(b);
}
