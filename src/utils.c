/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odib <odib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 11:12:44 by odib              #+#    #+#             */
/*   Updated: 2024/07/11 17:03:34 by odib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

t_stack_node	*find_last_node(t_stack_node *a)
{
	if (!a)
		return (NULL);
	while (a -> next)
	{
		a = a->next;
	}
	return (a);
}

int	is_sorted(t_stack_node	*list)
{
	if (!list)
		return (0);
	while (list->next)
	{
		if (list->nbr > list->next->nbr)
			return (0);
		list = list->next;
	}
	return (1);
}

t_stack_node	*find_min(t_stack_node	*list)
{
	long			min;
	t_stack_node	*min_res;

	if (!list)
		return (NULL);
	min = LONG_MAX;
	while (list)
	{
		if (list->nbr < min)
		{
			min = list->nbr;
			min_res = list;
		}
		list = list->next;
	}
	return (min_res);
}

t_stack_node	*find_max(t_stack_node *list)
{
	long			max;
	t_stack_node	*max_res;

	if (!list)
		return (NULL);
	max = 0;
	while (list)
	{
		if (list->nbr > max)
		{
			max = list->nbr;
			max_res = list;
		}
		list = list->next;
	}
	return (max_res);
}

int	list_length(t_stack_node	*list)
{
	int	i;

	if (!list)
		return (0);
	i = 0;
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}
