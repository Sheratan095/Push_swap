/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_loading.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:01:55 by maceccar          #+#    #+#             */
/*   Updated: 2024/06/26 13:41:11 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool	double_check_number(int number, char *str_number);
static void		error(int argc, char **argv, t_stack *stack);
static char		**take_arguments(int argc, char **argv, int *i, t_stack *stack);

// tmp_number è long per eviatare soliti problemi con il minimo intero
// Ottieni la matrice contentente l'argomento
// Cicla la matrice e per ogni elemento (stringa numerica)
//		Verifica che la stringa contenga solo elementi numerici
//		Ottieni il numero (atoi)
//		Fai il doppio controllo sulla stringa iniziale
//		Verifica che non sia già contenuto nello stack
//		Pusha in coda (come nel checker)
// Se argc == 2 vuol dire che la matrice è stata allocata durante la lettura
// 	=> va liberata
t_stack	*load_stack(int argc, char **argv, t_stack *stack)
{
	int		i;
	char	**argv_splitted;
	long	tmp_number;

	stack = ft_initialize_stack(stack);
	argv_splitted = take_arguments(argc, argv, &i, stack);
	while (argv_splitted[i])
	{
		if (ft_is_string_numeric(argv_splitted[i]) == false)
			error(argc, argv_splitted, stack);
		tmp_number = ft_atoi(argv_splitted[i]);
		if (double_check_number(tmp_number, argv_splitted[i]) == false)
			error(argc, argv_splitted, stack);
		if (ft_stack_contains(stack, tmp_number))
			error(argc, argv_splitted, stack);
		ft_push_tail(stack, tmp_number);
		i++;
	}
	if (argc == 2)
		ft_free_matrix((void **)argv_splitted);
	return (stack);
}

// i è per far capire alla funzione principale da che indice partire
//	se il formato è ./push_swap 1 2 3 (argc > 1)
//		i = 1 perchè se fosse 0, matrice[0] sarebbe ./pus_swap
//		result sarà diretteamente argv, quindi non andrà deallocata
//	se il formato è ./push_swap "1 2 3" (argc = 2)
//		splitta argv[2]
//		controlla che ci sia almeno un'elemento
//	se argc == 1 => errore
static char	**take_arguments(int argc, char **argv, int *i, t_stack *stack)
{
	char	**result;

	if (argc == 1)
		error(argc, argv, NULL);
	if (argc == 2)
	{
		*i = 0;
		result = ft_split(argv[1], ' ');
		if (ft_count_matrix_row((const void **)result) == 0)
			error(argc, result, stack);
	}
	else
	{
		*i = 1;
		result = argv;
	}
	return (result);
}

// Check if ther's just '+' or '-' because ft_atol and ft_itoa
//		would convert it in 0 but we need an error
//If first is '+' or '-' and the sequent char isn't a digit

// Controlla che non la stringa non sia semplicemente "+" o "-"
//		se il primo carattere è "+" o "-" dopo ci deve essere qualcosa
//		fatto perché atoi(+/-) restituisce +/-0
// Controlla che il numero non sfori i limiti dell'int castandolo a long
//		e verificando che rientri nei limiti perché con l'atoi, i numeri
//		troppo grandi o troppo piccolo andrebbero in overload nell'int
//		restituendo un'intero
// Ritrasformata il numero in stringa e lo confronta con quella dell'input
// Libera la stringa allocata dentro 
static t_bool	double_check_number(int number, char *str_number)
{
	t_bool	result;
	char	*right_str_nmbr;

	if ((str_number[0] == '-' || str_number[0] == '+')
		&& !ft_isdigit(str_number[1]))
		return (false);
	if (ft_atol(str_number) < INT_MIN || ft_atol(str_number) > INT_MAX)
		return (false);
	result = false;
	right_str_nmbr = ft_itoa(number);
	if (ft_strncmp(right_str_nmbr, str_number, ft_strlen(right_str_nmbr)) == 0)
		result = true;
	else
		if (ft_atoi(str_number) == number)
			result = true;
	free(right_str_nmbr);
	return (result);
}

// Se argc == 2 vuol dire che il formato è ./push_swap "1 2 3"
//		=> la matrice è una matrice allocata => va deallocata
// Altrimenti la matrice sarebbe argv stessa, quindi non va deallocata
// Libera lo stack
// Stampa errore 
// Esci dal programma
static void	error(int argc, char **matrix, t_stack *stack)
{
	if (argc == 2)
		ft_free_matrix((void **)matrix);
	ft_free_stack(stack);
	ft_putstr_fd("Error\n", STDERR_FILENO);
	exit(0);
}
