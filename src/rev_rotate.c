/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odib <odib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 11:00:04 by odib              #+#    #+#             */
/*   Updated: 2024/07/13 13:54:55 by odib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	rev_rotate(t_stack_node **list)
{
	t_stack_node	*last;

	if (!*list || !(*list)->next)
		return ;
	last = find_last_node(*list);
	last->prev->next = NULL;
	last->next = (*list);
	last->prev = NULL;
	(*list) = last;
	last->next->prev = last;
}

void	rev_rotate_both(t_stack_node **a, t_stack_node **b,
		t_stack_node *cheap_node)
{
	while (*b != cheap_node->target_node && *a != cheap_node)
		rrr(a, b, true);
	curr_index(*a);
	curr_index(*b);
}

void	rra(t_stack_node **a, bool print)
{
	rev_rotate(a);
	if (print)
		ft_printf("rra\n");
}

void	rrb(t_stack_node **b, bool print)
{
	rev_rotate(b);
	if (print)
		ft_printf("rrb\n");
}

void	rrr(t_stack_node **a, t_stack_node **b, bool print)
{
	rev_rotate(a);
	rev_rotate(b);
	if (print)
		ft_printf("rrr\n");
}