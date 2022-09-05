/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 14:04:10 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/09/05 17:14:01 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <err_msg.h>
#include <MLX42.h>
#include <stdlib.h>
#include <math.h>
#include <libft.h>

static void	drawline(mlx_image_t *img, t_coord *c0, t_coord *c1, u_int32_t rgb)
{
	t_linehelper	lh;

	lh_init(&lh, c0, c1);
	while (1)
	{
		if (lh.x >= 0 && lh.x < WIDTH && lh.y >= 0 && lh.y < HEIGHT)
			mlx_put_pixel(img, lh.x, lh.y, rgb);
		if ((lh.x == c1->x) && (lh.y == c1->y))
			break ;
		lh.e2 = 2 * lh.err;
		if (lh.e2 >= lh.dy)
		{
			lh.err += lh.dy;
			lh.x += lh.sx;
		}
		if (lh.e2 <= lh.dx)
		{
			lh.err += lh.dx;
			lh.y += lh.sy;
		}
	}
}

static void	draw_reset(t_fdf *fdf)
{
	size_t	n;

	n = fdf->img->width * fdf->img->height * sizeof(int);
	ft_memset(fdf->img->pixels, 0, n);
}

static void	set_coords(t_fdf *fdf, t_point *pt, int x, int y)
{
	t_coord	*c0;
	t_coord	*c1;
	int		tmp_y;

	c0 = init_coord();
	c1 = init_coord();
	c0->x = round(fdf->map->x_start + x * fdf->map->spacing - y
			* fdf->map->spacing);
	c0->y = round((fdf->map->y_start + y * fdf->map->spacing + x
				* fdf->map->spacing) - pt->height);
	c1->x = c0->x + fdf->map->spacing;
	c1->y = round(c0->y + fdf->map->spacing + pt->height);
	tmp_y = c1->y;
	if (x + 1 < fdf->map->cols && pt->next)
	{
		c1->y = round(c1->y - pt->next->height);
		drawline(fdf->img, c0, c1, pt->color);
	}
	if (y < (fdf->map->rows - 1))
	{
		c1->x = c1->x - 2 * fdf->map->spacing;
		c1->y = round(tmp_y - next_row_pt(pt, fdf->map->cols)->height);
		drawline(fdf->img, c0, c1, pt->color);
	}
}

void	draw(t_fdf *fdf, t_map *map)
{
	int		x;
	int		y;
	t_point	*pt;

	draw_reset(fdf);
	y = 0;
	pt = map->point;
	while (y < map->rows)
	{
		x = 0;
		while (x < map->cols)
		{
			set_coords(fdf, pt, x, y);
			if (pt->next)
				pt = pt->next;
			x++;
		}
		y++;
	}
}
