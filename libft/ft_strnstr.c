/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:33:36 by msoria-j          #+#    #+#             */
/*   Updated: 2022/12/07 18:18:13 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	long	i;
	long	j;
	size_t	hlen;
	size_t	nlen;

	i = 0;
	j = 0;
	hlen = ft_strlen((char *)haystack);
	nlen = ft_strlen((char *)needle);
	if (!needle[0])
		return ((char *)haystack);
	if (len < nlen)
		return (NULL);
	if (len > hlen)
		len = hlen;
	while ((i <= (long)(len - nlen)) && (i <= (long)(hlen - nlen)))
	{
		while ((haystack[i + j] == needle[j]) && needle[j] && haystack[i + j])
			j++;
		if (!needle[j])
			return ((char *)haystack + i);
		j = 0;
		i++;
	}
	return (NULL);
}

/*
#include<string.h>
#include<stdio.h>

int	main(void)
{
	char	haystack[] = "aaxy";
	char	needle[] = "xy";
	char	*res;
	size_t	l;
	
	l = 2;
	res = strnstr(haystack, needle, l);
	printf ("sysstrnstr: %s-%p\n", res, res);
	res = ft_strnstr(haystack, needle, l);
	printf ("ft_strnstr: %s-%p\n", res, res);
	return (0);
}
*/