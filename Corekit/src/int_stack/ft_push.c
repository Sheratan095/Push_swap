/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:40:17 by maceccar          #+#    #+#             */
/*   Updated: 2024/06/21 01:22:56 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

//Creazione di un nuovo nodo
//Memcheck
//Assegnazione valori di default
//Se lo stack non è vuoto
//	il nuovo nodo va linkato a quello precendente e viceversa
//Altrimenti
//	lo stack diventa il nuovo nodo
t_stack	*ft_push(t_stack *stack, int new_value)
{
	t_stack_node	*updated_head;

	if (!stack)
		return (NULL);
	updated_head = ft_create_node(new_value);
	if (ft_is_stack_empty(stack))
	{
		stack->head = updated_head;
		stack->tail = stack->head;
	}
	else
	{
		updated_head->next = stack->head;
		stack->head->prev = updated_head;
		stack->head = updated_head;
	}
	stack->length++;
	return (stack);
}
