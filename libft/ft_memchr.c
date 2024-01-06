/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 10:38:58 by msoria-j          #+#    #+#             */
/*   Updated: 2022/12/06 14:35:36 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (*str == (unsigned char) c)
			return (str);
		str++;
		i++;
	}
	return (NULL);
}

/*
#include<stdio.h>

int	main(int argc, char **argv)
{
	char	s1[] = "The strcmp() and strncmp() functions lexicographically";
	size_t	l;
	
	(void) argc;
	l = 60;
	printf ("%s\n", (char *) ft_memchr(s1, argv[1][0], l));
}
*/