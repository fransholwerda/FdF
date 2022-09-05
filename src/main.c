/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/19 12:12:15 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/09/05 17:34:03 by fholwerd      ########   odam.nl         */
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

static void	hook(void *param)
{
	t_fdf		*fdf;

	fdf = param;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fdf->mlx);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_UP))
		translate(fdf, 'y', -50);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_DOWN))
		translate(fdf, 'y', 50);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_LEFT))
		translate(fdf, 'x', -50);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_RIGHT))
		translate(fdf, 'x', 50);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_KP_ADD))
		zoom(fdf, 1);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_KP_SUBTRACT))
		zoom(fdf, -1);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_PAGE_UP))
		change_height(fdf, 1.1);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_PAGE_DOWN))
		change_height(fdf, 0.9);
}

static void	fdf(char *file_name)
{
	t_fdf		*fdf;
	mlx_image_t	*img;
	int			fd;

	fdf = fdf_init(WIDTH, HEIGHT, "FdF");
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		stop(ERR_FD);
	fdf->map = parse(fd);
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

int32_t	main(int argc, char *argv[])
{
	errno = 0;
	if (argc == 2)
	{
		if (check_extension(argv[1], "fdf\0"))
			fdf(argv[1]);
		else
			stop(ERR_FILE_EXTENSION);
	}
	else
		stop(ERR_FILE);
	return (EXIT_SUCCESS);
}
