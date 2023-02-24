#include "minitalk.h"

void	bit_right(char c, int pid)
{
	int		bit;

	bit = 7;
	while (bit >= 0)
	{
		if((c >> bit) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100); // açıklamasına bak
		bit--;
	}
	
}

int main(int ac, char *av[])
{
    int		pid;
	int		i;
	
    if(ac != 3)
    {
        ft_printf("Invalid arguments !\n");
		return (0);
    }
	i = 0;
	pid = ft_atoi(av[1]);
	while (av[2][i] != '\0')
	{
	 	bit_right(av[2][i], pid);
		i++;
	}
	return (0);
}