/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfeve <dfeve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 00:10:07 by dfeve             #+#    #+#             */
/*   Updated: 2024/12/27 23:40:39 by dfeve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_sig_usr(int code)
{
	static int	c;
	static int	bit;

	if (code == SIGUSR1)
		c |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", c);
		c = 0;
		bit = 0;
	}
}

int	main(void)
{
	banner();
	ft_printf("PID: %d\n", getpid());
	while (1)
	{
		signal(SIGUSR1, &handle_sig_usr);
		signal(SIGUSR2, &handle_sig_usr);
		pause();
	}
	return (0);
}
