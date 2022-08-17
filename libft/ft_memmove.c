/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 17:38:30 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/02/17 19:04:19 by fransholwer   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned char	*fd(unsigned char *d, unsigned const char *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}

static unsigned char	*fdo(unsigned char *d, unsigned const char *s, size_t n)
{
	while (n)
	{
		d[n - 1] = s[n - 1];
		n--;
	}
	return (d);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned const char	*s;
	unsigned char		*d;

	if (!dest && !src)
		return (NULL);
	s = (unsigned const char *)src;
	d = (unsigned char *)dest;
	if (d < s)
		d = fd(d, s, n);
	else
		d = fdo(d, s, n);
	return (dest);
}
