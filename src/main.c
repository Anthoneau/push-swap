/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoldber <agoldber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:54:37 by agoldber          #+#    #+#             */
/*   Updated: 2024/09/04 16:43:24 by agoldber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

// static void	print_stack(t_stack_node *a)
// {
// 	printf("-------------------------------------------------------\n");
// 	printf("contenu de la pile :\n\n");
// 	while(a)
// 	{
// 		printf("|Noeud : %p\n|Valeur : %d\n|Adresse du suivant : %p\n|Adresse du précédent : %p\n\n", (void *)a, a->value, (void *)a->next, (void *)a->prev);
// 		a = a->next;
// 	}
// 	printf("-------------------------------------------------------\n");
// }

static void	print_tab(char **av)
{
	int i = 0;
	while (av[i])
	{
		printf("av[%d] : %s\n", i, av[i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_stack_node	*a;	
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		ft_exit("", -1);
	check_av(ac, av);
	print_tab(av);
	// stack_init(&a, av);
	// print_stacks(a, b);
	// sa(&a);
	// rra(&a);
	// print_stacks(a, b);
	return (0);
}
