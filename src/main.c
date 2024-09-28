/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoldber <agoldber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:54:37 by agoldber          #+#    #+#             */
/*   Updated: 2024/09/28 19:12:04 by agoldber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;
	int				tot_elem;
	t_stack_node	*tab;

	a = NULL;
	b = NULL;
	tot_elem = 0;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		ft_exit("", 1);
	if (ac == 2)
		av = ft_split(av[1], ' ');
	if (!av)
		ft_exit("Error\n", 1);
	tab = check_av(ac, av, &tot_elem);
	bubble_sort(tab, tot_elem);
	stack_init(&a, av, tab);
	free(tab);
	sort(&a, &b, tot_elem);
	return (0);
}
