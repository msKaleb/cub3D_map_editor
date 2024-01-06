/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:42:04 by msoria-j          #+#    #+#             */
/*   Updated: 2022/12/06 14:39:38 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	if (ft_strlen(s) < start)
	{
		str = malloc(1);
		if (!str || !s)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	i = 0;
	str = malloc (len + 1);
	if (str)
	{
		while (i < len)
		{
			str[i] = s[i + start];
			i++;
		}
		str[i] = '\0';
	}
	return (str);
}

/*
#include<stdio.h>

int	main(void)
{
	char	s1[] = "La string desde la que crear la substring.";
	char	*str;
	
	str = ft_substr(s1, 37, 9);
	printf("string: %s$\n", str);
	printf("s1:  %p\n", s1);
	printf("str: %p\n", str);
	free(str);
}
*/