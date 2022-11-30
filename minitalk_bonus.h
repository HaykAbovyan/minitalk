/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habovyan <habovyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 16:38:42 by habovyan          #+#    #+#             */
/*   Updated: 2022/10/09 18:01:43 by habovyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <sys/wait.h>
# include "ft_printf/ft_printf.h"

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define END "\033[0m"

void				handler(int sig, siginfo_t *info, void *context);
void				recieve(int sik);
void				send_mes(int pid, char *mes);
void				send_bits(int pid, char c);
int					ft_atoi(const char *str);

#endif