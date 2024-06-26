/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:41:00 by maceccar          #+#    #+#             */
/*   Updated: 2024/06/21 01:03:56 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	start_sorting(t_stack *a, t_stack *b);

// Controlla il numero degli argomenti, se è 0 restituisce il terminale
// Carica lo stack dai parametri e di conseguenza ne veririfica la validità
//	(lo stack_a viene inizializzato dentro load_stack())
// Inizializzazione dello stack_b e assegna i nomi (servono solo per il print)
// Se lo stack non è ordinato
//	Ordinalo
// Alla fine libera tutto
int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	a = load_stack(argc, argv, a);
	a->name = 'a';
	b = ft_initialize_stack(b);
	b->name = 'b';
	if (!ft_is_stack_ordered(a))
		start_sorting(a, b);
	ft_free_stack(a);
	ft_free_stack(b);
}

// Se ci sono due numeri e il primo è maggiore del secondo => switch
// Se ce ne sono 3 => sort_three
// Altrimenti
//	Metti il primo elemento di b in a
//	Finchè lo stack a non contiene 3 elementi ordinati
//	 sort(a, b)
//	Ordina i 3 elementi nello stack a
//	Finchè lo stack b non è vuoto
//	 sort(a, b)
//	Muove in posizione il più piccolo elemento di a 
static void	start_sorting(t_stack *a, t_stack *b)
{
	if (a->length == 2 && a->head->value > a->head->next->value)
		sx(a);
	if (a->length == 3)
		ft_sort_three(a);
	else
	{
		px(a, b);
		while (a->length > 3)
			sort(b, a);
		ft_sort_three(a);
		while (b->length != 0)
			sort(a, b);
		move(get_insertion_cost(a, ft_get_min_value(a)), a);
	}
}
