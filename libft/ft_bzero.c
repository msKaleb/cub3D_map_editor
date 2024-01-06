/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:51:48 by msoria-j          #+#    #+#             */
/*   Updated: 2022/12/06 14:33:31 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

/*
int	main(int argc, char **argv)
{
	char 	b[50];
	size_t	l;
	
	(void) argc;
	l = argv[1][0] - '0';
	ft_bzero(b, l);
	printf ("%s", b);
}
*/