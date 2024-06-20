/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_stack_ordered.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 01:31:06 by maceccar          #+#    #+#             */
/*   Updated: 2024/06/21 01:31:06 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_bool	ft_is_stack_ordered(t_stack *stack)
{
	t_stack_node	*tmp;

	if (ft_is_stack_empty(stack))
		return (false);
	tmp = stack->head;
	while (tmp)
	{
		if (tmp->prev)
		{
			if (tmp->prev->value > tmp->value)
				return (false);
		}
		tmp = tmp->next;
	}
	return (true);
}
