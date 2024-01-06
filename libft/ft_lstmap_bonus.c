/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 17:05:48 by msoria-j          #+#    #+#             */
/*   Updated: 2022/12/11 18:16:31 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;
	t_list	*first_element;

	if (!lst)
		return (NULL);
	list = ft_lstnew(f(lst->content));
	if (!list)
		ft_lstclear(&list, del);
	first_element = list;
	lst = lst->next;
	while (lst)
	{
		list->next = ft_lstnew(f(lst->content));
		list = list->next;
		lst = lst->next;
	}
	return (first_element);
}
