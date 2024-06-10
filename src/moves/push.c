/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 19:03:24 by maceccar          #+#    #+#             */
/*   Updated: 2024/06/10 19:08:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "moves.h"

t_bool	pa(t_stack *a, t_stack *b)
{
	int	tmp_b_head;
	
	if (b->length <= 0)
		return (false);
	tmp_b_head = ft_pop(b);
	ft_push(a, tmp_b_head);
	return (true);
}

t_bool	pb(t_stack *a, t_stack *b)
{
	int	tmp_a_head;
	
	if (a->length <= 0)
		return (false);
	tmp_a_head = ft_pop(a);
	ft_push(b, tmp_a_head);
	return (true);
}