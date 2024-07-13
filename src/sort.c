/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odib <odib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 11:00:04 by odib              #+#    #+#             */
/*   Updated: 2024/07/13 16:30:08 by odib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest;

	cheapest = get_cheapest_node(*a);
	if (cheapest->above_median && cheapest->target_node->above_median)
		rotate_both(a, b, cheapest);
	else if (!(cheapest->above_median)
		&& !(cheapest->target_node->above_median))
		rev_rotate_both(a, b, cheapest);
	move_to_top(a, cheapest, 'a');
	move_to_top(b, cheapest->target_node, 'b');
	pb(b, a, true);
}

void	move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	move_to_top(a, (*b)->target_node, 'a');
	pa(a, b, true);
}

void	min_on_top(t_stack_node **a)
{
	t_stack_node	*min;

	min = find_min(*a);
	while ((*a)->nbr != min->nbr)
	{
		if (min->above_median)
			ra(a, true);
		else
			rra(a, true);
	}
}

void	sort(t_stack_node **a, t_stack_node **b)
{
	int	len_a;

	len_a = list_length(*a);
	if (len_a-- > 3 && !is_sorted(*a))
		pb(b, a, true);
	if (len_a-- > 3 && !is_sorted(*a))
		pb(b, a, true);
	while (len_a > 3 && !is_sorted(*a))
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
		len_a--;
	}
	trio_sort(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	curr_index(*a);
	min_on_top(a);
}
