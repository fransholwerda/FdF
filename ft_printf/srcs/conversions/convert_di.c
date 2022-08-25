/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_di.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/09 16:13:51 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/02/15 14:18:24 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

static int	ft_putint(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		count = write(1, "-2", 2);
		count += ft_putint(147483648);
	}
	else if (n < 0)
	{
		count = write(1, "-", 1);
		count += ft_putint(n * -1);
	}
	else if (n >= 10)
	{
		count = ft_putint(n / 10);
		count += ft_putchar((n % 10) + '0');
	}
	else
		count += ft_putchar((n % 10) + '0');
	return (count);
}

int	convert_di(va_list *arg)
{
	int	n;

	n = va_arg(*arg, int);
	return (ft_putint(n));
}
