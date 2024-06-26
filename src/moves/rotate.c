/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:30:32 by maceccar          #+#    #+#             */
/*   Updated: 2024/06/21 01:22:56 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "moves.h"

t_bool	ops_rotate(t_stack *stack);

t_bool	rx(t_stack *stack)
{
	t_bool	result;

	result = ops_rotate(stack);
	if (result)
		ft_printf("r%c\n", stack->name);
	return (result);
}
t_bool	rr(t_stack *a, t_stack *b)
{
	t_bool	result;

	result = ops_rotate(a) && ops_rotate(b);
	if (result)
		ft_printf("rr\n");
	return (result);
}

t_bool	ops_rotate(t_stack *stack)
{
	int	tmp_tail;

	if (stack == NULL || stack->length < 2)
		return (false);
	tmp_tail = ft_pop(stack);
	ft_push_tail(stack, tmp_tail);
	return (true);
}
