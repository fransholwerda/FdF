/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 14:04:10 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/08/17 16:16:47 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <err_msg.h>
#include <MLX42.h>
#include <stdlib.h>

// int	draw(void)
// {
// 	parse();
// }

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