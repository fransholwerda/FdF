/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/25 16:12:16 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/09/01 17:33:06 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <err_msg.h>
#include <get_next_line.h>
#include <libft.h>

#include <stdio.h>
static unsigned int	get_color(char *str)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(str))
	{
		if (str[i] == ',')
			return (0x00FFFFFF); //FIX THIS WITH COLOR
		i++;
	}
	return (0x00FFFFFF);
}

static void	fill_points(char **array, t_map *map)
{
	unsigned int	i;
	float			height;

	i = 0;
	map->cols = 0;
	while (array[i])
	{
		height = ft_atoi(array[i]);
		if (height > map->highest)
			map->highest = height;
		if (height < map->lowest)
			map->lowest = height;
		if (!map->point)
			map->point = pt_new(height, get_color(array[i]));
		else
			pt_add_back(map->point, pt_new(height, get_color(array[i])));
		i++;
		map->cols++;
	}
}

static void	get_points(int fd, t_map *map)
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
		fill_points(array, map);
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

t_map	*parse(int fd)
{
	t_map	*map;
	float	x_spacing;
	float	y_spacing;

	map = map_new();
	get_points(fd, map);
	x_spacing = WIDTH / (float)((map->cols + map->rows));
	y_spacing = (HEIGHT - map->highest + map->lowest) / (float)((map->rows + map->cols + 2));
	//printf("x_spacing: %f\ny_spacing: %f\n", x_spacing, y_spacing);
	if (x_spacing > y_spacing)
		map->spacing = floor(y_spacing);
	else
		map->spacing = floor(x_spacing);
	map->x_start = round(map->spacing * map->rows);
	map->y_start = round(map->spacing + map->highest);
	return (map);
}
