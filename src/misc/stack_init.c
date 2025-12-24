/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoldber <agoldber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 22:25:45 by agoldber          #+#    #+#             */
/*   Updated: 2024/10/10 17:12:02 by agoldber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	add_in_stack(t_stack_node **a, t_stack_node *node)
{
	t_stack_node	*current;

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

static int	new_node(t_stack_node **a, int value, t_stack_node *arr)
{
	t_stack_node	*node;
	int				i;

	i = 0;
	node = malloc(sizeof(t_stack_node));
	if (!node)
	{
		free(arr);
		ft_free_stack(a);
		return (0);
	}
	node->value = value;
	while (arr[i].value != node->value)
		i++;
	node->pos = arr[i].pos;
	node->next = NULL;
	add_in_stack(a, node);
	return (1);
}

void	stack_init(t_stack_node **a, char ***num, t_stack_node *arr)
{
	int		i;
	t_verif	nb;

	i = 0;
	while (num[0][i])
	{
		nb = ft_atol(num[0][i]);
		if (!new_node(a, nb.value, arr))
		{
			ft_free_double_arr(*num);
			ft_exit("Error\n", 1);
		}
		i++;
	}
}
