/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_s.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/09 16:13:54 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/02/15 14:15:07 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

int	convert_s(va_list *arg)
{
	char	*str;

	str = va_arg(*arg, char *);
	if (str)
		return (write(1, str, ft_strlen(str)));
	else
		return (write(1, "(null)", 6));
}
