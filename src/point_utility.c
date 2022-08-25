/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   point_utility.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/23 17:48:33 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/08/25 16:57:37 by fholwerd      ########   odam.nl         */
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
	return (pt);
}

t_point	*pt_add_back(t_point *dst, t_point *new)
{
	t_point	*first;

	if (!dst || !new)
		exit(EXIT_FAILURE);
	first = dst;
	while (dst->next)
		dst = dst->next;
	dst->next = new;
	return (first);
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
