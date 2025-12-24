/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoldber <agoldber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:54:37 by agoldber          #+#    #+#             */
/*   Updated: 2024/10/10 18:42:11 by agoldber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;
	int				tot_elem;
	char			**num;
	t_stack_node	*arr;

	a = NULL;
	b = NULL;
	num = NULL;
	tot_elem = 0;
	if (ac == 1 || (ac == 2 && !av[1][0]) || (ac == 2 && ft_isspace(av[1])))
		ft_exit("", 0);
	arr = check_av(ac, av, &tot_elem, &num);
	bubble_sort(arr, tot_elem);
	stack_init(&a, &num, arr);
	free(arr);
	ft_free_double_arr(num);
	sort(&a, &b, tot_elem);
	ft_free_stack(&a);
	return (0);
}
