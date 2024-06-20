/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:30:32 by maceccar          #+#    #+#             */
/*   Updated: 2024/06/10 19:14:30 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "moves.h"

t_bool	ops_reverse_rotate(t_stack *stack);

t_bool	rra(t_stack *a)
{
	return (ops_reverse_rotate(a));
}

t_bool	rrb(t_stack *b)
{
	return (ops_reverse_rotate(b));
}

t_bool	rrr(t_stack *a, t_stack *b)
{
	return (ops_reverse_rotate(a) && ops_reverse_rotate(b));
}

t_bool	ops_reverse_rotate(t_stack *stack)
{
	int	tmp_head;

	if (stack == NULL || stack->length < 2)
		return (false);
	tmp_head = ft_pop(stack);
	ft_push_tail(stack, tmp_head);
	return (true);
}
