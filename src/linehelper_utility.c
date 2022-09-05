/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   linehelper_utility.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/05 12:57:42 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/09/05 14:12:47 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <stdlib.h>

void	lh_init(t_linehelper *lh, t_coord *c0, t_coord *c1)
{
	lh->dx = abs(c1->x - c0->x);
	if (c0->x < c1->x)
		lh->sx = 1;
	else
		lh->sx = -1;
	lh->dy = -abs(c1->y - c0->y);
	if (c0->y < c1->y)
		lh->sy = 1;
	else
		lh->sy = -1;
	lh->err = lh->dx + lh->dy;
	lh->x = c0->x;
	lh->y = c0->y;
}
