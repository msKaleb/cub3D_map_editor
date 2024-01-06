/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 14:18:31 by msoria-j          #+#    #+#             */
/*   Updated: 2022/12/06 14:33:46 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha (c) != 0 || ft_isdigit (c) != 0)
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
	printf("%d", ft_isalnum(c));
}
*/