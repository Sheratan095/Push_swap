/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:23:50 by maceccar          #+#    #+#             */
/*   Updated: 2024/06/21 01:22:56 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVES_H
# define MOVES_H

# include "push_swap.h"
# include "corekit.h"

//-----------------------------------SWITCH-----------------------------------

/**
	@brief Switch 1° and 2° element in the stack a
	@param t_stack pointer to stack a
	@return Boolean that determines if the operation went well
*/
// t_bool	sa(t_stack *a);

/**
	@brief Switch 1° and 2° element in the stack b
	@param t_stack pointer to stack b
	@return Boolean that determines if the operation went well
*/
// t_bool	sb(t_stack *b);

/**
	@brief Switch 1° and 2° element in both stacks
	@param t_stack pointer to stack b
	@param t_stack pointer to stack b
	@return Boolean that determines if the operation went well
*/
// t_bool	ss(t_stack *a, t_stack *b);

//-----------------------------------ROTATE-----------------------------------

/**
	@brief Move last element of stack a in 1° position
	@param t_stack pointer to stack a
	@return Boolean that determines if the operation went well
*/
// t_bool	ra(t_stack *a);

/**
	@brief Move last element of stack b in 1° position
	@param t_stack pointer to stack b
	@return Boolean that determines if the operation went well
*/
// t_bool	rb(t_stack *b);

/**
	@brief Move last element of both stacks in 1° position
	@param t_stack pointer to stack a
	@param t_stack pointer to stack b
	@return Boolean that determines if the operation went well
*/
// t_bool	rr(t_stack *a, t_stack *b);

//-------------------------------REVERSE ROTATE-------------------------------

/**
	@brief Move 1° element of stack a in the last position
	@param t_stack pointer to stack a
	@return Boolean that determines if the operation went well
*/
// t_bool	rra(t_stack *a);

/**
	@brief Move 1° element of stack b in the last position
	@param t_stack pointer to stack b
	@return Boolean that determines if the operation went well
*/
// t_bool	rrb(t_stack *b);

/**
	@brief Move 1° element of both stacks in the last position
	@param t_stack pointer to stack a
	@param t_stack pointer to stack b
	@return Boolean that determines if the operation went well
*/
// t_bool	rrr(t_stack *a, t_stack *b);

//------------------------------------PUSH------------------------------------

/**
	@brief Move 1° element of stack_2 to stack_1
	@param t_stack pointer to stack 1 (to)
	@param t_stack pointer to stack 2 (from)
	@return Boolean that determines if the operation went well
*/
t_bool	px(t_stack *stack_1, t_stack *stack_2);

#endif
