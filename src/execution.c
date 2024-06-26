/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 18:25:39 by maceccar          #+#    #+#             */
/*   Updated: 2024/06/21 01:22:56 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_lowest_cost(t_stack *costs_a, t_stack *costs_b);
static void	play(int moves_a, int moves_b, t_stack *a, t_stack *b);
void		move(int movement, t_stack *stack);

// trova il node meno costoso da portare in posizione ed esegue la mossa
// a è lo stack da cui prendere i nodi
// b è lo stack dove vanno messi i nodi
// PERCHÈ QUESTA FUNZIONE VIENE USATA SIA LA PRIMA VOLTA PER PORTARE GLI
// ELEMENTI DA a A b LA PRIMA VOLTA CHE PER RIPORTARCELI ALLA FINE
// sa contiente i costi di ogni elemento di a
// sb contiente i costi di ogni elemento di b
// ca e cb sono usati come variabili temporanee
// Scorre tutto lo stack b (di arrivo)
//	fa la somma del costo dei nodi degli stack
//	se la somma == 0 => il valore è in cima allo stack
//	 => push
//	se la somma == minor costo trovato precentemente
//	 => inizia ad eseguire le mosse
void	play_next_best_move(t_stack *a, t_stack *b, t_stack *sa, t_stack *sb)
{
	t_stack_node	*node;
	int				lowest_cost;
	int				i;
	t_stack_node	*ca;
	t_stack_node	*cb;

	lowest_cost = get_lowest_cost(sa, sb);
	ca = sa->head;
	cb = sb->head;
	node = b->head;
	while (node)
	{
		i = ft_get_absolute(ca->value) + ft_get_absolute(cb->value);
		if (i == 0)
			return ((void)px(b, a));
		if (i == lowest_cost)
			return (play(ca->value, cb->value, a, b));
		node = node->next;
		ca = ca->next;
		cb = cb->next;
	}
}

// movement: numero di rotazioni da effettuare
// se movement > 0
//	=> effettua reverse rotate finchè movement è 0
// se movement < 0
//	> effettua rotate finchè movement è 0
void	move(int movement, t_stack *stack)
{
	if (!movement)
		return ;
	if (movement > 0)
	{
		while (movement--)
			rx(stack);
	}
	else
	{
		while (movement++)
			rrx(stack);
	}
}

// a è lo stack da cui prendere i nodi
// b è lo stack dove vanno messi i nodi
// moves_a costo per il nodo nello stack_a (usato come count)
// moves_b costo per il nodo nello stack_b (usato come count)
// Se entrambi i costi sono positivi
//	reverse rotate simultaneo (rrr) finchè non si sono esaurite le mosse
// Se entrambi i costi sono negativi
//	rotate simultaneo (rr) finchè non si sono esaurite le mosse
// Esegue eventuali mosse rimanenti per ogni stack singolarmente
static void	play(int moves_a, int moves_b, t_stack *a, t_stack *b)
{
	if (moves_a > 0 && moves_b > 0)
	{
		while (moves_a != 0 && moves_b != 0)
		{
			rr(a, b);
			moves_a--;
			moves_b--;
		}
	}
	else
	{
		while (moves_a != 0 && moves_b != 0)
		{
			rrr(a, b);
			moves_a++;
			moves_b++;
		}
	}
	move(moves_a, a);
	move(moves_b, b);
}

// Trova la coppia di nodi nei due stack che hanno
//	il minor costo per essere eseguite
// costs_a è lo stack dei costi da cui vanno levati i nodi
// costs_b è lo stack dei costi dove vanno inseriti i nodi di a
// Scorre tutto lo stack dei costi di b
//  ottiene la somma dei costi dei nodi nelle posizione corrispondente
//  Se è minor del minor costo finora trovato
//	 => il risultato (minor costo) diventerò il valore appena calcolato
//	Se il valore == 0
//	 => ritorna perché non è possibile trovare un costo minore di esso
static int	get_lowest_cost(t_stack *costs_a, t_stack *costs_b)
{
	int				temp_sum;
	int				lowest;
	t_stack_node	*cost_a;
	t_stack_node	*cost_b;

	cost_a = costs_a->head;
	cost_b = costs_b->head;
	lowest = ft_get_absolute(cost_a->value) + ft_get_absolute(cost_b->value);
	while (cost_b)
	{
		temp_sum = ft_get_absolute(cost_a->value) + ft_get_absolute(cost_b->value);
		cost_a = cost_a->next;
		cost_b = cost_b->next;
		if (temp_sum < lowest)
			lowest = temp_sum;
		if (lowest == 0)
			return (lowest);
	}
	return (lowest);
}
