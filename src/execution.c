/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 18:25:39 by maceccar          #+#    #+#             */
/*   Updated: 2024/06/21 01:22:56 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_lowest_cost(t_stack *a, t_stack *b);
static void	play(int moves_a, int moves_b, t_stack *a, t_stack *b);
void		move(int movement, t_stack *stack);

// trova il node meno costoso da ordinare e lo ordina
void	play_next_best_move(t_stack *a, t_stack *b, t_stack *sa, t_stack *sb)
{
	t_stack_node	*node;
	int				lowcost;
	int				i;
	t_stack_node	*ca;
	t_stack_node	*cb;

	lowcost = get_lowest_cost(sa, sb);
	ca = sa->head;
	cb = sb->head;
	node = b->head;
	while (node)
	{
		i = ft_get_absolute(ca->value) + ft_get_absolute(cb->value);
		if (i == 0)
			return ((void)px(b, a));
		if (i == lowcost)
			return (play(ca->value, cb->value, a, b));
		node = node->next;
		ca = ca->next;
		cb = cb->next;
	}
}

void	move(int movement, t_stack *stack)
{
	if (!movement)
		return ;
	if (movement > 0)
	{
		while (movement--)
			rx(stack);
	}
	else
		while (movement++)
			rrx(stack);
}

static void	play(int moves_a, int moves_b, t_stack *a, t_stack *b)
{
	if (moves_a > 0 && moves_b > 0)
	{
		while (moves_a != 0 && moves_b != 0)
		{
			rr(a, b);
			moves_a--;
			moves_b--;
		}
	}
	else if (moves_a < 0 && moves_b < 0)
	{
		while (moves_a != 0 && moves_b != 0)
		{
			rrr(a, b);
			moves_a++;
			moves_b++;
		}
	}
	move(moves_a, a);
	move(moves_b, b);
	px(b, a);
}

static int	get_lowest_cost(t_stack *a, t_stack *b)
{
	int				i;
	int				lowest;
	t_stack_node	*ca;
	t_stack_node	*cb;

	ca = a->head;
	cb = b->head;
	lowest = ft_get_absolute(ca->value) + ft_get_absolute(cb->value);
	while (cb)
	{
		i = ft_get_absolute(ca->value) + ft_get_absolute(cb->value);
		ca = ca->next;
		cb = cb->next;
		if (i < lowest)
			lowest = i;
		if (lowest == 0)
			return (lowest);
	}
	return (lowest);
}
