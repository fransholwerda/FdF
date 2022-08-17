/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/11 17:18:19 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/02/07 21:45:33 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dlen;
	size_t	i;

	dlen = ft_strlen(dst);
	if ((size - dlen - 1) < size)
	{
		i = 0;
		while (i < (size - dlen - 1) && src[i])
		{
			dst[dlen + i] = src[i];
			i++;
		}
		dst[dlen + i] = '\0';
	}
	if (size < dlen)
		return (size + ft_strlen(src));
	return (dlen + ft_strlen(src));
}
