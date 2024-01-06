/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:03:22 by msoria-j          #+#    #+#             */
/*   Updated: 2022/12/06 16:10:59 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*d;
	char	*s;

	d = (char *) dst;
	s = (char *) src;
	i = 0;
	if (!dst && !src)
		return (dst);
	if (d > s)
	{
		while (len--)
			d[len] = s[len];
	}
	else
	{
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dst);
}

/*
#include<stdio.h>

int	main(void)
{
   const char src[50] = "http://www.tutorialspoint.com";
   char dest[50];
   
   ft_strlcpy(dest, "Heloooo!!", 10);
   printf("Before memcpy dest = %s\n", dest);
   ft_memmove(dest, src, ft_strlen(src)+1);
   printf("After memcpy dest = %s\n", dest);
   return(0);
}
*/
