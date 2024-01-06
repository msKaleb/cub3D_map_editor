/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 09:02:12 by msoria-j          #+#    #+#             */
/*   Updated: 2022/12/06 17:17:01 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

/*
#include<stdio.h>

int	main(void)
{
	int		i;
	char	c;

	i = 96;
	c = 'a';
	while (c <= 'z')
	{
		printf("%c", ft_toupper(c));
		c++;
	}
}
*/