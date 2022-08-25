/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 14:04:10 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/08/25 18:05:05 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <err_msg.h>
#include <MLX42.h>
#include <stdlib.h>
#include <math.h>


#include <stdio.h>

void	drawline(mlx_image_t *img, int x0, int y0, int x1, int y1, unsigned int rgb)
{
	int dx = abs (x1 - x0);
	int sx = x0 < x1 ? 1 : -1;
	int dy = -abs (y1 - y0);
	int sy = y0 < y1 ? 1 : -1;
	int err = dx + dy, e2;

	while (1)
	{
		if (x0 >= 0 && x0 < WIDTH && y0 >= 0 && y0 < HEIGHT)
			mlx_put_pixel(img, x0, y0, rgb);
		if ((x0 == x1) && (y0 == y1))
			break ;
		e2 = 2 * err;
		if (e2 >= dy)
		{
			err += dy;
			x0 += sx;
		}
		if (e2 <= dx)
		{
			err += dx;
			y0 += sy;
		}
	}
}

void	draw(t_fdf *fdf, t_map *map)
{
	int		i;
	int		j;
	int		x0;
	int		x1;
	int		y0;
	int		y1;
	t_point	*pt;

	i = 0;
	pt = map->point;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			x0 = round(map->x_start + j * map->spacing - i * map->spacing);
			y0 = round(map->y_start + i * map->spacing + j * map->spacing);
			x1 = x0 + map->spacing;
			y1 = y0 + map->spacing;
			if (j + 1 < map->cols)
				drawline(fdf->img, x0, y0, x1, y1, pt->color);
			if (i + 1 < map->rows)
				drawline(fdf->img, x0, y0, x1 - 2 * map->spacing, y1, pt->color);
			j++;
		}
		i++;
	}
}
