/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/03 13:40:15 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/10/15 16:41:35 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lstf;
	t_list	*lptr;

	if (!lst || !f || !del)
		return (NULL);
	lstf = NULL;
	lptr = lstf;
	while (lst)
	{
		lstf = ft_lstnew(f(lst->content));
		if (!lstf)
		{
			ft_lstclear(&lptr, del);
			free(lptr);
			return (NULL);
		}
		lst = lst->next;
		ft_lstadd_back(&lptr, lstf);
	}
	return (lptr);
}
