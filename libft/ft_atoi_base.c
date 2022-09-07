/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/07 11:55:48 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/09/07 12:55:35 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	is_whitespace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\v' || c == '\r'
		|| c == '\f')
		return (1);
	return (0);
}

static int	base_value(int c, int base)
{
	char	*small_base;
	char	*big_base;
	int		i;

	small_base = "0123456789abcdefghijklmnopqrstuvwxyz";
	big_base = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	i = 0;
	while (i < base)
	{
		if (c == small_base[i] || c == big_base[i])
			return (i);
		i++;
	}
	return (-1);
}

u_int32_t	ft_atoi_base(const char *nptr, int base)
{
	u_int32_t	value;
	int			minus;
	int			i;

	value = 0;
	minus = 1;
	i = 0;
	while (is_whitespace(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
		minus = -1;
		i++;
	}
	while (base_value(nptr[i], base) != -1)
	{
		value = (value * base) + base_value(nptr[i], base);
		i++;
	}
	return (value * minus);
}
