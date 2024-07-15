/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odib <odib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 11:00:04 by odib              #+#    #+#             */
/*   Updated: 2024/07/13 10:44:54 by odib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	swap(t_stack_node **list)
{
	if (!*list || !(*list)->next)
		return ;
	*list = (*list)->next;
	(*list)->prev->prev = *list;
	(*list)->prev->next = (*list)->next;
	if ((*list)->next)
		(*list)->next->prev = (*list)->prev;
	(*list)->next = (*list)->prev;
	(*list)->prev = NULL;
}

void	trio_sort(t_stack_node **list)
{
	t_stack_node	*temp;

	temp = find_max(*list);
	if (temp == *list)
		ra(list, true);
	else if ((*list)->next == temp)
		rra(list, true);
	if ((*list)->nbr > (*list)->next->nbr)
		sa(list, true);
}

void	sa(t_stack_node **a, bool print)
{
	swap(a);
	if (print)
		ft_printf("sa\n");
}

void	sb(t_stack_node **b, bool print)
{
	swap(b);
	if (print)
		ft_printf("sb\n");
}

void	ss(t_stack_node **a, t_stack_node **b, bool print)
{
	swap(a);
	swap(b);
	if (print)
		ft_printf("ss\n");
}
