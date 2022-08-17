/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 16:19:06 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/02/07 21:21:22 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*ptrd;
	unsigned const char	*ptrs;

	ptrd = (unsigned char *)dest;
	ptrs = (unsigned const char *)src;
	while (n > 0)
	{
		if (*ptrs == (unsigned char)c)
		{
			*ptrd = *ptrs;
			ptrd++;
			return (ptrd);
		}
		*ptrd = *ptrs;
		ptrd++;
		ptrs++;
		n--;
	}
	return (NULL);
}
