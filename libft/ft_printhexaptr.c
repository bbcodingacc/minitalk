/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexaptr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarabog <mkarabog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:08:26 by mkarabog          #+#    #+#             */
/*   Updated: 2023/02/20 23:12:57 by mkarabog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lenf(unsigned long long x)
{
	int	len;

	len = 0;
	if (x == 0)
		len = 1;
	while (x > 0)
	{
		x = x / 16;
		len += 1;
	}
	return (len);
}

void	ft_printhexamain(unsigned long long decimal)
{
	char	*hex_list;
	int		remainder;

	hex_list = "abcdef";
	if (decimal >= 16)
		ft_printhexamain (decimal / 16);
	remainder = decimal % 16;
	if (remainder <= 9)
		ft_printchar(remainder + '0');
	else
	{	
		remainder = remainder - 10;
		write (1, (hex_list + remainder), 1);
	}
}

int	ft_printhexaptr(unsigned long long decimal)
{
	int		len;

	len = ft_lenf(decimal);
	ft_printchar('0');
	ft_printchar('x');
	ft_printhexamain(decimal);
	return (len + 2);
}
