/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoldber <agoldber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:36:13 by agoldber          #+#    #+#             */
/*   Updated: 2024/09/28 19:09:42 by agoldber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_in_tab(t_stack_node *tab, int i, int j)
{
	int	temp;

	temp = tab[i].value;
	tab[i].value = tab[j].value;
	tab[j].value = temp;
}

void	bubble_sort(t_stack_node *tab, int tot_elem)
{
	int	i;
	int	j;

	i = 0;
	while (i < tot_elem)
	{
		j = i + 1;
		while (j < tot_elem)
		{
			if (tab[i].value > tab[j].value)
				swap_in_tab(tab, i, j);
			j++;
		}
		tab[i].pos = i;
		i++;
	}
}
