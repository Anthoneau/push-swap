/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoldber <agoldber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 19:19:12 by agoldber          #+#    #+#             */
/*   Updated: 2024/09/04 16:44:15 by agoldber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

void	ft_exit(char *str, int i)
{
	ft_putstr_fd(str, 1);
	exit(i);
}

void	ft_freexit(void *pointer, char *str, int i)
{
	free(pointer);
	ft_exit(str, i);
}

void	ft_free_stack(t_stack_node **stack)
{
	t_stack_node *current;
	t_stack_node *to_free;

	current = *stack;
	while(current)
	{
		to_free = current;
		current = current->next;
		free(to_free);
	}
}

t_verif	ft_atol(char *str)
{
	t_verif		res;
	int			sign;

	res.value = 0;
	res.err = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str)
	{
		if (*str >= '0' || *str <= '9')
			res.value = res.value * 10 + (*str - '0');
		if (!ft_isdigit(*str))
			res.err = -1;
		str++;
	}
	res.value *= sign;
	if (res.value > INT_MAX || res.value < INT_MIN)
		res.err = -1;
	return (res);
}
