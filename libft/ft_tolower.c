/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 09:31:55 by msoria-j          #+#    #+#             */
/*   Updated: 2022/12/06 17:16:01 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

/*
#include<stdio.h>

int	main(void)
{
	int		i;
	char	c;

	i = 96;
	c = 'A';
	while (c <= 'Z')
	{
		printf("%c", ft_tolower(c));
		c++;
	}
}
*/