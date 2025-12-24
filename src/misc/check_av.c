/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_av.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoldber <agoldber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 19:15:04 by agoldber          #+#    #+#             */
/*   Updated: 2024/10/10 17:31:25 by agoldber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	not_void(char *av)
{
	int	num;

	num = 0;
	while (*av)
	{
		if (ft_isdigit(*av))
			num++;
		else if (ft_isalpha(*av))
		{
			num = 0;
			break ;
		}
		av++;
	}
	return (num);
}

static char	**fill_num(int ac, char **av)
{
	char	**num;
	int		i;
	int		j;

	if (ac == 2 && !not_void(av[1]))
		return (NULL);
	if (ac == 2)
		return (ft_split(av[1], ' '));
	num = malloc(ac * sizeof(char *));
	if (!num)
		return (NULL);
	i = 1;
	j = 0;
	while (av[i])
	{
		num[j] = ft_strdup(av[i]);
		if (!num[j])
			return (ft_free_double_arr(num), NULL);
		i++;
		j++;
	}
	num[j] = NULL;
	return (num);
}

static int	check_double(t_stack_node *arr, int i)
{
	int	j;

	if (i > 0)
	{
		j = i - 1;
		while (j >= 0)
		{
			if (arr[i].value == arr[j].value)
				return (0);
			j--;
		}
	}
	return (1);
}

static t_stack_node	*check_numbers(char **num, int *tot_elem)
{
	int				i;
	t_verif			nb;
	t_stack_node	*arr;

	i = 0;
	while (num[i])
		i++;
	arr = malloc(i * sizeof(t_stack_node));
	if (!arr)
		return (NULL);
	i = 0;
	while (num[i])
	{
		nb = ft_atol(num[i]);
		if (nb.err == -1)
			return (free(arr), NULL);
		arr[i].value = nb.value;
		if (!check_double(arr, i))
			return (free(arr), NULL);
		i++;
	}
	*tot_elem = i;
	return (arr);
}

t_stack_node	*check_av(int ac, char **av, int *tot_elem, char ***num)
{
	t_stack_node	*arr;

	*num = fill_num(ac, av);
	if (!*num)
		ft_exit("Error\n", 1);
	arr = check_numbers(*num, tot_elem);
	if (!arr)
	{
		ft_free_double_arr(*num);
		ft_exit("Error\n", 1);
	}
	return (arr);
}
