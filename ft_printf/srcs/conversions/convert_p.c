/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_p.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/09 16:13:57 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/02/09 16:48:42 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

static int	ft_putpointer(u_int64_t n)
{
	char	*hex;
	int		count;

	hex = "0123456789abcdef";
	count = 0;
	if (n >= 16)
		count += ft_putpointer(n / 16);
	count += write(1, &hex[n % 16], 1);
	return (count);
}

int	convert_p(va_list *arg)
{
	u_int64_t	ptr;
	int			count;

	ptr = va_arg(*arg, u_int64_t);
	count = write(1, "0x", 2);
	count += ft_putpointer(ptr);
	return (count);
}
