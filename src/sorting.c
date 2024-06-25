/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:41:41 by maceccar          #+#    #+#             */
/*   Updated: 2024/06/21 01:22:56 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_stack *stack)
{
	t_stack_node	*n;

	if (ft_is_stack_ordered(stack))
		return ;
	n = stack->head;
	if (n->value < n->next->value)
	{
		rrx(stack);
		if (ft_is_stack_ordered(stack))
			return ;
	}
	if (n->value > n->next->value)
	{
		if (n->value > n->next->next->value)
			rx(stack);
		if (ft_is_stack_ordered(stack))
			return ;
	}
	sx(stack);
}

// a is "from", b is "to"
void	sort(t_stack *from, t_stack *to)
{
	t_stack			*cost_a;
	t_stack			*cost_b;
	t_stack_node	*node;

	cost_a = NULL;
	cost_b = NULL;
	cost_a = ft_initialize_stack(cost_a);
	cost_b = ft_initialize_stack(cost_b);
	node = to->head;
	while (node != NULL)
	{
		ft_push_tail(cost_a, get_selection_cost(from, node));
		ft_push_tail(cost_b, get_insertion_cost(to, node->value));
		node = node->next;
	}
	play_next_best_move(from, to, cost_a, cost_b);
	ft_free_stack(cost_a);
	ft_free_stack(cost_b);
}
