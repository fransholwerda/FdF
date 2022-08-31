/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/25 16:12:16 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/08/31 17:56:37 by fholwerd      ########   odam.nl         */
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

	line = NULL;
	new_point = NULL;
	while (get_next_line(fd, &line))
	{
		array = ft_split(line, ' ');
		map->rows++;
		fill_points(array, map);
		free(line);
		free_array(array);
		line = NULL;
	}
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
	y_spacing = (HEIGHT - map->highest + map->lowest) / (float)((map->rows + map->cols));
	//printf("x_spacing: %f\ny_spacing: %f\n", x_spacing, y_spacing);
	if (x_spacing > y_spacing)
		map->spacing = y_spacing;
	else
		map->spacing = x_spacing;
	map->x_start = round(map->spacing * map->rows);
	map->y_start = round(map->spacing + map->highest);
	return (map);
}
