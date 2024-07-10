/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odib <odib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:37:51 by odib              #+#    #+#             */
/*   Updated: 2024/07/09 17:20:59 by odib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol(const char *s)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1; 
	while (*s == ' ' || *s == '\t' || *s == '\n' || \
			*s == '\r' || *s == '\f' || *s == '\v')
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

void    append_node(t_stack_node **list, int value)
{
    t_stack_node    *node;
    t_stack_node    *last_node;

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

void    init_stack_a(t_stack_node **a, char **av)
{
    long    value;
    int     i;

    i = 0;
    while (av[i])
    {
        if (is_error_impliment(av[i]))
            free_on_errors(a);
        value = ft_atol(av[i]);
        if (value > INT_MAX || value < INT_MIN)
            free_on_errors(a);
        if  (is_duplicate(a, value))
            free_on_errors(a);
        append_node(a,(int)value);
        i++;
    }
}
