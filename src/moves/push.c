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

#include "push_swap.h"

//If stack_1 == a => pb
//If stack_1 == b => pa
//1: From
//2: To
t_bool	px(t_stack *stack_1, t_stack *stack_2)
{
	if (ft_is_stack_empty(stack_1))
		return (false);
	stack_1 = ft_push(stack_2, ft_pop(stack_1));
	ft_printf("p%c\n", stack_2->name);
	return (true);
}
