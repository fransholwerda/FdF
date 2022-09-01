/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/19 12:12:15 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/09/01 16:54:51 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <MLX42.h>
#include <stdlib.h>
#include <unistd.h>
#include <libft.h>
#include <fdf.h>
#include <err_msg.h>


#include <stdio.h>

void	stop(char *s)
{
	if (errno == 0)
		ft_putendl_fd(s, 2);
	else
		perror(s);
	exit(EXIT_FAILURE);
}

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
	{
		fdf->map->y_start -= 50;
		draw(fdf, fdf->map);
	}
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN) || (mlx_is_key_down(mlx, MLX_KEY_S)))
	{
		fdf->map->y_start += 50;
		draw(fdf, fdf->map);
	}
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT) || (mlx_is_key_down(mlx, MLX_KEY_A)))
	{
		fdf->map->x_start -= 50;
		draw(fdf, fdf->map);
	}
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT) || (mlx_is_key_down(mlx, 68)))
	{
		fdf->map->x_start += 50;
		draw(fdf, fdf->map);
	}
	if (mlx_is_key_down(mlx, MLX_KEY_KP_ADD))
	{
		fdf->map->spacing++;
		draw(fdf, fdf->map);
	}
	if (mlx_is_key_down(mlx, MLX_KEY_KP_SUBTRACT))
	{
		fdf->map->spacing--;
		draw(fdf, fdf->map);
	}
}

int32_t	main(int argc, char *argv[])
{
	t_fdf		*fdf;
	mlx_image_t	*img;
	int			fd;

	errno = 0;
	if (argc == 2)
	{
		fdf = fdf_init(WIDTH, HEIGHT, "FdF");
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			stop(ERR_FD);
		printf("Before parsing.\n");
		fdf->map = parse(fd);
		printf("After parsing.\n");
		printf("x_start: %f\ny_start: %f\nspacing: %f\ncols:    %d\nrows:    %d\n", fdf->map->x_start, fdf->map->y_start, fdf->map->spacing, fdf->map->cols, fdf->map->rows);
		printf("highest: %f\nlowest:  %f\n", fdf->map->highest, fdf->map->lowest);
		close(fd);
		if (!fdf || !fdf->map)
			stop(ERR_INIT);
		img = fdf->img;
		ft_memset(img->pixels, 0, img->width * img->height * sizeof(int));
		draw(fdf, fdf->map);
		mlx_image_to_window(fdf->mlx, fdf->img, 0, 0);
		mlx_loop_hook(fdf->mlx, &hook, fdf);
		mlx_loop(fdf->mlx);
		mlx_terminate(fdf->mlx);
	}
	else
		stop(ERR_FILE);
	return (EXIT_SUCCESS);
}
