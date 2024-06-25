/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 19:03:24 by maceccar          #+#    #+#             */
/*   Updated: 2024/06/21 01:22:56 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "moves.h"

//If stack_1 == a => pb
//If stack_1 == b => pa
t_bool	px(t_stack *stack_1, t_stack *stack_2)
{
	int	tmp_b_head;

	if (ft_is_stack_empty(stack_2))
		return (false);
	tmp_b_head = ft_pop(stack_2);
	if (!ft_push(stack_1, tmp_b_head))
		return (false);
	ft_printf("p%c\n", stack_2->name);
	return (true);
}
