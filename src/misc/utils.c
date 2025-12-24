/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoldber <agoldber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 19:19:12 by agoldber          #+#    #+#             */
/*   Updated: 2024/10/06 19:24:46 by agoldber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit(char *str, int i)
{
	ft_putstr_fd(str, 2);
	exit(i);
}

void	ft_free_stack(t_stack_node **stack)
{
	t_stack_node	*current;
	t_stack_node	*to_free;

	current = *stack;
	while (current)
	{
		to_free = current;
		if (current->next)
			current = current->next;
		else
			break ;
		free(to_free);
	}
	if (to_free)
		free(to_free);
}

void	ft_free_double_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
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
