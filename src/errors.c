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

int is_error_impliment(char   *str)
{
    int i;

    i = 0;
    if (str[i] != '-' && str[i] != '+' && !(str[i] >= '0' && str[i] <= '9'))
        return (1);
    if ((str[i] == '-' || str[i] == '+') && !(str[i + 1] >= '0' && str[i + 1] <= '9'))
        return (1);
    while (str[i])
    {
        if ((str[i] >= '0' && str[i] <= '9'))
            return (1);
        i++;
    }
    return (0);
}

int is_duplicate(t_stack_node *a, int nb)
{
    if (!a)
        return (0);
    while(a)
    {
        if (a->nbr = nb)
            return (1);
        a = a->next;
    }
    return (0);
}

void    free_stack(t_stack_node **list)
{
    t_stack_node    *temp;
    t_stack_node    *curr;

    if (!list)
        return ;
    curr = *list;
    while (curr)
    {
        temp = curr->next;
        curr->nbr = 0;
        free(curr);
        curr = temp;
    }
    *list = NULL;
}

void    free_on_errors(t_stack_node **a)
{
    free_stack(a);
    ft_printf("Error\n");
    exit(1);
}
