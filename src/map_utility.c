/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_utility.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/23 17:48:30 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/08/31 13:09:47 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <stdlib.h>
#include <err_msg.h>

t_map	*map_new(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		stop(ERR_MAP_INIT);
	map->point = NULL;
	map->cols = 0;
	map->rows = 0;
	map->spacing = 0;
	map->x_start = 0;
	map->y_start = 0;
	map->highest = -2147483648;
	map->lowest = 2147483647;
	return (map);
}
