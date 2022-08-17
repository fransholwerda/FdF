/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/03 15:49:30 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/10/29 12:18:34 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	cut_used_line(int fd, t_gnl *gnl, size_t i)
{
	char	*temp_str;
	char	*temp;

	if (!gnl->rest_fd[fd][0])
	{
		return (1);
	}
	temp_str = gnl->rest_fd[fd];
	temp = ft_strdup(&temp_str[i]);
	free(gnl->rest_fd[fd]);
	if (!temp)
		return (-1);
	gnl->rest_fd[fd] = temp;
	return (1);
}

static int	fill_line(char **line, int i, t_gnl *gnl, int fd)
{
	int	j;

	*line = malloc(sizeof(char) * (i + 1));
	if (!*line)
		return (-1);
	j = 0;
	while (j < i)
	{
		line[0][j] = gnl->rest_fd[fd][j];
		j++;
	}
	line[0][j] = '\0';
	return (1);
}

static int	check_line(int fd, t_gnl *gnl, char **line)
{
	size_t	i;
	int		return_value;

	i = 0;
	return_value = 1;
	while (gnl->rest_fd[fd][i] != '\n')
	{
		if (gnl->rest_fd[fd][i] == '\0')
		{
			return_value = 0;
			break ;
		}
		i++;
	}
	if (fill_line(line, i + 1, gnl, fd) == -1)
		return (-1);
	if (cut_used_line(fd, gnl, i + 1) == -1)
	{
		free(*line);
		*line = NULL;
		return (-1);
	}
	return (return_value);
}

int	get_next_line(int fd, char **line)
{
	static t_gnl	gnl;
	char			*temp;
	int				reading;

	if (!line || fd < 0 || fd > FD_TOTAL || BUFFER_SIZE < 1)
		return (-1);
	if (!gnl.rest_fd[fd])
		gnl.rest_fd[fd] = ft_strdup("\0");
	if (!gnl.rest_fd[fd])
		return (-1);
	reading = read(fd, gnl.buf, BUFFER_SIZE);
	while (reading > 0)
	{
		gnl.buf[reading] = '\0';
		temp = ft_strjoin(gnl.rest_fd[fd], gnl.buf);
		free(gnl.rest_fd[fd]);
		if (!temp)
			return (-1);
		gnl.rest_fd[fd] = temp;
		if (ft_strchr(gnl.rest_fd[fd], '\n'))
			break ;
		reading = read(fd, gnl.buf, BUFFER_SIZE);
	}
	return (check_line(fd, &gnl, line));
}
