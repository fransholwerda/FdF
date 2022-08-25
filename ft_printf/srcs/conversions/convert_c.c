/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_c.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/09 16:12:38 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/02/09 16:21:26 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

int	convert_c(va_list *arg)
{
	char	c;

	c = va_arg(*arg, int);
	return (write(1, &c, 1));
}
