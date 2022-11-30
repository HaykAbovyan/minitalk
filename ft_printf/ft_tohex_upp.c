/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tohex_upp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habovyan <habovyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 18:14:42 by habovyan          #+#    #+#             */
/*   Updated: 2022/04/28 17:23:33 by habovyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_tohex_upp(unsigned int n, char *alpha)
{
	unsigned int	count;
	unsigned int	nbr;

	nbr = n;
	count = 0;
	if (nbr < 16)
		count += ft_putchar(alpha[nbr]);
	else
	{
		count += ft_tohex_upp(nbr / 16, "0123456789ABCDEF");
		count += ft_tohex_upp(nbr % 16, "0123456789ABCDEF");
	}
	return (count);
}
