/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:23:30 by msoria-j          #+#    #+#             */
/*   Updated: 2022/12/06 15:44:16 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	ft_isspace(char c)
{
	if (c == ' ' || (c > 8 && c < 14))
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	while (ft_isspace(str[i]) != 0)
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || sign == -1)
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			res = (res * 10) + str[i] - '0';
		else
			break ;
		i++;
	}
	return (res * sign);
}

/*
#include<stdlib.h>
#include<stdio.h>

int	main(void)
{
	char str[]=" \t\v\n\r\f123";
	printf ("ft_atoi: %d\n", ft_atoi(str));
	printf ("sysatoi: %d\n", atoi(str));
}
*/