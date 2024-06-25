/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:19:56 by maceccar          #+#    #+#             */
/*   Updated: 2024/06/21 01:22:56 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "corekit.h"

t_stack	*load_stack(int argc, char **argv, t_stack *stack);

void	ft_sort_three(t_stack *stack);

void	push_to(t_stack *stack_1, t_stack *stack_2);

void	reverse_rotation(t_stack *a);

void	rotation(t_stack *a);

int		get_selection_cost(t_stack *a, t_stack_node *node);

void	reverse_rotation(t_stack *a);

void	rotation(t_stack *a);

int		get_insertion_cost(t_stack *b, int value);

void	rrr(t_stack *a, t_stack *b);

void	rr(t_stack *a, t_stack *b);

void	rrx(t_stack *a);

void	rx(t_stack *a);

void	sx(t_stack *a);

void	px(t_stack *a, t_stack *b);

void	sort(t_stack *from, t_stack *to);

void	move(int movement, t_stack *stack);

void	play_next_best_move(t_stack *a, t_stack *b, t_stack *sa, t_stack *sb);

#endif
