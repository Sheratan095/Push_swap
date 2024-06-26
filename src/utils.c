/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:24:25 by maceccar          #+#    #+#             */
/*   Updated: 2024/06/21 01:22:56 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	smallest_bigger_than(t_stack *stack, int x);
static int	greatest_smaller_than(t_stack *stack, int x);

//ottiene il costo di un nodo guardando la sua posizione
int	get_insertion_cost(t_stack *b, int value)
{
	int	cost;
	int	position;

	position = ft_get_position_in_stack(b, ft_stack_contains(b, value));
	if ((size_t)position > b->length / 2)
		cost = -(b->length - position);
	else
		cost = position;
	return (cost);
}

//ottiene il target node in base all'ordine "a"->decrescente "b"->crescente
int	get_selection_cost(t_stack *a, t_stack_node *node)
{
	int	target;

	if (a->name == 'a')
		target = greatest_smaller_than(a, node->value);
	else if (a->name == 'b')
		target = smallest_bigger_than(a, node->value);
	return (get_insertion_cost(a, target));
}

// Trova il più grande numero nello stack minore di x
// Scorre tutto lo stack attraverso il cursor (tmp)
// 	Se il valore in questione è minore di x e
//		o x = result : nessun altro numero è stato ancora trovato
//		oppure il valore > result : è stato trovato un nuovo numero maggiore
// 	  => il risultato diventa quel numero
// 	Il cursore va avanti
// Se result == x vuol dire che non è stato trovato nessun valore minore di x
//	il risultato sarà il valore massimo nello stack
static int	smallest_bigger_than(t_stack *stack, int x)
{
	t_stack_node	*cursor;
	int				result;

	result = x;
	cursor = stack->head;
	while (cursor != NULL)
	{
		if (cursor->value < x && (x == result || cursor->value > result))
			result = cursor->value;
		cursor = cursor->next;
	}
	if (result == x)
		result = ft_get_max_value(stack);
	return (result);
}

// Trova il più piccolo numero nello stack maggiore di x
// Scorre tutto lo stack attraverso il cursor (tmp)
// 	Se il valore in questione è maggiore di x e
//		o x = result : nessun altro numero è stato ancora trovato
//		oppure il valore < result : è stato trovato un nuovo numero minore
// 	  => il risultato diventa quel numero
// 	Il cursore va avanti
// Se result == x vuol dire che non è stato trovato nessun valore minore di x
//	il risultato sarà il valore minimo nello stack
static int	greatest_smaller_than(t_stack *stack, int x)
{
	t_stack_node	*cursor;
	int				result;

	result = x;
	cursor = stack->head;
	while (cursor != NULL)
	{
		if (cursor->value > x && (x == result || cursor->value < result))
			result = cursor->value;
		cursor = cursor->next;
	}
	if (result == x)
		result = ft_get_min_value(stack);
	return (result);
}
