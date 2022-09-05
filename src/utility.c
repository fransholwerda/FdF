/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utility.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/21 15:10:04 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/09/05 17:32:51 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <MLX42.h>
#include <fdf.h>
#include <libft.h>
#include <stdlib.h>

t_fdf	*fdf_init(int32_t width, int32_t height, char *name)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	if (!fdf)
		return (NULL);
	fdf->mlx = mlx_init(width, height, name, true);
	if (!fdf->mlx)
		return (NULL);
	fdf->img = mlx_new_image(fdf->mlx, width, height);
	if (!fdf->img)
		return (NULL);
	fdf->map = NULL;
	return (fdf);
}

int	check_extension(char *file, char *extension)
{
	int	f_len;
	int	e_len;
	int	i;

	f_len = ft_strlen(file);
	e_len = ft_strlen(extension);
	if (f_len >= e_len + 2)
	{
		i = f_len - (e_len + 1);
		if (file[i] == '.' && ft_strncmp(&file[i + 1], extension, e_len) == 0)
			return (1);
	}
	return (0);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int	ft_isblank(char c)
{
	if (c == ' ')
		return (1);
	return (0);
}
