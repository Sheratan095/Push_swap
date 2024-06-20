/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_duplicate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:40:17 by maceccar          #+#    #+#             */
/*   Updated: 2024/06/21 00:09:55 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_bool	ft_search_duplicate(t_stack *stack)
{
	t_stack_node	*tmp;

	if (ft_is_stack_empty(stack))
		return (false);
	tmp = stack->head;
	while (tmp)
	{
		if (ft_stack_contains(stack, tmp->value))
			return (true);
		tmp = tmp->next;
	}
	return (false);
}
