/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habovyan <habovyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 14:29:26 by habovyan          #+#    #+#             */
/*   Updated: 2022/04/29 14:30:10 by habovyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_ptr(uintptr_t num, char *alpha)
{
	unsigned int		count;
	unsigned long long	nbr;

	nbr = num;
	count = 0;
	if (nbr < 16)
	{
		ft_putchar(alpha[nbr]);
		count++;
	}
	else
	{
		count += ft_put_ptr(nbr / 16, "0123456789abcdef");
		count += ft_put_ptr(nbr % 16, "0123456789abcdef");
	}
	return (count);
}

int	ft_printptr(unsigned long long ptr, char *alpa)
{
	int	count;

	count = 0;
	count += write(1, "0x", 2);
	if (ptr < 16)
		count += ft_putchar(alpa[ptr]);
	else
	{
		count += ft_put_ptr(ptr / 16, "0123456789abcdef");
		count += ft_put_ptr(ptr % 16, "0123456789abcdef");
	}
	return (count);
}
