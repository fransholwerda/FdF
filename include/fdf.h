/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/25 15:30:36 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/08/17 16:13:47 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include <errno.h>
# include <MLX42.h>

# ifndef WIDTH
#  define WIDTH 1280
# endif
# ifndef HEIGHT
#  define HEIGHT 720
# endif

typedef struct s_coord
{
	float			height;
	unsigned int	color;
	struct s_coord	*next;
}					t_coord;

typedef struct s_map
{
	float	x_start;
	float	y_start;
	float	x_spacing;
	float	y_spacing;
	int		cols;
	int		rows;
	t_coord	*coord;
}			t_map;

typedef struct s_fdf
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_fdf;

/**
 * Initilizes a new fdf Instance.
 * 
 * @param[in] width The width of the window.
 * @param[in] height The height of the window.
 * @param[in] title The title of the window.
 * @returns Ptr to the fdf handle or null on failure.
 */
t_fdf	*fdf_init(int32_t width, int32_t height, char *name);

void	drawline(mlx_image_t *img, int x0, int y0, int x1, int y1, unsigned int rgb);

#endif
