/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/04 17:29:41 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/10/08 18:51:06 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*ptr;

	c %= 256;
	ptr = s;
	while (n > 0)
	{
		if (*ptr == c)
			return ((char *)ptr);
		ptr++;
		n--;
	}
	return (NULL);
}
