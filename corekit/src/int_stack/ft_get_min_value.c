/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_min_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 00:26:00 by maceccar          #+#    #+#             */
/*   Updated: 2024/06/21 01:22:56 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	ft_get_min_value(t_stack *stack)
{
	int				min;
	t_stack_node	*tmp;

	if (ft_is_stack_empty(stack))
		return (0);
	tmp = stack->head;
	min = stack->head->value;
	while (tmp != NULL)
	{
		if (min > tmp->value)
			min = tmp->value;
		tmp = tmp->next;
	}
	return (min);
}
