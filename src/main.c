/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:41:00 by maceccar          #+#    #+#             */
/*   Updated: 2024/06/21 01:30:52 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	initialize_stacks(t_stack *a, t_stack *b, int argc, char *argv[]);

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc == 1)
		return (ft_printf("Error\n"));
	initialize_stacks(a, b, argc, argv);
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
		move(get_insertion_cost(a, ft_get_min_value(a)), a);
	}
	return (ft_free_stack(a), ft_free_stack(b), 0);
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

//Just for norminette
static int	initialize_stacks(t_stack *a, t_stack *b, int argc, char *argv[])
{
	a = load_stack(argc, argv, a);
	a->name = 'a';
	b = ft_initialize_stack(b);
	b->name = 'b';
}
