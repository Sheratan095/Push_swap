/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:40:17 by maceccar          #+#    #+#             */
/*   Updated: 2024/06/10 18:41:21 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	const unsigned char	*char_dest;
	const unsigned char	*char_src;
	size_t				i;

	i = 0;
	char_dest = str1;
	char_src = str2;
	while (i < n)
	{
		if ((char_dest[i] - char_src[i]) != 0)
			return (char_dest[i] - char_src[i]);
		i++;
	}
	return (0);
}
