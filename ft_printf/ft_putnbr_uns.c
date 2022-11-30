/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_uns.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habovyan <habovyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 18:57:27 by habovyan          #+#    #+#             */
/*   Updated: 2022/04/29 13:26:33 by habovyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_putnbr_uns(unsigned int n)
{
	unsigned int	count;
	unsigned int	nbr;

	nbr = n;
	count = 0;
	if (nbr < 0)
	{
		nbr = __INT_MAX__;
		count += ft_putnbr(nbr);
	}
	else if (nbr < 10)
	{
		count += ft_putchar(nbr + '0');
	}
	else
	{
		count += ft_putnbr(n / 10);
		count += ft_putchar((n % 10) + '0');
	}
	return (count);
}
