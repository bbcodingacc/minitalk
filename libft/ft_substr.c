/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarabog <mkarabog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 19:04:52 by mkarabog          #+#    #+#             */
/*   Updated: 2022/12/21 20:27:55 by mkarabog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	x;

	if (!s)
		return (NULL);
	if (start > ft_strlen((char *)s) - 1)
		return (ft_strdup(""));
	x = ft_strlen(s) - start;
	if (len < x)
		x = len;
	sub = (char *)malloc(sizeof(char) * (x + 1));
	if (sub == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[start] != '\0')
	{
		sub[i] = s[start];
		i++;
		start++;
	}
	sub[i] = '\0';
	return (sub);
}
