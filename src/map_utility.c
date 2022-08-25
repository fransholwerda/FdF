/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_utility.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/23 17:48:30 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/08/25 15:07:06 by fholwerd      ########   odam.nl         */
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
	map->x_spacing = 0;
	map->x_start = 0;
	map->y_spacing = 0;
	map->y_start = 0;
	return (map);
}
