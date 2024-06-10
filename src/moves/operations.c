/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:53:06 by maceccar          #+#    #+#             */
/*   Updated: 2024/06/10 18:41:21 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corekit.h"


t_bool	ops_reverse_rotate(t_stack *stack)
{
	int	tmp_head;

	if (stack == NULL || stack->length < 2)
		return (false);
	tmp_head = ft_pop(stack);
	ft_push_tail(stack, tmp_head);
	return (true);
}
