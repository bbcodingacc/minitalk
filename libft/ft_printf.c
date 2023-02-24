/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarabog <mkarabog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 02:33:00 by mkarabog          #+#    #+#             */
/*   Updated: 2023/02/20 23:11:06 by mkarabog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_format(va_list args, const char c)
{	
	int		len;

	len = 0;
	if (c == 'c')
		len = ft_printchar(va_arg(args, int));
	else if (c == 's')
		len = ft_printstring(va_arg(args, char *));
	else if (c == 'p')
		len = ft_printhexaptr(va_arg(args, unsigned long long));
	else if (c == 'd' || c == 'i')
		len = ft_printdecimal(va_arg(args, int));
	else if (c == 'u')
		len = ft_printunsigned(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		len = ft_printhexadec(va_arg(args, unsigned int), c);
	else if (c == '%')
		len = ft_printpercent();
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			len += ft_format(args, str[i]);
		}
		else
			len += ft_printchar(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}
