/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/09 13:37:02 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/02/15 14:06:46 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);

/* Conversions */
int	convert_c(va_list *arg);
int	convert_s(va_list *arg);
int	convert_p(va_list *arg);
int	convert_di(va_list *arg);
int	convert_u(va_list *arg);
int	convert_hex(va_list *arg, int big);

/* Utilities */
int	ft_strlen(char *str);
int	ft_putchar(char c);

#endif
