/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   coord_utility.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/03 17:03:58 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/09/05 12:25:32 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <stdlib.h>
#include <err.h>
#include <err_msg.h>

t_coord	*init_coord(void)
{
	t_coord	*c0;

	c0 = malloc(sizeof(t_coord));
	if (!c0)
		stop(ERR_COORD_INIT);
	return (c0);
}
