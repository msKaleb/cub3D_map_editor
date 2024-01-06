/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 10:01:47 by msoria-j          #+#    #+#             */
/*   Updated: 2022/12/07 14:19:39 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}

/*
#include<stdio.h>

int	main(void)
{
	//char	str[] = "The strrchr() function locates the last occurrence of c.";
	char	str[] = "teste";

	//(void) argc;
	printf ("%p\n", ft_strrchr(str, '\0'));
}
*/