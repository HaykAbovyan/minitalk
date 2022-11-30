/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habovyan <habovyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 16:34:40 by habovyan          #+#    #+#             */
/*   Updated: 2022/10/10 16:34:18 by habovyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	handler(int sig, siginfo_t *info, void *context)
{
	static int		i;
	static char		byte;

	(void) context;
	if (sig == SIGUSR1)
		byte |= 128 >> i;
	i++;
	if (i == 8)
	{
		if (byte == '\0')
		{
			if (kill(info->si_pid, SIGUSR2) == -1)
				exit (EXIT_FAILURE);
		}
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
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	ft_printf("PID is %d\n", getpid());
	while (1)
		pause();
	exit (EXIT_FAILURE);
}
