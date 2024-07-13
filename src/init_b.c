/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odib <odib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 11:00:04 by odib              #+#    #+#             */
/*   Updated: 2024/07/13 13:19:47 by odib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	set_target_b(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*curr_a;
	t_stack_node	*target_node;
	long			best_index;

	while (b)
	{
		best_index = LONG_MAX;
		curr_a = a;
		while (curr_a)
		{
			if (curr_a->nbr > b->nbr && curr_a->nbr < best_index)
			{
				best_index = curr_a->nbr;
				target_node = curr_a;
			}
			curr_a = curr_a->next;
		}
		if (best_index == LONG_MAX)
			b->target_node = find_min(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	init_nodes_b(t_stack_node *a, t_stack_node *b)
{
	curr_index(a);
	curr_index(b);
	set_target_b(a, b);
}
