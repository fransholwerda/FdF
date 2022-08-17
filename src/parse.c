/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/25 16:12:16 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/08/17 12:39:06 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <err_msg.h>
#include <get_next_line.h>

int	ft_isblank(char c)
{
	if (c == " ")
		return (1);
	return (0);
}

int	fill_coord(char **line, t_map *map)
{
	int	i;
	int	last_coord;

	i = -1;
	while (++i < ft_strlen(*line))
	{
		last_coord = ft_atoi(*line);
		while (ft_isdigit(line[i]))
			i++;
	}
	map->cols = i;
}

int	parse(int fd, t_map	*map)
{
	char	*line;

	line = NULL;
	while (get_next_line(fd, &line))
	{
		map->cols++;
		free(line);
		line = NULL;
	}
	if (line)
		free(line);
	map->x_spacing = WIDTH / (map->cols + 2);
	map->y_spacing = HEIGHT / (map->rows + 2);
	if (map->x_spacing > map->y_spacing)
		map->x_spacing = map->y_spacing;
	else
		map->y_spacing = map->x_spacing;
	map->x_start = ((map->cols - 1) / 2 + 1) * map->x_spacing;
	map->y_start = map->y_spacing;
}
