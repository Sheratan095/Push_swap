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

int	abs(int a)
{
	if (a < 0)
		a = -a;
	return (a);
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

//str => if stack_1 == a => pb else pa
void	push_to(t_stack *stack_1, t_stack *stack_2)
{
	if (ft_is_stack_empty(stack_1))
		return ;
	stack_1 = ft_push(stack_2, ft_pop(stack_1));
}

void	reverse_rotation(t_stack *a)
{
	if (ft_is_stack_empty(a) || a->length < 2)
		return ;
	a = ft_push_tail(a, ft_pop(a));
}

void	rotation(t_stack *a)
{
	if (ft_is_stack_empty(a) || a->length < 2)
		return ;
	a = ft_push(a, ft_pop_tail(a));
}
