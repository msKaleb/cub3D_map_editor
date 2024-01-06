/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:22:26 by msoria-j          #+#    #+#             */
/*   Updated: 2022/12/06 14:36:38 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *) b;
	i = 0;
	while (i < len)
	{
		str[i] = (unsigned char) c;
		i++;
	}
	return (b);
}

/*
#include<stdio.h>

int	main(int argc, char **argv)
{
	char	cb[50];
	char	c;
	
	(void) argc;
	c = argv[1][0];
	ft_memset(cb, c, 10);
	printf ("%s", cb);
}
*/