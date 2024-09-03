/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoldber <agoldber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:45:06 by agoldber          #+#    #+#             */
/*   Updated: 2024/09/02 20:37:08 by agoldber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void    push(t_stack_node **dst, t_stack_node **src)
{
    t_stack_node    *push;
	int				i;

    if (*src)
    {
		i = 0;
        push = *src;
		if ((*src)->next)
		{
			*src = (*src)->next;
        	(*src)->prev = NULL;
			i = 1;
		}
        if (*dst)
        {
            (*dst)->prev = push;
            push->next = *dst;
            *dst = push;
        }
        else
        {
            *dst = push;
            push->next = NULL;
        }
		if (!i)
			*src = NULL;
    }
}

void	pa(t_stack_node **a, t_stack_node **b)
{
	push(a, b);
}

void	pb(t_stack_node **b, t_stack_node **a)
{
	push(b, a);
}
