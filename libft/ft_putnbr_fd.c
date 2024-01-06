/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:31:55 by msoria-j          #+#    #+#             */
/*   Updated: 2022/12/06 16:32:35 by msoria-j         ###   ########.fr       */
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

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	number;
	int				digits;
	int				neg;
	char			str[13];

	neg = 0;
	ft_bzero(str, 13);
	digits = count_digits(n);
	number = (unsigned int) n;
	if (n < 0)
	{
		number = number * -1;
		neg = 1;
	}
	while (digits--)
	{
		str[digits] = (number % 10) + '0';
		number /= 10;
	}
	if (neg == 1)
		str[0] = '-';
	ft_putstr_fd(str, fd);
}

/*
#include<fcntl.h>
#include<stdio.h>

int	main(void)
{
	int		fd;

	fd = open("file.txt", O_WRONLY | O_APPEND);
	if (!fd)
		write(2, "Couldn't load file\n", 19);
	ft_putnbr_fd(-2147483648, fd);
	close(fd);	
}
*/