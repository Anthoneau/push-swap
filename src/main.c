/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoldber <agoldber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:54:37 by agoldber          #+#    #+#             */
/*   Updated: 2024/08/31 01:32:51 by agoldber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

static void	print_stack(t_stack_node *a)
{
	printf("contenu de la pile :\n\n");
	while(a)
	{
		printf("Noeud : %p\nValeur : %d\nAdresse du suivant : %p\nAdresse du précédent : %p\n\n", (void *)a, a->value, (void *)a->next, (void *)a->prev);
		a = a->next;
	}
}

int	main(int ac, char **av)
{
	t_stack_node	*a;	
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		ft_exit("Wrong argument!\n", -1);
	check_av(ac, av);
	stack_init(&a, av);
	print_stack(a);
	sa(&a);
	return (0);
}
