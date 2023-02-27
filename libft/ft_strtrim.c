/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarabog <mkarabog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 10:59:24 by mkarabog          #+#    #+#             */
/*   Updated: 2022/12/21 20:25:08 by mkarabog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	isexist(char a, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == a)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		start;
	int		finish;
	char	*trimmed;

	i = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	while (s1[i] != '\0' && isexist(s1[i], set) == 1)
		i++;
	start = i;
	i = ft_strlen(s1) - 1;
	while (i >= start && isexist(s1[i], set) == 1)
		i--;
	finish = i;
	trimmed = malloc(sizeof(char) * ((finish - start) + 2));
	if (trimmed == NULL)
		return (NULL);
	i = 0;
	ft_strlcpy (trimmed, &s1[start], finish - start + 2);
	return (trimmed);
}
