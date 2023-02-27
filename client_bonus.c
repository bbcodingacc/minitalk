/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarabog <mkarabog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:22:18 by mkarabog          #+#    #+#             */
/*   Updated: 2023/02/26 20:14:46 by mkarabog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	printed(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("The message is printed!!!");
}

void	bit_right(unsigned char c, int pid)
{
	int		bit;

	bit = 7;
	while (bit >= 0)
	{
		if ((c >> bit) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit--;
	}
}

int	main(int ac, char *av[])
{
	int		pid;
	int		i;
	int		bit;

	if (ac != 3)
	{
		ft_printf("Invalid arguments !\n");
		return (0);
	}
	i = 0;
	pid = ft_atoi(av[1]);
	signal(SIGUSR1, printed);
	while (av[2][i] != '\0')
	{
		bit_right(av[2][i], pid);
		i++;
	}
	bit = 8;
	while (bit > 0)
	{
		kill(pid, SIGUSR2);
		bit--;
		usleep(100);
	}
	return (0);
}
