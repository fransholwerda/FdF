/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_utility.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/23 17:48:30 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/09/07 13:30:42 by fholwerd      ########   odam.nl         */
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

void	translate(t_fdf *fdf, char xy, int amount)
{
	if (xy == 'x')
	{
		fdf->map->x_start += amount;
		draw(fdf, fdf->map);
	}
	else if (xy == 'y')
	{
		fdf->map->y_start += amount;
		draw(fdf, fdf->map);
	}
}

void	zoom(t_fdf *fdf, int amount)
{
	fdf->map->spacing += amount;
	draw(fdf, fdf->map);
}

void	change_height(t_fdf *fdf, float factor, int up)
{
	t_point	*pt;

	pt = fdf->map->point;
	while (pt)
	{
		if (up == 1)
			pt->height = pt->height * factor;
		else
			pt->height = pt->height / factor;
		pt = pt->next;
	}
	draw(fdf, fdf->map);
}

void	change_colour(t_fdf *fdf, u_int32_t rgb)
{
	fdf->rgb = rgb;
	draw(fdf, fdf->map);
}
