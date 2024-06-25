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

// void	px(t_stack *from, t_stack *to)
// {
// 	ft_printf("p%c\n", to->name);
// 	push_to(from, to);
// }

void	sx(t_stack *a)
{
	int	temp;

	ft_printf("s%c\n", a->name);
	if (ft_is_stack_empty(a) || a->length < 2)
		return ;
	temp = a->head->value;
	a->head->value = a->head->next->value;
	a->head->next->value = temp;
}

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
