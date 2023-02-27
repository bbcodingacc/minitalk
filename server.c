/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarabog <mkarabog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:22:20 by mkarabog          #+#    #+#             */
/*   Updated: 2023/02/25 14:24:25 by mkarabog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	bit_left(int sig)
{
	int			binary;
	static int	result = 0;
	static int	bit = 7;

	if (sig == SIGUSR1)
		binary = 1;
	else
		binary = 0;
	result = result + (binary << bit);
	if (bit == 0)
	{
		ft_printf("%c", result);
		bit = 7;
		result = 0;
	}
	else
		bit--;
}

int	main(void)
{
	int		pid;

	pid = getpid();
	ft_printf("PID = %d\n", pid);
	signal(SIGUSR1, bit_left);
	signal(SIGUSR2, bit_left);
	while (1)
		;
	return (0);
}
