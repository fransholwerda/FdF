/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/25 15:30:36 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/08/23 12:15:46 by fholwerd      ########   odam.nl         */
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

typedef struct s_point
{
	float			height;
	unsigned int	color;
	struct s_point	*next;
}					t_point;

typedef struct s_coord
{
	int	x;
	int	y;
}				t_coord;

typedef struct s_map
{
	float	x_start;
	float	y_start;
	float	x_spacing;
	float	y_spacing;
	int		cols;
	int		rows;
	t_point	*point;
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

/**
 * Tests whether the input is blank space.
 * 
 * @param[in] c The char being tested.
 * @returns Returns 1 if it's blank, 0 if not.
 */
int		ft_isblank(char c);

void	drawline(mlx_image_t *img, int x0, int y0, int x1, int y1, unsigned int rgb);

#endif
