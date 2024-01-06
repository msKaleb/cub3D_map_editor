/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 13:21:55 by msoria-j          #+#    #+#             */
/*   Updated: 2022/12/06 16:06:26 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*d;
	char	*s;

	d = (char *) dst;
	s = (char *) src;
	i = 0;
	if (dst == NULL && src == NULL)
		return (dst);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}

/*
#include<string.h>

int	main(void)
{
   const char src[50] = "http://www.tutorialspoint.com";
   char dest[50];
   
   ft_strlcpy(dest, "Heloooo!!", 10);
   printf("Before memcpy dest = %s\n", dest);
   ft_memcpy(dest, src, ft_strlen(src)+1);
   printf("After memcpy dest = %s\n", dest);
   
   return(0);
}
*/