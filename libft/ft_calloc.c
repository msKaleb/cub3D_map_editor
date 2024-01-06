/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:54:04 by msoria-j          #+#    #+#             */
/*   Updated: 2022/12/05 15:45:35 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ret;
	size_t	bytes;
	size_t	i;

	bytes = count * size;
	i = 0;
	ret = (char *)malloc (bytes);
	if (ret != NULL)
	{
		while (i < bytes)
		{
			ret[i] = 0;
			i++;
		}
	}
	return ((void *) ret);
}

/*
int	main(void)
{
	void	*ptr;
	
	ptr = ft_calloc (3, 4);
	printf ("Address: %p\n", ptr);
	free(ptr);
	printf ("Freed");
}
*/