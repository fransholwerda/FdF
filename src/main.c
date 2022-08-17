/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/19 12:12:15 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/08/17 16:14:38 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <MLX42.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <libft.h>
#include <fdf.h>

void	hook(void *param)
{
	t_fdf		*fdf;
	mlx_t		*mlx;
	mlx_image_t	*img;

	fdf = param;
	mlx = fdf->mlx;
	img = fdf->img;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP) || (mlx_is_key_down(mlx, MLX_KEY_W)))
		img->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN) || (mlx_is_key_down(mlx, MLX_KEY_S)))
		img->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT) || (mlx_is_key_down(mlx, MLX_KEY_A)))
		img->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT) || (mlx_is_key_down(mlx, 68)))
		img->instances[0].x += 5;
}

int32_t	main(void)
{
	t_fdf		*fdf;
	mlx_image_t	*img;

	fdf = fdf_init(WIDTH, HEIGHT, "FdF");
	if (!fdf)
		exit(EXIT_FAILURE);
	img = fdf->img;
	ft_memset(img->pixels, 255, img->width * img->height * sizeof(int));
	drawline(img, 0, 0, 100, 100, 120);
	mlx_image_to_window(fdf->mlx, fdf->img, 0, 0);
	mlx_loop_hook(fdf->mlx, &hook, fdf);
	mlx_loop(fdf->mlx);
	mlx_terminate(fdf->mlx);
	return (EXIT_SUCCESS);
}
