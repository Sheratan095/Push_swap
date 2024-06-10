/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Moves.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:23:50 by maceccar          #+#    #+#             */
/*   Updated: 2024/06/10 18:44:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVES_H
# define MOVES_H

# include "push_swap.h"
# include "corekit.h"

//--------------------------SWITCH--------------------------

/**
	@brief Switch 1° and 2° element in the stack a
	@param t_stack pointer to stack a
	@return Boolean that determines if the operation went well
*/
t_bool	sa(t_stack *a);

/**
	@brief Switch 1° and 2° element in the stack b
	@param t_stack pointer to stack b
	@return Boolean that determines if the operation went well
*/
t_bool	sb(t_stack *b);

/**
	@brief Switch 1° and 2° element in both stacks
	@param t_stack pointer to stack b
	@param t_stack pointer to stack b
	@return Boolean that determines if the operation went well
*/
t_bool	ss(t_stack *a, t_stack *b);





//--------------------------ROTATE--------------------------

/**
	@brief Move last element of stack a in 1° position
	@param t_stack pointer to stack a
	@return Boolean that determines if the operation went well
*/
t_bool	ra(t_stack *a);

/**
	@brief Move last element of stack b in 1° position
	@param t_stack pointer to stack b
	@return Boolean that determines if the operation went well
*/
t_bool	rb(t_stack *b);

/**
	@brief Move last element of both stacks in 1° position
	@param t_stack pointer to stack a
	@param t_stack pointer to stack b
	@return Boolean that determines if the operation went well
*/
t_bool	rr(t_stack *a, t_stack *b);

#endif
