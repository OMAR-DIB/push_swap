/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odib <odib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 11:00:04 by odib              #+#    #+#             */
/*   Updated: 2024/07/13 17:20:46 by odib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	push(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*temp;

	if (!(*b))
		return ;
	temp = *b;
	*b = (*b)->next;
	if (*b)
		(*b)->prev = NULL;
	temp->prev = NULL;
	if (!*a)
	{
		*a = temp;
		temp->next = NULL;
	}
	else
	{
		temp->next = *a;
		temp->next->prev = temp;
		*a = temp;
	}
}

void	pa(t_stack_node **a, t_stack_node **b, bool print)
{
	push(a, b);
	if (print)
		ft_printf("pa\n");
}

void	pb(t_stack_node **b, t_stack_node **a, bool print)
{
	push(b, a);
	if (print)
		ft_printf("pb\n");
}
