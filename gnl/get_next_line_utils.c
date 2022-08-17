/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/03 15:49:27 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/05/19 12:31:22 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*s12;
	unsigned int	i;
	unsigned int	j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s12 = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (s12 == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s12[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		s12[i] = s2[j];
		i++;
		j++;
	}
	s12[i] = '\0';
	return (s12);
}

char	*ft_strdup(const char *s)
{
	char	*sdup;
	size_t	i;

	if (!s)
		return (NULL);
	sdup = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!sdup)
		return (NULL);
	i = 0;
	while (s[i])
	{
		sdup[i] = s[i];
		i++;
	}
	sdup[i] = '\0';
	return (sdup);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == 0)
		return ((char *)&s[i]);
	return (NULL);
}
