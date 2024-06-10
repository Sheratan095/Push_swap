/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:43:46 by maceccar          #+#    #+#             */
/*   Updated: 2024/06/10 19:10:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main()
{
	t_stack *stack;

	stack = ft_initialize_stack(stack);
	stack = ft_push(stack, 4);
	stack = ft_push(stack, 3);
	stack = ft_push(stack, 2);
	stack = ft_push(stack, 1);
	
	t_stack *stack1;

	stack1 = ft_initialize_stack(stack1);
	stack1 = ft_push(stack1, 9);
	stack1 = ft_push(stack1, 8);
	stack1 = ft_push(stack1, 7);
	stack1 = ft_push(stack1, 6);
	
	ft_display_stack(stack);
	ft_printf("\n");
	ft_display_stack(stack1);
	ft_printf("\n");
	ft_printf("\n");
	

	ft_printf("|%i|\n\n", pb(stack, stack1));

	ft_display_stack(stack);
	ft_printf("\n");
	ft_display_stack(stack1);
	

	ft_free_stack(stack);
	ft_free_stack(stack1);
}
