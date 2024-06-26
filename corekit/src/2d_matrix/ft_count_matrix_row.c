/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_matrix_row.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:40:17 by maceccar          #+#    #+#             */
/*   Updated: 2024/06/26 13:41:11 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corekit.h"

size_t	ft_count_matrix_row(const void **matrix)
{
	size_t	i;

	i = 0;
	while (matrix[i])
		i++;
	return (i);
}
