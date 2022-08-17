/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 15:58:54 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/02/07 21:21:39 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*ptrd;
	unsigned const char	*ptrs;

	if (dest == NULL && src == NULL)
		return (NULL);
	ptrd = (unsigned char *)dest;
	ptrs = (unsigned const char *)src;
	while (n > 0)
	{
		*ptrd = *ptrs;
		ptrd++;
		ptrs++;
		n--;
	}
	return (dest);
}
