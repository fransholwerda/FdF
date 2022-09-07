/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/25 16:12:16 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/09/07 13:25:08 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <err_msg.h>
#include <get_next_line.h>
#include <libft.h>

static unsigned int	get_color(t_fdf *fdf, char *str)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(str))
	{
		if (str[i] == ',')
			return (ft_atoi_base(&str[i + 3], 16) * 256 + 0xFF);
		i++;
	}
	return (fdf->line_rgb);
}

static void	fill_points(t_fdf *fdf, char **array, t_map *map)
{
	unsigned int	i;
	float			height;

	i = 0;
	map->cols = 0;
	while (array[i])
	{
		if (array[i][0] != '\n')
		{
			height = ft_atoi(array[i]);
			if (height > map->highest)
				map->highest = height;
			if (height < map->lowest)
				map->lowest = height;
			if (!map->point)
				map->point = pt_new(height, get_color(fdf, array[i]));
			else
				pt_add_back(map->point, pt_new(height,
						get_color(fdf, array[i])));
			map->cols++;
		}
		i++;
	}
}

static void	get_points(t_fdf *fdf, int fd, t_map *map)
{
	char	*line;
	char	**array;
	t_point	*new_point;
	int		rv;

	line = NULL;
	new_point = NULL;
	rv = get_next_line(fd, &line);
	while (rv == 1)
	{
		array = ft_split(line, ' ');
		map->rows++;
		fill_points(fdf, array, map);
		free(line);
		free_array(array);
		line = NULL;
		rv = get_next_line(fd, &line);
	}
	if (rv == -1)
		stop(ERR_FD);
	if (line)
		free(line);
}

t_map	*parse(t_fdf *fdf, int fd)
{
	t_map	*map;
	float	x_spacing;
	float	y_spacing;

	map = map_new();
	get_points(fdf, fd, map);
	x_spacing = WIDTH / (float)((map->cols + map->rows));
	y_spacing = (HEIGHT - map->highest + map->lowest)
		/ (float)((map->rows + map->cols + 2));
	if (x_spacing > y_spacing)
		map->spacing = floor(y_spacing);
	else
		map->spacing = floor(x_spacing);
	map->x_start = round(map->spacing * map->rows);
	map->y_start = round(map->spacing + map->highest);
	return (map);
}
