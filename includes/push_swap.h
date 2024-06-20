/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:19:56 by maceccar          #+#    #+#             */
/*   Updated: 2024/06/20 19:42:05 by maceccar         ###   ########.fr       */
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

void	print_stacks(t_stack *main, t_stack *temp);

void	push_to(t_stack *stack_1, t_stack *stack_2);

int		min_value(t_stack *stack);

void	reverse_rotation(t_stack *a);

void	rotation(t_stack *a);

t_bool	is_stack_ordered(t_stack *stack);

int		get_selection_cost(t_stack *a, t_stack_node *node);

void	display_stacks(t_stack *a, t_stack *b);

void	reverse_rotation(t_stack *a);

void	rotation(t_stack *a);

int		get_insertion_cost(t_stack *b, int value);

int		min_value(t_stack *stack);

void	rrr(t_stack *a, t_stack *b);

void	rr(t_stack *a, t_stack *b);

void	rrx(t_stack *a);

void	rx(t_stack *a);

void	sx(t_stack *a);

void	px(t_stack *a, t_stack *b);

void	sort(t_stack *from, t_stack *to);

int		max_value(t_stack *stack);

void	move(int movement, t_stack *stack);

int		get_position(t_stack *stack, t_stack_node *node);

void	play_next_best_move(t_stack *a, t_stack *b, t_stack *sa, t_stack *sb);

#endif
