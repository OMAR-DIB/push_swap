/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odib <odib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 11:00:04 by odib              #+#    #+#             */
/*   Updated: 2024/07/13 16:26:51 by odib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	rotate(t_stack_node **list)
{
	t_stack_node	*last;

	if (!*list || !(*list)->next)
		return ;
	last = find_last_node(*list);
	last->next = (*list);
	(*list) = (*list)->next;
	(*list)->prev = NULL;
	last->next->prev = last;
	last->next->next = NULL;
}

void	rotate_both(t_stack_node **a, t_stack_node **b,
		t_stack_node *cheap_node)
{
	while (*b != cheap_node->target_node && *a != cheap_node)
		rr(a, b, true);
	curr_index(*a);
	curr_index(*b);
}

void	ra(t_stack_node **a, bool print)
{
	rotate(a);
	if (print)
		ft_printf("ra\n");
}

void	rb(t_stack_node **b, bool print)
{
	rotate(b);
	if (print)
		ft_printf("rb\n");
}

void	rr(t_stack_node **a, t_stack_node **b, bool print)
{
	rotate(a);
	rotate(b);
	if (print)
		ft_printf("rr\n");
}
