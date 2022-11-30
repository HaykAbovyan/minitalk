/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habovyan <habovyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 16:34:40 by habovyan          #+#    #+#             */
/*   Updated: 2022/10/09 18:03:03 by habovyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int sig, siginfo_t *info, void *context)
{
	static int		i;
	static char		byte;

	(void) context;
	(void) info;
	if (sig == SIGUSR1)
		byte |= 128 >> i;
	i++;
	if (i == 8)
	{
		write(1, &byte, 1);
		byte = 0;
		i = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("PID is %d\n", getpid());
	while (1)
		pause();
	exit (EXIT_FAILURE);
}
