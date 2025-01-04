/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfeve <dfeve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 21:27:55 by dfeve             #+#    #+#             */
/*   Updated: 2024/12/30 23:52:14 by dfeve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	c_to_bit(char c, int pid)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & (0x01 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		bit++;
	}
}

void	send_str(char *str, int pid)
{
	int	i;

	i = 0;
	while (str[i])
	{
		c_to_bit(str[i], pid);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		ft_printf("\033[0;31m[ERROR] : WRONG NUMBER OF\
		 ARGUMENTS (must be 3)\n\033[0m");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	if (pid < 0)
	{
		ft_printf("\033[0;31m[ERROR] : INVALID PID (essaye pas \
		de niquer mon projet sale fou va)\n\033[0m");
		return (0);
	}
	send_str("\033[0;32m[MESSAGE RECEIVED]:\n", pid);
	send_str("-> \033[0;34m", pid);
	send_str(argv[2], pid);
	c_to_bit('\n', pid);
}
