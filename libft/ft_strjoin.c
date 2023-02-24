/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarabog <mkarabog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 19:29:45 by mkarabog          #+#    #+#             */
/*   Updated: 2022/12/21 19:59:13 by mkarabog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*conc;
	int		x;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	x = ft_strlen(s1) + ft_strlen(s2);
	conc = malloc ((x + 1) * sizeof(char));
	if (conc == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		conc[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		conc[i + j] = s2[j];
		j++;
	}
	conc[i + j] = '\0';
	return (conc);
}
