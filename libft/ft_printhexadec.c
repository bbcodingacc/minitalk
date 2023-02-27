/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexadec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarabog <mkarabog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 21:55:15 by mkarabog          #+#    #+#             */
/*   Updated: 2023/02/20 23:12:27 by mkarabog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lenfx(unsigned int x)
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

void	ft_printhexalow(unsigned long long decimal)
{
	char			*hex_list;
	unsigned int	remainder;

	hex_list = "abcdef";
	if (decimal >= 16)
		ft_printhexalow (decimal / 16);
	remainder = decimal % 16;
	if (remainder <= 9)
		ft_printchar(remainder + '0');
	else
	{	
		remainder = remainder - 10;
		write (1, (hex_list + remainder), 1);
	}
}

void	ft_printhexaup(unsigned int decimal)
{
	char	*hex_list;
	int		remainder;

	hex_list = "ABCDEF";
	if (decimal >= 16)
		ft_printhexaup (decimal / 16);
	remainder = decimal % 16;
	if (remainder <= 9)
		ft_printchar(remainder + '0');
	else
	{	
		remainder = remainder - 10;
		write (1, (hex_list + remainder), 1);
	}
}

int	ft_printhexadec(unsigned int decimal, int format)
{
	unsigned int	len;

	len = ft_lenfx(decimal);
	if (format == 'X')
		ft_printhexaup(decimal);
	else if (format == 'x')
		ft_printhexalow(decimal);
	return (len);
}
