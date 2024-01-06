/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:14:08 by msoria-j          #+#    #+#             */
/*   Updated: 2022/12/06 14:35:44 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	while (n--)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	return (0);
}

/*
#include<string.h>
#include<stdio.h>

int	main(void)
{
	char str1[]="The memcmp() function compares byte ";
	char str2[]="The memcmp() function compares byte ";
	size_t	i;

	i = 80;
	printf("ft_memcmp: %d\n", ft_memcmp(str1, str2, i));
	printf("memcmp: %d\n", memcmp(str1, str2, i));
}
*/