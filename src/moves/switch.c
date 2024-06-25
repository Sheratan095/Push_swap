/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:11:58 by maceccar          #+#    #+#             */
/*   Updated: 2024/06/21 01:22:56 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "moves.h"

static t_bool	ops_switch(t_stack *stack);

t_bool	sx(t_stack *stack)
{	
	t_bool	result;

	result = ops_switch(stack);
	if (result)
		ft_printf("s%c\n", stack->name);
	return (result);
}

t_bool	ss(t_stack *a, t_stack *b)
{
	t_bool	result;

	result = ops_switch(a) && ops_switch(b);
	if (result)
		ft_printf("ss%c\n");
	return (result);
}

static t_bool	ops_switch(t_stack *stack)
{
	int	tmp_first;
	int	tmp_second;

	if (stack == NULL || stack->length < 2)
		return (false);
	tmp_first = ft_pop(stack);
	tmp_second = ft_pop(stack);
	ft_push(stack, tmp_first);
	ft_push(stack, tmp_second);
	return (true);
}
