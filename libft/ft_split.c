/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/01 19:49:03 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/02/17 19:02:47 by fransholwer   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_result(char **result, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		free(result[i]);
		i++;
	}
	free(result);
}

static size_t	word_count(char const *s, char c)
{
	size_t	count;
	size_t	i;

	if (ft_strlen(s) == 0)
		return (0);
	if (s[0] && !s[1])
		return (1);
	count = 0;
	i = 1;
	while (s[i])
	{
		if ((s[i] != c && s[i - 1] == c) || (i == 1 && s[0] != c))
			count++;
		i++;
	}
	return (count);
}

static char	*add_word(char const *s, char c, size_t i)
{
	size_t	count;
	size_t	j;
	char	*word;

	count = 0;
	while (s[i + count] != c && s[i + count])
		count++;
	word = malloc((count + 1) * sizeof(char));
	if (!word)
		return (NULL);
	j = 0;
	while (j < count)
	{
		word[j] = s[i];
		i++;
		j++;
	}
	word[count] = '\0';
	return (word);
}

static char	**fill_result(char **result, const char *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			result[j] = add_word(s, c, i);
			if (!result[j])
			{
				free_result(result, word_count(s, c));
				return (NULL);
			}
			j++;
			while (s[i] != c && s[i])
				i++;
		}
		if (s[i])
			i++;
	}
	result[j] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	if (!s)
		return (NULL);
	result = (char **)malloc((word_count(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	result = fill_result(result, s, c);
	if (!result)
		return (NULL);
	return (result);
}
