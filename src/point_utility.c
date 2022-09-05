/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   point_utility.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/23 17:48:33 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/09/05 15:55:30 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <stdlib.h>

t_point	*pt_new(float height, unsigned int color)
{
	t_point	*pt;

	pt = malloc(sizeof(t_point));
	if (!pt)
		exit(EXIT_FAILURE);
	pt->height = height;
	pt->color = color;
	pt->next = NULL;
	pt->last = pt;
	return (pt);
}

void	pt_add_back(t_point *dst, t_point *new)
{
	if (!dst || !new)
		exit(EXIT_FAILURE);
	dst->last->next = new;
	dst->last = new;
}

void	pt_clear(t_point *pt)
{
	t_point	*temp;

	while (pt)
	{
		temp = pt;
		pt = pt->next;
		free(temp);
	}
}

t_point	*next_row_pt(t_point *pt, int cols)
{
	int		i;

	i = 0;
	while (i < cols)
	{
		pt = pt->next;
		i++;
	}
	return (pt);
}
