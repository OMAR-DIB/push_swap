/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odib <odib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:06:54 by odib              #+#    #+#             */
/*   Updated: 2024/07/09 17:16:36 by odib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

void    init_stack_a(t_stack_node **a, char **av);
t_stack_node    *find_last_node(t_stack_node *a);
static long	ft_atol(const char *s);
int is_error_impliment(char   *str);
int is_duplicate(t_stack_node *a, int nb);
void    free_stack(t_stack_node **list);
void    free_on_errors(t_stack_node **a);




#endif