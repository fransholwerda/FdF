/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/09 13:38:35 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/02/15 15:23:25 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

static int	parse(const char *str, va_list *arg, int i)
{
	if (str[i] == 'c')
		i = convert_c(arg);
	else if (str[i] == 's')
		i = convert_s(arg);
	else if (str[i] == 'p')
		i = convert_p(arg);
	else if (str[i] == 'd')
		i = convert_di(arg);
	else if (str[i] == 'i')
		i = convert_di(arg);
	else if (str[i] == 'u')
		i = convert_u(arg);
	else if (str[i] == 'x')
		i = convert_hex(arg, 0);
	else if (str[i] == 'X')
		i = convert_hex(arg, 1);
	else if (str[i] == '%')
		i = write(1, "%", 1);
	return (i);
}

static int	print_str(const char *str, va_list *arg)
{
	int	i;
	int	printed;
	int	last_write;
	int	temp;

	i = 0;
	printed = 0;
	last_write = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			printed += write(1, str + last_write, i - last_write);
			temp = parse(str, arg, i + 1);
			if (temp < 0)
				return (temp);
			i += 2;
			printed += temp;
			last_write = i;
		}
		else
			i++;
	}
	printed += write(1, str + last_write, i - last_write);
	return (printed);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		error;

	va_start(arg, str);
	error = print_str(str, &arg);
	va_end(arg);
	return (error);
}
