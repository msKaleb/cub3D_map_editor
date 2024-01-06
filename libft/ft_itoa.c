/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:07:27 by msoria-j          #+#    #+#             */
/*   Updated: 2022/12/06 14:35:24 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	count_digits(int n)
{
	unsigned int	number;
	int				digits;

	digits = 1;
	number = (unsigned int)n;
	if (n < 0)
	{
		number = number * -1;
		digits++;
	}
	while (number / 10 > 0)
	{
		number /= 10;
		digits++;
	}
	return (digits);
}

char	*ft_itoa(int n)
{
	unsigned int	number;
	int				digits;
	int				neg;
	char			*str;

	neg = 0;
	digits = count_digits(n);
	str = ft_calloc(1, digits + 1);
	number = (unsigned int) n;
	if (n < 0)
	{
		number = number * -1;
		neg = 1;
	}
	if (!str)
		return (NULL);
	while (digits--)
	{
		str[digits] = (number % 10) + '0';
		number /= 10;
	}
	if (neg == 1)
		str[0] = '-';
	return (str);
}

/*
#include<stdio.h>

int	main(void)
{
	char	*str;

	str = ft_itoa(2147483647);
	printf("Number: %s\n", str);
}
*/