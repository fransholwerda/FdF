/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/25 16:12:16 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/08/23 17:49:34 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <err_msg.h>
#include <get_next_line.h>

static t_coord	*fill_coords(char *line, t_map *map)
{
	int				i;
	float			height;
	unsigned int	color;

	i = -1;
	while (++i < ft_strlen(line))
	{
		height = ft_atoi(&line[i]);
		while (ft_isdigit(line[i]))
			i++;
		if (line[i] == ',')
		{
			//FIX THIS TO ADD ACTUAL COLOUR
			color = 0x00FF0000;
			i += 9;
			//FIX THIS TO ADD ACTUAL COLOUR
		}
		else
			color = 0x00FF0000;
		while (ft_isblank(line[i]))
			i++;
	}
	map->cols = i;
}

static int	get_points(int fd, t_map *map)
{
	char	*line;
	t_coord	*new_coord;

	line = NULL;
	new_coord = NULL;
	while (get_next_line(fd, &line))
	{
		map->cols++;
		new_coord = fill_coords(line, map);
		free(line);
		line = NULL;
	}
	if (line)
		free(line);
}

int	parse(int fd, t_map	*map)
{
	if (get_points(fd, map) == 0)
	{
		fd = fd;
	}
	map->x_spacing = WIDTH / (map->cols + 2);
	map->y_spacing = HEIGHT / (map->rows + 2);
	if (map->x_spacing > map->y_spacing)
		map->x_spacing = map->y_spacing;
	else
		map->y_spacing = map->x_spacing;
	map->x_start = ((map->cols - 1) / 2 + 1) * map->x_spacing;
	map->y_start = map->y_spacing;
}
