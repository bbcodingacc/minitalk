/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarabog <mkarabog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 16:58:51 by mkarabog          #+#    #+#             */
/*   Updated: 2022/12/21 19:01:50 by mkarabog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*duplicated;
	int		size;
	int		i;

	i = 0;
	size = ft_strlen(s1);
	duplicated = malloc((size + 1) * sizeof(char));
	if (duplicated == NULL)
		return (NULL);
	while (i < size)
	{
		duplicated[i] = s1[i];
		i++;
	}
	duplicated[i] = '\0';
	return (duplicated);
}
