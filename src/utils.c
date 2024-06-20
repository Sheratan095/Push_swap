/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:24:25 by maceccar          #+#    #+#             */
/*   Updated: 2024/06/21 01:04:17 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	smallest_bigger_than(t_stack *stack, int x)
{
	t_stack_node	*cursor;
	int				target;

	target = x;
	cursor = stack->head;
	while (cursor != NULL)
	{
		if (cursor->value < x && (x == target || cursor->value > target))
			target = cursor->value;
		cursor = cursor->next;
	}
	if (target == x)
		target = ft_get_max_value(stack);
	return (target);
}

int	greatest_smaller_than(t_stack *stack, int x)
{
	t_stack_node	*cursor;
	int				target;

	target = x;
	cursor = stack->head;
	while (cursor != NULL)
	{
		if (cursor->value > x && (x == target || cursor->value < target))
			target = cursor->value;
		cursor = cursor->next;
	}
	if (target == x)
		target = ft_get_min_value(stack);
	return (target);
}

//ottiene il costo di un nodo guardando la sua posizione
int	get_insertion_cost(t_stack *b, int value)
{
	int	cost;
	int	position;

	position = ft_get_position_in_stack(b, ft_stack_contains(b, value));
	if (position > b->length / 2)
		cost = -(b->length - position);
	else
		cost = position;
	return (cost);
}

//ottiene il target node in base all'ordine "a"->decrescente "b"->crescente
int	get_selection_cost(t_stack *a, t_stack_node *node)
{
	int	target;

	if (a->name == 'a')
		target = greatest_smaller_than(a, node->value);
	else if (a->name == 'b')
		target = smallest_bigger_than(a, node->value);
	return (get_insertion_cost(a, target));
}
