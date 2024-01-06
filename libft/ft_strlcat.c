/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:37:59 by msoria-j          #+#    #+#             */
/*   Updated: 2022/12/06 14:38:00 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dest_index;
	size_t	src_index;
	size_t	srclen;
	size_t	orig_destlen;

	orig_destlen = ft_strlen(dst);
	srclen = ft_strlen(dst) + ft_strlen(src);
	dest_index = ft_strlen(dst);
	src_index = 0;
	if (dstsize != 0)
	{
		while (src[src_index] && dest_index < dstsize - 1)
		{
			dst[dest_index] = src[src_index];
			src_index++;
			dest_index++;
		}
		dst[dest_index] = '\0';
	}
	if (orig_destlen > dstsize)
		srclen = ft_strlen(src) + dstsize;
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
	i = ft_strlcat(dest, src, n);
	printf("%s\n", dest);
	printf("%d", i);
	return (0);
}
*/