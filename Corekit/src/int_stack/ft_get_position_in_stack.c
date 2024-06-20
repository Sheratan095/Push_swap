/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_position_in_stack.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 00:09:51 by maceccar          #+#    #+#             */
/*   Updated: 2024/06/21 00:17:47 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	ft_get_position_in_stack(t_stack *stack, t_stack_node *node)
{
	int				i;
	t_stack_node	*cursor;

	i = 0;
	if (!stack || !node)
		return (-1);
	cursor = stack->head;
	while (i < stack->length)
	{
		if (node == cursor)
			return (i);
		i++;
		cursor = cursor->next;
	}
	return (-1);
}
