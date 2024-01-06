/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:15:07 by msoria-j          #+#    #+#             */
/*   Updated: 2022/12/06 16:43:02 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	str = ft_calloc(1, len + 1);
	if (!str)
		return (NULL);
	while (i < len)
	{
		while (*s1)
		{
			str[i] = *s1;
			s1++;
			i++;
		}
		while (*s2)
		{
			str[i] = *s2;
			s2++;
			i++;
		}
	}
	return (str);
}

/*
#include<stdio.h>

int	main(void)
{
	char	*str;
	char	s1[] = "Reserva (con malloc(3))";
	char	s2[] = " y devuelve una nueva string";

	str = ft_strjoin(s1, s2);
	printf("%s\n", str);
	free(str);
}
*/