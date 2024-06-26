/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_position_in_stack.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 00:09:51 by maceccar          #+#    #+#             */
/*   Updated: 2024/06/26 13:41:11 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	ft_get_position_in_stack(t_stack *stack, t_stack_node *node)
{
	int				index;
	t_stack_node	*tmp;

	index = 0;
	if (!stack || !node)
		return (-1);
	tmp = stack->head;
	while (tmp != NULL)
	{
		if (node == tmp)
			return (index);
		index++;
		tmp = tmp->next;
	}
	return (-1);
}
