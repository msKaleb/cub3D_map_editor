/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:35:25 by msoria-j          #+#    #+#             */
/*   Updated: 2022/12/06 14:36:46 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_putchar_fd(char c, int fd)
{
	ssize_t	wr;

	wr = write (fd, &c, 1);
	if (wr != 1)
		write (2, "Error.\n", 7);
}

/*
#include<fcntl.h>
#include<stdio.h>

int	main(void)
{
	char	str[] = "The open() system call opens the file specified by pathname.";
	int	fd;
	int	i;

	i = 0;
	fd = open("file.txt", O_WRONLY | O_APPEND);
	if (!fd)
		write(2, "Couldn't load file\n", 19);
	while (str[i])
	{
		ft_putchar_fd(str[i], fd);
		i++;
	}
	close(fd);
}
*/