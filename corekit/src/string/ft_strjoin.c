/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:40:17 by maceccar          #+#    #+#             */
/*   Updated: 2024/06/26 13:41:11 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	res_len;
	char	*res;

	res_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	res = ft_calloc(res_len, sizeof(char));
	if (!res)
		return (NULL);
	ft_strlcat(res, s1, res_len);
	ft_strlcat(res, s2, res_len);
	return (res);
}
