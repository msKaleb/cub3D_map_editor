/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:02:00 by msoria-j          #+#    #+#             */
/*   Updated: 2022/12/08 17:24:50 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*t_new;

	t_new = (t_list *)malloc (sizeof(t_list));
	if (!t_new)
		return (NULL);
	t_new->content = content;
	t_new->next = NULL;
	return (t_new);
}

/*
#include<stdio.h>

int	main(void)
{
	t_list	*k;

	k = ft_lstnew("mikel");
	printf("%s", k->content);
	free(k);
}
*/