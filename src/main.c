/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:43:46 by maceccar          #+#    #+#             */
/*   Updated: 2024/06/10 17:37:18 by marvin           ###   ########.fr       */
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

	ft_display_stack(stack);

	sa(stack);

	ft_printf("\n");
	ft_display_stack(stack);

	ft_free_stack(stack);
}
