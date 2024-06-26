/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:23:50 by maceccar          #+#    #+#             */
/*   Updated: 2024/06/26 13:59:50 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVES_H
# define MOVES_H

# include "push_swap.h"
# include "corekit.h"

//-----------------------------------SWITCH-----------------------------------

/**
	@brief Switch 1° and 2° element in the stack x
	@param t_stack pointer to stack x
	@return Boolean that determines if the operation went well
*/
t_bool	sx(t_stack *stack);

/**
	@brief Switch 1° and 2° element in both stacks
	@param t_stack pointer to stack b
	@param t_stack pointer to stack b
	@return Boolean that determines if the operation went well
*/
t_bool	ss(t_stack *a, t_stack *b);

//-----------------------------------ROTATE-----------------------------------

/**
	@brief Move first element of stack x in last position
	@param t_stack pointer to stack a
	@return Boolean that determines if the operation went well
*/
t_bool	rx(t_stack *stack);

/**
	@brief Move first element of both stacks in last position
	@param t_stack pointer to stack a
	@param t_stack pointer to stack b
	@return Boolean that determines if the operation went well
*/
t_bool	rr(t_stack *a, t_stack *b);

//-------------------------------REVERSE ROTATE-------------------------------

/**
	@brief Move last element of stack x in the first position
	@param t_stack pointer to stack a
	@return Boolean that determines if the operation went well
*/
t_bool	rrx(t_stack *a);

/**
	@brief Move last element of both stacks in the first position
	@param t_stack pointer to stack a
	@param t_stack pointer to stack b
	@return Boolean that determines if the operation went well
*/
t_bool	rrr(t_stack *a, t_stack *b);

//------------------------------------PUSH------------------------------------

/**
	@brief Move 1° element of stack_2 to stack_1
	@param t_stack pointer to stack 1 (to)
	@param t_stack pointer to stack 2 (from)
	@return Boolean that determines if the operation went well
*/
t_bool	px(t_stack *stack_1, t_stack *stack_2);

#endif
