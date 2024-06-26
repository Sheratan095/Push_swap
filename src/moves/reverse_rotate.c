/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:30:32 by maceccar          #+#    #+#             */
/*   Updated: 2024/06/21 01:22:56 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "moves.h"

static t_bool	ops_reverse_rotate(t_stack *stack);

t_bool	rrx(t_stack *stack)
{
	t_bool	result;

	result = ops_reverse_rotate(stack);
	if (result)
		ft_printf("rr%c\n", stack->name);
	return (result);
}

t_bool	rrr(t_stack *a, t_stack *b)
{
	t_bool	result;

	result = ops_reverse_rotate(a) && ops_reverse_rotate(b);
	if (result)
		ft_printf("rrr\n");
	return (result);
}

static t_bool	ops_reverse_rotate(t_stack *stack)
{
	int	tmp_head;

	if (stack == NULL || stack->length < 2)
		return (false);
	tmp_head = ft_pop_tail(stack);
	ft_push(stack, tmp_head);
	return (true);
}
