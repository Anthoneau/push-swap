/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoldber <agoldber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 22:25:45 by agoldber          #+#    #+#             */
/*   Updated: 2024/08/31 01:08:47 by agoldber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

static void	add_in_stack(t_stack_node **a, t_stack_node *node)
{
	t_stack_node *current;

	if (!*a)
	{
		node->prev = NULL;
		*a = node;
	}
	else
	{
		current = *a;
		while (current->next)
			current = current->next;
		current->next = node;
		node->prev = current;
	}
}

static void	new_lst(t_stack_node **a, int value)
{
	t_stack_node	*node;
	t_stack_node	*current;

	node = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!node)
	{
		ft_free_stack(&*a);
		ft_exit("Error creating the node\n", -1);
	}
	if (!value)
	{
		free(node);
		ft_free_stack(&*a);
		ft_exit("Error creating the node\n", -1);
	}
	else
		node->value = value;
	node->next = NULL;
	add_in_stack(&*a, node);
}

void	stack_init(t_stack_node **a, char **av)
{
	int		i;
	t_verif	nb;

	i = 0;
	while (av[i])
	{
		nb = ft_atol(av[i]);
		new_lst(&*a, (int)nb.value);
		i++;
	}
}
