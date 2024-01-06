/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:01:18 by msoria-j          #+#    #+#             */
/*   Updated: 2022/12/06 14:34:24 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (c);
	else
		return (0);
}

/*
#include<stdio.h>

int	main(int argc, char **argv)
{
	char	c;

	(void) argc;
	c = argv[1][0];
	printf("%d", ft_isprint(c));
}
*/