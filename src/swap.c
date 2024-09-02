/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoldber <agoldber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 18:39:37 by agoldber          #+#    #+#             */
/*   Updated: 2024/08/31 17:37:55 by agoldber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

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
		return (i);
	else
		return (0);
}

void	swap(t_stack_node **a)
{
	t_stack_node	*first;
	t_stack_node	*second;
	t_stack_node	*current;
	int				i;

	current = *a;
	first = NULL;
	second = NULL;
	if ((i = check(*a)) == 2)
	{
		first = current;
		current = current->next;
		first->prev = first->next;
		first->next = NULL;
		current->next = current->prev;
		current->prev = NULL;
		printf("Noeud Current : %p\nValue : %d\nAdresse next : %p\nAdresse prev : %p\n\n", (void *)current, current->value, (void *)current->next, (void *)first->prev);
		printf("Noeud First : %p\nValue : %d\nAdresse next : %p\nAdresse prev : %p\n\n", (void *)first, first->value, (void *)first->next, (void *)first->prev);
	}
}

