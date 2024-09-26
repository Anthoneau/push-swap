/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoldber <agoldber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:36:13 by agoldber          #+#    #+#             */
/*   Updated: 2024/09/23 20:28:06 by agoldber         ###   ########.fr       */
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

static void	get_ind(t_stack_node *tab, t_ind *ind)
{
	ind->min_val = tab[0].value;
	ind->min_pos = tab[0].pos;
	ind->max_val = tab[ind->tot_elem - 1].value;
	ind->max_pos = tab[ind->tot_elem - 1].pos;
}

void	bubble_sort(t_stack_node *tab, int elem, t_ind *ind)
{
	int	i;
	int	j;

	i = 0;
	while (i < elem)
	{
		j = i + 1;
		while (j < elem)
		{
			if (tab[i].value > tab[j].value)
				swap_in_tab(tab, i, j);
			j++;
		}
		tab[i].pos = i;
		i++;
	}
	get_ind(tab, ind);
}
