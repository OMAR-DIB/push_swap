/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odib <odib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 11:08:42 by odib              #+#    #+#             */
/*   Updated: 2024/07/13 16:22:58 by odib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

long	ft_atol(const char *s)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*s == ' ' || *s == '\t' || *s == '\n' || *s == '\r' || *s == '\f'
		|| *s == '\v')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (ft_isdigit(*s))
		result = result * 10 + (*s++ - '0');
	return (result * sign);
}

void	append_node(t_stack_node **list, int value)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (!list)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	node->next = NULL;
	node->nbr = value;
	if (!(*list))
	{
		*list = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last_node(*list);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	init_stack_a(t_stack_node **a, char **av)
{
	long	value;
	int		i;

	i = 0;
	while (av[i])
	{
		if (is_error_impliment(av[i]))
			free_on_errors(a);
		value = ft_atol(av[i]);
		if (value > INT_MAX || value < INT_MIN)
			free_on_errors(a);
		if (is_duplicate(*a, (int)value))
			free_on_errors(a);
		append_node(a, (int)value);
		i++;
	}
}

void	move_to_top(t_stack_node **list, t_stack_node *top, char name)
{
	while (*list != top)
	{
		if (name == 'a')
		{
			if (top->above_median)
				ra(list, true);
			else
				rra(list, true);
		}
		else if (name == 'b')
		{
			if (top->above_median)
				rb(list, true);
			else
				rrb(list, true);
		}
	}
}

void	init_nodes_a(t_stack_node *a, t_stack_node *b)
{
	curr_index(a);
	curr_index(b);
	set_target_a(a, b);
	cost_of_a(a, b);
	set_cheapest(a);
}
