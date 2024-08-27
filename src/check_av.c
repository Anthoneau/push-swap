/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_av.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoldber <agoldber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 17:25:12 by agoldber          #+#    #+#             */
/*   Updated: 2024/08/27 18:20:01 by agoldber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

static int	check_numbers(char **av, int i)
{
	int	j;

	while  (av[i])
	{
		j = 0;
		while(av[i][j])
		{
			printf("%c", av[i][j]);
			if (!ft_isdigit(av[i][j]))
			{
				if (av[i][j] != '-' && av[i][j] != '+')
					return (0);
			}
			j++;
		}
		printf("\n");
		i++;
	}
	return (1);
}

void	check_av(int ac, char **av)
{
	if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		if (!check_numbers(av, 0))
			ft_exit("Wrong arguments !dans check_Av\n", -1);	
	}
	else
		if (!check_numbers(av, 1))
			ft_exit("Wrong arguments !dans check_Av\n", -1);
}
