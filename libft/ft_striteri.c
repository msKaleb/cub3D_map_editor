/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:26:19 by msoria-j          #+#    #+#             */
/*   Updated: 2022/12/11 15:48:39 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

/*void	myfunc(unsigned int n, char *c)
{
	char	cc;

	n = 0;
	cc = *c;
}*/

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}

/*
#include<stdio.h>

int	main(void)
{
	char	str[] = "La función a aplicar sobre cada carácter.";

	ft_striteri(str, myfunc);
}
*/