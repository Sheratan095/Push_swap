/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:41:41 by maceccar          #+#    #+#             */
/*   Updated: 2024/06/21 01:22:56 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Controlla se lo stack è già ordinato
// Se il primo è minore del secondo => rotate
// Altrimenti (il primo è maggiore del secondo)
//	 Se il primo è meggiore dell'ultimo => reverse rotate
// Se lo stack non è ordinato è rimasto solo da switchare i primi
void	ft_sort_three(t_stack *stack)
{
	t_stack_node	*tmp;

	if (ft_is_stack_ordered(stack))
		return ;
	tmp = stack->head;
	if (tmp->value < tmp->next->value)
		rrx(stack);
	else
	{
		if (tmp->value > tmp->next->next->value)
			rx(stack);
	}
	if (ft_is_stack_ordered(stack))
		return ;
	sx(stack);
}

// a è lo stack da cui prendere i nodi (from)
// b è lo stack dove vanno messi i nodi (to)
// PERCHÈ QUESTA FUNZIONE VIENE USATA SIA LA PRIMA VOLTA PER PORTARE GLI
// ELEMENTI DA a A b LA PRIMA VOLTA CHE PER RIPORTARCELI ALLA FINE
// Sposta tutti gli elementi dal primo al secondo nel modo più efficente
// Ottiene i costi di ogni nodo in entrambi gli stack
// Esegue la mossa (serie di operazioni) migliore basandosi sui costi raccolti
// Libera gli stack contenenti i costi
void	sort(t_stack *from, t_stack *to)
{
	t_stack			*cost_a;
	t_stack			*cost_b;
	t_stack_node	*node;

	cost_a = NULL;
	cost_b = NULL;
	cost_a = ft_initialize_stack(cost_a);
	cost_b = ft_initialize_stack(cost_b);
	node = to->head;
	while (node != NULL)
	{
		ft_push_tail(cost_a, get_selection_cost(from, node));
		ft_push_tail(cost_b, get_insertion_cost(to, node->value));
		node = node->next;
	}
	execute_best_move(from, to, cost_a, cost_b);
	ft_free_stack(cost_a);
	ft_free_stack(cost_b);
}
