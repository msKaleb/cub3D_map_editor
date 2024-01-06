/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 09:41:25 by msoria-j          #+#    #+#             */
/*   Updated: 2022/12/06 14:37:37 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

/* -- (!*str) will be true if (*str) is '\0' -- */
char	*ft_strchr(const char *s, int c)
{
	char	cc;
	char	*str;

	str = (char *) s;
	cc = (char) c;
	while (*str != cc)
	{
		if (!*str)
			return (NULL);
		str++;
	}
	return (str);
}

/*
#include<stdio.h>

int	main(int argc, char **argv)
{
	char	str[] = "The strchr() function locates the first occurrence of c";

	(void) argc;
	printf ("%p\n", ft_strchr(str, argv[1][0]));
}
*/