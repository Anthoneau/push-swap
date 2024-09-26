/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoldber <agoldber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:45:06 by agoldber          #+#    #+#             */
/*   Updated: 2024/09/23 20:28:47 by agoldber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push(t_stack_node **dst, t_stack_node **src)
{
	t_stack_node	*push;

	if (*src)
	{
		push = *src;
		if ((*src)->next)
		{
			*src = (*src)->next;
			(*src)->prev = NULL;
		}
		else
			*src = NULL;
		if (*dst)
		{
			push->next = *dst;
			(*dst)->prev = push;
		}
		else
			push->next = NULL;
		*dst = push;
		return (1);
	}
	return (0);
}

int	pa(t_stack_node **a, t_stack_node **b)
{
	if (push(a, b))
	{
		ft_printf("pa\n");
		return (1);
	}
	return (0);
}

int	pb(t_stack_node **b, t_stack_node **a)
{
	if (push(b, a))
	{
		ft_printf("pb\n");
		return (1);
	}
	return (0);
}
