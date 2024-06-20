/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:41:00 by maceccar          #+#    #+#             */
/*   Updated: 2024/06/20 19:42:05 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_value(t_stack *stack)
{
	int				min;
	t_stack_node	*node;

	node = stack->head;
	min = stack->head->value;
	while (node != NULL)
	{
		if (min > node->value)
			min = node->value;
		node = node->next;
	}
	return (min);
}

//gets the position, first value is 0
int	get_position(t_stack *stack, t_stack_node *node)
{
	int				i;
	t_stack_node	*cursor;

	i = 0;
	cursor = stack->head;
	while (i < stack->length)
	{
		if (node == cursor)
			return (i);
		i++;
		cursor = cursor->next;
	}
	return (0);
}

//Scorre tutto lo stack, se esiste qualocosa prima, se e minore e ordinato
t_bool	is_stack_ordered(t_stack *stack)
{
	t_stack_node	*temp_node;

	temp_node = stack->head;
	while (temp_node)
	{
		if (temp_node->prev)
		{
			if (temp_node->prev->value > temp_node->value)
				return (false);
		}
		temp_node = temp_node->next;
	}
	return (true);
}

void	ft_sort_three(t_stack *stack)
{
	t_stack_node	*n;

	if (is_stack_ordered(stack))
		return ;
	n = stack->head;
	if (n->value < n->next->value)
	{
		rrx(stack);
		if (is_stack_ordered(stack))
			return ;
	}
	if (n->value > n->next->value)
	{
		if (n->value > n->next->next->value)
			rx(stack);
		if (is_stack_ordered(stack))
			return ;
	}
	sx(stack);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = load_stack(argc, argv, a);
	a->name = 'a';
	b = ft_initialize_stack(b);
	b->name = 'b';
	if (is_stack_ordered(a))
		return (ft_free_stack(a), ft_free_stack(b), 0);
	if (a->length == 2 && a->head->value > a->head->next->value)
		sx(a);
	if (a->length == 3)
		ft_sort_three(a);
	else
	{
		px(a, b);
		while (a->length > 3 && !is_stack_ordered(a))
			sort(b, a);
		ft_sort_three(a);
		while (b->length != 0)
			sort(a, b);
		move(get_insertion_cost(a, min_value(a)), a);
	}
	return (ft_free_stack(a), ft_free_stack(b), 0);
}
