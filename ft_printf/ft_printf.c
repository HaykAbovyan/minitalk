/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habovyan <habovyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 19:24:27 by habovyan          #+#    #+#             */
/*   Updated: 2022/05/02 16:55:45 by habovyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_checking(const char *str, int i, va_list args)
{
	int	count;

	count = 0;
	if (str[i] == 's')
		count += ft_putstr(va_arg(args, char *));
	if (str[i] == 'c')
		count += ft_putchar(va_arg(args, int));
	if (str[i] == 'd' || str[i] == 'i')
		count += ft_putnbr(va_arg(args, int));
	if (str[i] == 'x')
		count += ft_tohex(va_arg(args, unsigned int), "0123456789abcdef");
	if (str[i] == 'X')
		count += ft_tohex_upp(va_arg(args, unsigned int), "0123456789ABCDEF");
	if (str[i] == '%')
		count += ft_putchar('%');
	if (str[i] == 'u')
		count += ft_putnbr_uns(va_arg(args, unsigned int));
	if (str[i] == 'p')
		count += ft_printptr(va_arg(args, unsigned long long),
				"0123456789abcdef");
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		str_size;
	int		i;
	int		count;

	count = 0;
	str_size = ft_strlen(str);
	i = 0;
	va_start(args, str);
	while (i < str_size)
	{
		if (str[i] == '%')
		{
			count += ft_checking(str, (i + 1), args);
			i += 2;
		}
		else
		{
			count += ft_putchar(str[i]);
			i++;
		}
	}
	va_end(args);
	return (count);
}
