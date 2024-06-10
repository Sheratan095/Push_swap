/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:30:32 by maceccar          #+#    #+#             */
/*   Updated: 2024/06/10 18:46:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "moves.h"

t_bool	ops_rotate(t_stack *stack);

t_bool	ra(t_stack *a)
{
	return (ops_rotate(a));
}

t_bool	rb(t_stack *b)
{
	return (ops_rotate(b));
}

t_bool	rr(t_stack *a, t_stack *b)
{
	return (ops_rotate(a) && ops_rotate(b));
}


t_bool	ops_rotate(t_stack *stack)
{
	int	tmp_tail;

	if (stack == NULL || stack->length < 2)
		return (false);
	tmp_tail = ft_pop_tail(stack);
	ft_push(stack, tmp_tail);
	return (true);
}
