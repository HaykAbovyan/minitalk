/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habovyan <habovyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 16:26:40 by habovyan          #+#    #+#             */
/*   Updated: 2022/11/29 14:58:07 by habovyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bits(int pid, char c)
{
	int	i;

	i = 128;
	while (i)
	{
		if (c & i)
		{
			if (kill(pid, SIGUSR1) == -1)
				exit(EXIT_FAILURE);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(EXIT_FAILURE);
		}
		usleep(50);
		i >>= 1;
	}
}

void	send_mes(int pid, char *mes)
{
	int	i;

	i = 0;
	while (mes[i])
	{	
		send_bits(pid, mes[i]);
		i++;
	}
}

int	is_num(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

int	main(int ac, char **as)
{
	int		pid;
	char	*mes;

	if (ac == 3 && is_num(as[1]))
	{
		pid = ft_atoi(as[1]);
		mes = as[2];
		send_mes(pid, mes);
	}
	else
	{
		ft_printf("Syntax: <./client> <PID> <message>");
		return (0);
	}
}
