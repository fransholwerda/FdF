/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/30 13:01:26 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/02/17 19:10:55 by fransholwer   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	if (needle[0] == '\0')
		return ((char *)&str[0]);
	i = 0;
	while (i < len && str[i] != '\0')
	{
		j = 0;
		while (i + j < len && str[i + j] != '\0' && str[i + j] == needle[j])
		{
			j++;
			if (needle[j] == '\0')
				return ((char *)&str[i]);
		}
		i++;
	}
	return (NULL);
}
