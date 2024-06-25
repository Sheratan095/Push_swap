/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:41:00 by maceccar          #+#    #+#             */
/*   Updated: 2024/06/21 01:03:56 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_them_all(t_stack *a, t_stack *b);

//Check number of arguments:
// If no parameters are specified, the program must not display anything
//	and give the prompt back
int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	a = load_stack(argc, argv, a);
	a->name = 'a';
	b = ft_initialize_stack(b);
	b->name = 'b';
	if (ft_is_stack_ordered(a))
		return (ft_free_stack(a), ft_free_stack(b), 0);
	sort_them_all(a, b);
	return (ft_free_stack(a), ft_free_stack(b), 0);
}

//TO DO da spostare e cambiare nome possibilmente (start_sorting)
//Just for normi
static void	sort_them_all(t_stack *a, t_stack *b)
{
	if (a->length == 2 && a->head->value > a->head->next->value)
		sx(a);
	if (a->length == 3)
		ft_sort_three(a);
	else
	{
		px(a, b);
		while (a->length > 3 && !ft_is_stack_ordered(a))
			sort(b, a);
		ft_sort_three(a);
		while (b->length != 0)
			sort(a, b);
		move(get_insertion_cost(a, ft_get_min_value(a)), a);
	}
}

void	ft_sort_three(t_stack *stack)
{
	t_stack_node	*n;

	if (ft_is_stack_ordered(stack))
		return ;
	n = stack->head;
	if (n->value < n->next->value)
	{
		rx(stack);
		if (ft_is_stack_ordered(stack))
			return ;
	}
	if (n->value > n->next->value)
	{
		if (n->value > n->next->next->value)
			rrx(stack);
		if (ft_is_stack_ordered(stack))
			return ;
	}
	sx(stack);
}
