/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:40:41 by maceccar          #+#    #+#             */
/*   Updated: 2024/06/21 01:22:56 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_stack *a, t_stack *b)
{
	ft_printf("rr\n");
	reverse_rotation(a);
	reverse_rotation(b);
}

void	rrr(t_stack *a, t_stack *b)
{
	ft_printf("rrr\n");
	rotation(a);
	rotation(b);
}

void	rx(t_stack *stack)
{
	ft_printf("r%c\n", stack->name);
	reverse_rotation(stack);
}
