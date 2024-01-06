/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:44:12 by msoria-j          #+#    #+#             */
/*   Updated: 2022/12/06 16:49:58 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	srclen;

	srclen = ft_strlen(src);
	i = 0;
	if (dstsize > 0)
	{
		while (src[i] && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (srclen);
}

/*
#include<stdio.h>

int main(void)
{
	char	src[] = "salut, coMment tU vAs ? 42motS quarAnte-deux; cinquante+et+un";
	char	c;
	char	*dest;
	int		i = 0;
	int		n = 27;

	dest = &c;
	i = ft_strlcpy(dest, src, n);
	printf("%s\n", dest);
	printf("%d", i);
	return (0);
}
*/