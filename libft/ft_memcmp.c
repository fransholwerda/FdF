/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/04 19:36:24 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/02/07 21:21:34 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char	*ptr1;
	unsigned const char	*ptr2;

	ptr1 = s1;
	ptr2 = s2;
	if (n == 0)
		return (0);
	else
	{
		while (n > 0)
		{
			if (*ptr1 != *ptr2)
				return (*ptr1 - *ptr2);
			ptr1++;
			ptr2++;
			n--;
		}
	}
	return (0);
}
