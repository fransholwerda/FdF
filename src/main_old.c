/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/25 15:29:54 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/04/08 14:37:19 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/err_msg.h"
#include "../gnl/get_next_line.h"
#include <errno.h>
#include <fcntl.h>

void	stop(char *s)
{
	if (errno == 0)
		ft_putendl_fd(s, 2);
	else
		perror(s);
	exit(1);
}

void	my_mlx_pixel_put(t_fdf *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

t_fdf	*fdf_init(void)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	if (!fdf)
		stop(ERR_INIT);
	fdf->mlx = mlx_init(WIDTH, HEIGHT, "FdF", false);
	if (!fdf->mlx)
		stop(ERR_INIT);
	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	if (!fdf->img)
		stop(ERR_INIT);
	fdf->addr = mlx_get_data_addr(fdf->img, &fdf->bits_per_pixel,
			&fdf->line_length, &fdf->endian);
	return (fdf);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_fdf	*fdf;

	errno = 0;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			stop(ERR_FD);
		fdf = fdf_init();
		my_mlx_pixel_put(fdf, 50, 50, 0x00FF0000);
		mlx_put_image_to_window(fdf, fdf->win, fdf->img, 0, 0);
		mlx_loop(fdf->mlx);
	}
	stop(ERR_FILE);
	return (0);
}
