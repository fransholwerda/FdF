/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/25 16:12:16 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/08/25 18:04:42 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <err_msg.h>
#include <get_next_line.h>
#include <libft.h>

#include <stdio.h>

static void	fill_points(char *line, t_map *map)
{
	unsigned int	i;
	float			height;
	unsigned int	color;

	i = 0;
	map->cols = 0;
	while (i < ft_strlen(line))
	{
		height = ft_atoi(&line[i]);
		while (ft_isdigit(line[i]))
			i++;
		if (line[i] == ',')
		{
			//FIX THIS TO ADD ACTUAL COLOUR
			color = 0x00FFFFFF;
			i += 9;
			//FIX THIS TO ADD ACTUAL COLOUR
		}
		else
			color = 0x00FFFFFF;
		while (ft_isblank(line[i]))
			i++;
		if (!map->point)
			map->point = pt_new(height, color);
		else
			pt_add_back(map->point, pt_new(height, color));
		i++;
		map->cols++;
	}
}

static void	get_points(int fd, t_map *map)
{
	char	*line;
	t_point	*new_point;

	line = NULL;
	new_point = NULL;
	while (get_next_line(fd, &line))
	{
		map->rows++;
		fill_points(line, map);
		free(line);
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
	x_spacing = WIDTH / ((map->cols + 2) * 2);
	y_spacing = HEIGHT / ((map->rows + 2) * 2);
	if (x_spacing > y_spacing)
		map->spacing = y_spacing;
	else
		map->spacing = x_spacing;
	map->x_start = ((map->cols - 1) / 2 + 1) * x_spacing;
	map->y_start = y_spacing;
	return (map);
}
