/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdecimal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarabog <mkarabog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:06:16 by mkarabog          #+#    #+#             */
/*   Updated: 2023/02/20 23:10:44 by mkarabog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_findlenf(int n)
{
	int	len;

	if (n < 0)
		len = 1;
	else
		len = 0;
	while (n < -9 || n > 9)
	{
		len++;
		n /= 10;
	}
	len++;
	return (len);
}

int	ft_printdecimal(int decimal)
{
	int	len;

	len = ft_findlenf(decimal);
	if (decimal == -2147483648)
		return (write(1, "-2147483648", 11));
	else if (decimal < 0)
	{
		decimal *= -1;
		write(1, "-", 1);
		ft_printdecimal(decimal);
	}
	else
	{
		if (decimal >= 10)
			ft_printdecimal(decimal / 10);
		ft_printchar((decimal % 10) + '0');
	}
	return (len);
}
