/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odib <odib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:06:54 by odib              #+#    #+#             */
/*   Updated: 2024/07/11 17:02:42 by odib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdbool.h>
# include <limits.h>
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

long			ft_atol(const char *s);

t_stack_node	*find_max(t_stack_node *list);
t_stack_node	*find_min(t_stack_node	*list);
t_stack_node	*find_last_node(t_stack_node *a);

void			free_stack(t_stack_node **list);
void			free_on_errors(t_stack_node **a);
void			append_node(t_stack_node **list, int value);
void			init_stack_a(t_stack_node **a, char **av);
void			rotate(t_stack_node **list);
void			ra(t_stack_node **a, bool print);
void			rb(t_stack_node **b, bool print);
void			rr(t_stack_node **a, t_stack_node **b, bool print);
void			swap(t_stack_node **list);
void			sa(t_stack_node **a, bool print);
void			sb(t_stack_node **b, bool print);
void			ss(t_stack_node **a, t_stack_node **b, bool print);

int				list_length(t_stack_node	*list);
int				is_error_impliment(char *str);
int				is_duplicate(t_stack_node *a, int nb);
int				is_sorted(t_stack_node	*list);
#endif