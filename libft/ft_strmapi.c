/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:58:37 by msoria-j          #+#    #+#             */
/*   Updated: 2022/12/11 15:48:46 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

/*char	func(unsigned int n, char c)
{
	n = 0;
	return (c);
}*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	str = ft_calloc(1, ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = (*f)(i, s[i]);
		i++;
	}
	return (str);
}

/*
#include<stdio.h>

int	main(void)
{
	char	str[] = "La string creada tras el correcto uso de f.";
	char	*res;

	res = ft_strmapi(str, func);
	printf("%s\n", res);
	free (res);
}
*/