/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_u.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/09 16:13:48 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/02/15 12:57:01 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

static int	ft_putuint(u_int32_t n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count = ft_putuint(n / 10);
	count += ft_putchar((n % 10) + '0');
	return (count);
}

int	convert_u(va_list *arg)
{
	u_int32_t	n;

	n = va_arg(*arg, u_int32_t);
	return (ft_putuint(n));
}
