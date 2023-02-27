/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarabog <mkarabog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 16:47:19 by mkarabog          #+#    #+#             */
/*   Updated: 2022/12/21 10:48:37 by mkarabog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	count(long int nb)
{	
	int		quantity;

	quantity = 1;
	if (nb < 0)
	{
		quantity++;
		nb *= -1;
	}
	while (nb >= 10)
	{
		nb /= 10;
		quantity++;
	}
	return (quantity);
}	

char	*ft_itoa(int n)
{
	char		*str;
	int			i;
	long int	nb;

	nb = n;
	str = malloc((count(nb) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = count(nb);
	if (nb < 0)
	{	
		str[0] = '-';
		nb *= -1;
	}
	str[i] = '\0';
	i -= 1;
	while (nb >= 10)
	{
		str[i] = (nb % 10) + '0';
		nb /= 10;
		i--;
	}
	str[i] = nb + '0';
	return (str);
}
