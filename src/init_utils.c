/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odib <odib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 11:00:04 by odib              #+#    #+#             */
/*   Updated: 2024/07/13 16:16:30 by odib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	curr_index(t_stack_node *list)
{
	int	i;
	int	median;

	i = 0;
	if (!list)
		return ;
	median = list_length(list) / 2;
	while (list)
	{
		list->index = i;
		if (i <= median)
			list->above_median = true;
		else
			list->above_median = false;
		list = list->next;
		i++;
	}
}

void	set_target_a(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*curr_b;
	t_stack_node	*target_node;
	long			best_index;

	while (a)
	{
		best_index = LONG_MIN;
		curr_b = b;
		while (curr_b)
		{
			if (curr_b->nbr < a->nbr && curr_b->nbr > best_index)
			{
				best_index = curr_b->nbr;
				target_node = curr_b;
			}
			curr_b = curr_b->next;
		}
		if (best_index == LONG_MIN)
			a->target_node = find_max(b);
		else
			a->target_node = target_node;
		a = a->next;
	}
}

void	cost_of_a(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = list_length(a);
	len_b = list_length(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!(a->above_median))
			a->push_cost = len_a - (a->index);
		if (a->target_node->above_median)
			a->push_cost += a->target_node->index;
		else
			a->push_cost += len_b - (a->target_node->index);
		a = a->next;
	}
}

void	set_cheapest(t_stack_node *list)
{
	long			cheapest;
	t_stack_node	*cheapest_node;

	if (!list)
		return ;
	cheapest = LONG_MAX;
	while (list)
	{
		if (list->push_cost < cheapest)
		{
			cheapest = list->push_cost;
			cheapest_node = list;
		}
		list = list->next;
	}
	cheapest_node->cheapest = true;
}

t_stack_node	*get_cheapest_node(t_stack_node *list)
{
	if (!list)
		return (NULL);
	while (list)
	{
		if (list->cheapest)
			return (list);
		list = list->next;
	}
	return (NULL);
}
