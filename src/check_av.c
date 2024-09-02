/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_av.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoldber <agoldber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 17:25:12 by agoldber          #+#    #+#             */
/*   Updated: 2024/08/31 00:27:04 by agoldber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	del_prog_name(char **av)
{
	int	i;
	int	j;

	i = 0;
	while(av[i])
	{
		j = i + 1;
		if (av[j])
			av[i] = av[j];
		else
			av[i] = NULL;
		i++;
	}
}

static int	check_double(int *tab, int i)
{
	int	j;

	if (i > 0)
	{
		j = i - 1;
		while(j != 0)
		{
			if (tab[i] == tab[j])
				return(0);
			j--;
		}	
	}
	return (1);
}

static int	check_numbers(char **av)
{
	int		i;
	int		j;
	t_verif	nb;
	int		*tab;

	i = 0;
	while (av[i])
		i++;
	tab = malloc(i * sizeof(int));
	i = 0;
	while(av[i])
	{
		nb = ft_atol(av[i]);
		if (nb.err == -1)
			ft_freexit(tab, "Wrong argument!\n", -1);
		tab[i] = nb.value;
		if (!check_double(tab, i))
			ft_freexit(tab, "Wrong argument!\n", -1);
		i++;
	}
	free(tab);
	return (1);
}

void	check_av(int ac, char **av)
{
	if (ac == 2)
		av = ft_split(av[1], ' ');
	else
		del_prog_name(av);
	if (!(check_numbers(av)))
		ft_exit("Wrong arguments !\n", -1);
}
