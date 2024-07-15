/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odib <odib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:37:51 by odib              #+#    #+#             */
/*   Updated: 2024/07/13 17:17:00 by odib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void print_stack(t_stack_node *top) {
    t_stack_node *current = top;
    while (current != NULL) {
        printf("%d ", current->nbr);
        current = current->next;
    }
    printf("\n");
}

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			**variables;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (EXIT_FAILURE);
	else if(ac == 2)
		av = ft_split(av[1],' ');
	else if (ac == 2)
		variables = ft_split(av[1], ' ');
	else
		variables = (av + 1);
	//printf("%s", av[1]);
	init_stack_a(&a, variables);
	if (!is_sorted(a))
	{
		if (list_length(a) == 2)
			sa(&a, true);
		else if (list_length(a) == 3)
			trio_sort(&a);
		else
			sort(&a, &b);
	}
	//print_stack(a);
	free_stack(&a);
	return (0);
}
