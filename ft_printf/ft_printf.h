/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habovyan <habovyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:56:07 by habovyan          #+#    #+#             */
/*   Updated: 2022/10/09 17:28:32 by habovyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>
# include <stddef.h>

unsigned int				ft_putnbr_uns(unsigned int n);
unsigned int				ft_tohex(unsigned int n, char *alpha);
unsigned int				ft_tohex_upp(unsigned int n, char *alpha);
int							ft_printptr(unsigned long long ptr, char *alpa);
int							ft_printf(const char *str, ...);
int							ft_putchar(int c);
int							ft_putstr(char *s);
int							ft_putnbr(int n);
size_t						ft_strlen(const char *c);
#endif
