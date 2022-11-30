/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tohex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habovyan <habovyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 18:14:42 by habovyan          #+#    #+#             */
/*   Updated: 2022/04/28 17:23:26 by habovyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_tohex(unsigned int n, char *alpha)
{
	unsigned int	count;
	unsigned int	nbr;

	nbr = n;
	count = 0;
	if (nbr < 16)
	{
		ft_putchar(alpha[nbr]);
		count++;
	}
	else
	{
		count += ft_tohex(nbr / 16, "0123456789abcdef");
		count += ft_tohex(nbr % 16, "0123456789abcdef");
	}
	return (count);
}
