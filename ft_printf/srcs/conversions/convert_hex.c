/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_hex.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/09 16:13:42 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/02/15 13:37:34 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

static int	ft_puthex(u_int32_t n, int big)
{
	char	*small_hex;
	char	*big_hex;
	int		count;

	small_hex = "0123456789abcdef";
	big_hex = "0123456789ABCDEF";
	count = 0;
	if (n >= 16)
		count = ft_puthex(n / 16, big);
	if (big)
		count += ft_putchar(big_hex[n % 16]);
	else
		count += ft_putchar(small_hex[n % 16]);
	return (count);
}

int	convert_hex(va_list *arg, int big)
{
	u_int32_t	n;

	n = va_arg(*arg, u_int32_t);
	return (ft_puthex(n, big));
}
