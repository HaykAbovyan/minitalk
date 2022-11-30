/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habovyan <habovyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 18:57:27 by habovyan          #+#    #+#             */
/*   Updated: 2022/04/28 17:24:10 by habovyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long	ft_extra(unsigned int count)
{
	write(1, "-2147483648", 11);
	count = 11;
	return (count);
}		

int	ft_putnbr(int n)
{
	long	nbr;
	int		count;

	nbr = n;
	count = 0;
	if (nbr == -2147483648)
		count += ft_extra(count);
	else
	{
		if (nbr < 0)
		{
			nbr = -nbr;
			count += ft_putchar('-');
		}
		if (nbr >= 10)
		{
			count += ft_putnbr(nbr / 10);
			count += ft_putchar((nbr % 10) + '0');
		}
		else
			count += ft_putchar(nbr + '0');
	}
	return (count);
}
