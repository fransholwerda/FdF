/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 14:04:10 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/08/31 16:24:29 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <err_msg.h>
#include <MLX42.h>
#include <stdlib.h>
#include <math.h>
#include <libft.h>


#include <stdio.h>

void	drawline(mlx_image_t *img, int x0, int y0, int x1, int y1, unsigned int rgb)
{
	int dx = abs (x1 - x0);
	int sx = x0 < x1 ? 1 : -1;
	int dy = -abs (y1 - y0);
	int sy = y0 < y1 ? 1 : -1;
	int err = dx + dy, e2;
	static int count = 0;

	count++;
	printf("#%d -> from %d,%d to %d,%d\n", count, x0, y0, x1, y1);
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

t_point	*next_row_pt(t_point *pt, int cols)
{
	int		i;

	i = 0;
	while (i < cols)
	{
		pt = pt->next;
		i++;
	}
	return (pt);
}

void	draw_reset(t_fdf *fdf)
{
	size_t	n;

	n = fdf->img->width * fdf->img->height * sizeof(int);
	ft_memset(fdf->img->pixels, 0, n);
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
	t_point	*pt2;

	draw_reset(fdf);
	i = 0;
	pt = map->point;
	pt2 = next_row_pt(pt, map->cols);
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			x0 = round(map->x_start + j * map->spacing - i * map->spacing);
			y0 = round((map->y_start + i * map->spacing + j * map->spacing) - pt->height);
			x1 = x0 + map->spacing;
			y1 = round(y0 + map->spacing + pt->height);
			if (j + 1 < map->cols)
				drawline(fdf->img, x0, y0, x1, round(y1 - pt->next->height), pt->color);
			if (i + 1 < map->rows)
				drawline(fdf->img, x0, y0, x1 - 2 * map->spacing, round(y1 - next_row_pt(pt, map->cols)->height), pt->color);
			if (!(i + 1 == map->rows && j + 1 == map->cols))
				pt = pt->next;
			j++;
		}
		if (i + 1 < map->rows)
			pt2 = next_row_pt(pt, map->cols);
		i++;
	}
}
