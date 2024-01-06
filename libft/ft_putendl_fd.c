/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:27:08 by msoria-j          #+#    #+#             */
/*   Updated: 2022/12/06 14:36:53 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

/*
#include<fcntl.h>
#include<stdio.h>

int	main(void)
{
	char	str[] = "Envía la string 's' al file descriptor especificado.";
	int		fd;

	fd = open("file.txt", O_WRONLY | O_APPEND);
	if (!fd)
		write(2, "Couldn't load file\n", 19);
	ft_putendl_fd(str, fd);
	close(fd);	
}
*/