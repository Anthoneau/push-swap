/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_av.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoldber <agoldber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 17:25:12 by agoldber          #+#    #+#             */
/*   Updated: 2024/09/24 19:44:02 by agoldber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	del_prog_name(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = i + 1;
		if (av[j])
			av[i] = av[j];
		else
			av[i] = NULL;
		i++;
	}
}

static int	check_double(t_stack_node *tab, int i)
{
	int	j;

	if (i > 0)
	{
		j = i - 1;
		while (j >= 0)
		{
			if (tab[i].value == tab[j].value)
				return (0);
			j--;
		}
	}
	return (1);
}

static t_stack_node	*check_numbers(char **av, t_ind *ind)
{
	int				i;
	t_verif			nb;
	t_stack_node	*tab;

	i = 0;
	while (av[i])
		i++;
	tab = malloc(i * sizeof(t_stack_node));
	if (!tab)
		ft_exit("Error\n", 1);
	i = 0;
	while (av[i])
	{
		nb = ft_atol(av[i]);
		if (nb.err == -1)
			ft_freexit(tab, "Error\n", 1);
		tab[i].value = nb.value;
		if (!check_double(tab, i))
			ft_freexit(tab, "Error\n", 1);
		i++;
	}
	ind->tot_elem = i;
	return (tab);
}

t_stack_node	*check_av(int ac, char **av, t_ind *ind)
{
	t_stack_node	*tab;

	if (ac > 2)
		del_prog_name(av);
	tab = check_numbers(av, ind);
	return (tab);
}
