/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_var.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j < msoria-j@student.42urduliz.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:59:36 by msoria-j          #+#    #+#             */
/*   Updated: 2023/03/31 14:42:42 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_fprintf.h"

int	print_char(int fd, char c)
{
	write(fd, &c, 1);
	return (0);
}

int	print_str(int fd, char *s)
{
	if (!s)
		return (write(fd, "(null)", 6) - 1);
	return (write(fd, s, ft_strlen(s)) - 1);
}

int	print_hex(int fd, unsigned int p, char format)
{
	char	*s;
	int		ret;

	ret = 0;
	if (p == 0)
		return (write(fd, "0", 1) - 1);
	s = change_base((unsigned long long)p, format);
	ret = write(fd, s, ft_strlen(s));
	free(s);
	return (ret - 1);
}

int	print_uint(int fd, unsigned int u)
{
	char	*s;
	int		ret;

	s = ft_itoa_u(u);
	ret = write(fd, s, ft_strlen(s));
	free(s);
	return (ret - 1);
}

int	print_int(int fd, int d, char arg)
{
	char	*s;
	int		ret;

	if (arg == 'c')
	{
		print_char(fd, d);
		return (0);
	}
	s = ft_itoa(d);
	ret = write(fd, s, ft_strlen(s));
	free(s);
	return (ret - 1);
}
