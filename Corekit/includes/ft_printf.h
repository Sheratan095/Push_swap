/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:40:17 by maceccar          #+#    #+#             */
/*   Updated: 2024/06/10 18:41:21 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "corekit.h"

int		ft_putptr(unsigned long lnb, char *base);

int		ft_is_in(char c, const char *ptr);

int		ft_putchar(char c);

int		ft_putstr(const char *str);

int		ft_putnbr(long int nb);

int		ft_printf(const char	*format, ...);

int		ft_putbase(unsigned int nb, char *base);

int		ft_unsignedputnbr(int n);

#endif
