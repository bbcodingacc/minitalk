/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarabog <mkarabog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 21:11:33 by mkarabog          #+#    #+#             */
/*   Updated: 2023/02/20 23:14:35 by mkarabog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_findlen(unsigned int n)
{
	int	len;

	len = 1;
	while (n > 9)
	{
		len++;
		n /= 10;
	}
	return (len);
}

int	ft_printunsigned(unsigned int decimal)
{
	int	len;

	if (decimal >= 10)
		ft_printunsigned(decimal / 10);
	ft_printchar((decimal % 10) + '0');
	len = ft_findlen(decimal);
	return (len);
}
