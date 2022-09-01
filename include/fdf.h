/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/25 15:30:36 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/09/01 15:57:49 by fholwerd      ########   odam.nl         */
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
#  define WIDTH 2240
# endif
# ifndef HEIGHT
#  define HEIGHT 1260
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
	float	spacing;
	int		cols;
	int		rows;
	float	highest;
	float	lowest;
	t_point	*point;
}			t_map;

typedef struct s_fdf
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_map		*map;
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
 * @param[in] name The title of the window.
 * @returns Ptr to the fdf handle or null on failure.
 */
t_fdf	*fdf_init(int32_t width, int32_t height, char *name);

/**
 * Frees the content of the array and the array itself.
 * 
 * @param[in] array The array to be freed.
 */
void	free_array(char **array);

/**
 * Tests whether the input is blank space.
 * 
 * @param[in] c The char being tested.
 * @returns Returns 1 if it's blank, 0 if not.
 */
int		ft_isblank(char c);

/**
 * Will parse the given file and store information in a t_map object
 * 
 * @param[in] file The file provided by the user.
 * @returns Ptr to the map handle or null on failure.
 */
t_map	*parse(int fd);

/**
 * Functions for adding t_point objects and clearing them
 */
t_point	*pt_new(float height, unsigned int color);
t_point	*pt_add_back(t_point *dst, t_point *new);
void	pt_clear(t_point *pt);

/**
 * Function for initializing a t_map object
 */
t_map	*map_new(void);

/**
 * Prints out errno error if there is one, otherwise the given string.
 * 
 * @param[in] s (string) The message printed on error.
 */
void	stop(char *s);

void	draw(t_fdf *fdf, t_map *map);
void	drawline(mlx_image_t *img, int x0, int y0, int x1, int y1, unsigned int rgb);

#endif
