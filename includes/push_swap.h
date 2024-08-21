/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoldber <agoldber@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 19:21:32 by agoldber          #+#    #+#             */
/*   Updated: 2024/08/21 16:31:11 by agoldber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

typedef struct s_list_node {
	int	value;
	int	pos;
	s_list_node *prev;
	s_list_node *next;
}	t_node;

void	ft_exit(char *str, int n);

#endif