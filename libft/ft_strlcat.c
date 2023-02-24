/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarabog <mkarabog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 09:23:26 by mkarabog          #+#    #+#             */
/*   Updated: 2022/12/22 15:35:11 by mkarabog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	dstlen;
	size_t	i;
	size_t	j;

	i = 0;
	srclen = ft_strlen(src);
	if (dstsize == 0 && !dst)
		return (srclen);
	dstlen = ft_strlen(dst);
	j = dstlen;
	if (dstsize <= j)
		return (dstsize + srclen);
	while (src[i] != '\0' && j + 1 < dstsize)
		dst[j++] = src[i++];
	dst[j] = '\0';
	return (dstlen + srclen);
}
