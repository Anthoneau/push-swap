/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoldber <agoldber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:54:37 by agoldber          #+#    #+#             */
/*   Updated: 2024/08/20 19:31:13 by agoldber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	count_arg(char **av)
{
	int	count;
	int	i;
	int	j;
	int	k;

	count = 0;
	i = 1;
	j = 0;
	k = 0;
	while(av[i])
	{
		while(av[i][j])
		{
			if (ft_isalpha(av[i][j]))
				ft_exit("Error\n", -1);
			if (ft_isdigit(av[i][j]) && k)
			{
				count++;
				k = 0;
			}
			else
				k = 1;
			j++;
		}
		i++;
	}
}

int	main(int argc, char **av)
{
	int	*tab_a;
	int	*tab_b;

	
	return (0);
}