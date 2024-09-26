/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoldber <agoldber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:54:37 by agoldber          #+#    #+#             */
/*   Updated: 2024/09/26 13:58:24 by agoldber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;
	t_ind			ind;
	t_stack_node	*tab;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		ft_exit("", 1);
	if (ac == 2)
		av = ft_split(av[1], ' ');
	if (!av)
		ft_exit("Error\n", 1);
	tab = check_av(ac, av, &ind);
	bubble_sort(tab, ind.tot_elem, &ind);
	stack_init(&a, av, tab);
	sort(&a, &b, ind);
	return (0);
}
