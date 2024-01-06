/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:15:49 by msoria-j          #+#    #+#             */
/*   Updated: 2022/12/11 19:54:59 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<errno.h>

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s1) + 1;
	str = (char *) ft_calloc(1, len);
	if (str)
	{
		while (i < len - 1)
		{
			str[i] = s1[i];
			i++;
		}
		str[i] = '\0';
	}
	else
	{
		errno = ENOMEM;
		return (NULL);
	}
	return (str);
}

/*
#include<stdio.h>

int	main(void)
{
	char	s1[] = "The strdup() function allocates sufficient memory";
	char	*str;

	str = ft_strdup(s1);
	printf ("String: %s\n", str);
	printf ("s1 Address: %p\n", s1);
	printf ("ft Address: %p\n", str);
	free(str);
}
*/