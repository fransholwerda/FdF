/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstlast.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 13:52:44 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/10/15 16:08:28 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	size_t	len;

	if (!lst)
		return (NULL);
	len = ft_lstsize(lst);
	while (len > 1)
	{
		lst = lst->next;
		len--;
	}
	return (lst);
}
