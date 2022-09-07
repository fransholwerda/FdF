/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   colours.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/07 12:21:07 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/09/07 13:27:09 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOURS_H
# define COLOURS_H

typedef enum colours
{
	BLACK	= 0x000000FF,
	WHITE	= 0xFFFFFFFF,
	RED		= 0xFF000088,
	LIME	= 0x00FF0088,
	BLUE	= 0x0000FF88,
	YELLOW	= 0xFFFF0088,
	CYAN	= 0x00FFFF88,
	MAGENTA	= 0xFF00FF88,
	SILVER	= 0xC0C0C0FF,
	GRAY	= 0x808080FF,
	MAROON	= 0x800000FF,
	OLIVE	= 0x808000FF,
	GREEN	= 0x008000FF,
	PURPLE	= 0x800080FF,
	TEAL	= 0x008080FF,
	NAVY	= 0x000080FF,
}	t_colours;

#endif