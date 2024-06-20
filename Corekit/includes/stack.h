/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:40:17 by maceccar          #+#    #+#             */
/*   Updated: 2024/06/21 00:07:31 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "corekit.h"

/**
	Struct used for the dubly linked list of int

	Circular dependency: con't use t_stack because it isn't still defined
			This will result in a compilation error because the compiler
			doesn't know what t_stack is at that point.
*/

typedef struct s_stack_node
{
	int					value;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

//TO DO levare name?
typedef struct s_stack
{
	char				name;
	int					length;
	struct s_stack_node	*head;
	struct s_stack_node	*tail;
}	t_stack;

/**
	@brief Allocate the stack and set to NULL head and tail
	@param stack pointer to stack that will be allocated
	@return Pointer to allocated stack
*/
t_stack			*ft_initialize_stack(t_stack *stack);

/**
	@brief Create a new node of the stack
	@param new_value value to assign to the new node
	@return Pointer to created node
*/
t_stack_node	*ft_create_node(int value);

/**
	@brief Check if stack is empty or null
	@param stack pointer to stack
	@return Boolean
*/
enum e_bool		ft_is_stack_empty(t_stack *stack);

/**
	@brief Create new node and add it to the stack
	@param stack pointer to stack
	@param new_value value to assign to the new node
	@return Pointer to stack
*/
t_stack			*ft_push(t_stack *stack, int new_value);

/**
	@brief Remove top element of the stack
	@param stack pointer to stack
	@return Value of popped node
*/
int				ft_pop(t_stack *stack);

/**
	@brief Remove last element of the stack
	@param stack pointer to stack
	@return Value of popped node
*/
int				ft_pop_tail(t_stack *stack);

/**
	@brief Print in the termial the stack, starting from top
	@param stack pointer to stack
*/
void			ft_display_stack(t_stack *stack);

/**
	@brief Free the stack
	@param stack pointer to stack
*/
void			ft_free_stack(t_stack *stack);

/**
	@brief Checks if value exists inside of stack
	@param stack pointer to stack
	@param value value to search
	@return the node found or NULL
*/
t_stack_node	*ft_stack_contains(t_stack *stack, int value);

/**
	@brief Search duplicate node of equal value after node pointer
	@param stack pointer to stack
	@return true if duplicate is found
*/
enum e_bool		ft_search_duplicate(t_stack *stack);

/**
	@brief Add new node to the bottom of the stack
	@param stack pointer to stack
	@param new_value value to assign to the new node
	@return Pointer to stack
*/
t_stack			*ft_push_tail(t_stack *stack, int new_value);

/**
	@brief Get index of the node in the stack
	@param stack pointer to stack
	@param node pointer to node
	@return Position of the node or -1 if there isn't or if stack or node are null
*/
int				ft_get_position_in_stack(t_stack *stack, t_stack_node *node);

#endif
