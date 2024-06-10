/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:53:06 by maceccar          #+#    #+#             */
/*   Updated: 2024/06/10 17:24:04 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corekit.h"

t_bool	ops_rotate(t_stack *stack)
{
	int	tmp_tail;

	if (stack == NULL || stack->length < 2)
		return (false);
	tmp_tail = ft_pop_tail(stack);
	ft_push(stack, tmp_tail);
	return (true);
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
