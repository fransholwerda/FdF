/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/03 13:20:26 by fholwerd      #+#    #+#                 */
/*   Updated: 2020/12/03 13:29:53 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*d;
	size_t	n;
	size_t	i;

	if (!s)
		return (NULL);
	n = ft_strlen(s);
	d = malloc((n + 1) * sizeof(char));
	if (!d)
		return (NULL);
	i = 0;
	while (i < n)
	{
		d[i] = f(i, s[i]);
		i++;
	}
	d[i] = '\0';
	return (d);
}
