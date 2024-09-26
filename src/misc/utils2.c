/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoldber <agoldber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 19:56:47 by agoldber          #+#    #+#             */
/*   Updated: 2024/09/26 13:58:19 by agoldber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	real_sorted(t_stack_node **stack)
{
	t_stack_node	*current;
	int				pos1;

	current = *stack;
	pos1 = 0;
	while (1)
	{
		if (current->pos != pos1)
			return (0);
		pos1++;
		if (current->next)
			current = current->next;
		else
			break ;
	}
	return (1);
}

int	count_node(t_stack_node **stack)
{
	int				count;
	t_stack_node	*current;

	count = 0;
	current = *stack;
	if (current == NULL)
		return (0);
	while (current)
	{
		if (current->next)
		{
			current = current->next;
			count++;
		}
		else
			break ;
	}
	return (count + 1);
}

void	init_tab(int *tab)
{
	int	i;

	i = 0;
	while (i++ <= 20)
		tab[i] = 0;
}

void	complete_tab(int tab[10], int elem)
{
	int	i;
	int	multiplicator;

	i = 0;
	multiplicator = 1;
	while (i <= 10)
	{
		tab[i] = elem * multiplicator;
		i++;
		multiplicator++;
	}
}

int	in_tab(int elem, int tab[10])
{
	int	i;

	i = 0;
	if (elem < tab[0])
		return (0);
	while (i <= 10)
	{
		if (elem == tab[i])
			return (1);
		i++;
	}
	return (0);
}
