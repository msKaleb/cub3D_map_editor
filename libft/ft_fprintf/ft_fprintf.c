/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:32:26 by msoria-j          #+#    #+#             */
/*   Updated: 2023/04/13 18:48:43 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_fprintf.h"

static int	print_adr(int fd, unsigned long long p)
{
	char	*s;
	int		ret;

	s = change_base(p, 'p');
	write(fd, "0x", 2);
	ret = write(fd, s, ft_strlen(s)) + 1;
	free(s);
	return (ret);
}

static int	choose_format(int fd, va_list ap, char format)
{
	int	ret;

	ret = 0;
	if (format == '%')
		write(fd, "%%", 1);
	if (format == 'd' || format == 'i' || format == 'c')
		ret += print_int(fd, va_arg(ap, int), format);
	if (format == 's')
		ret += print_str(fd, va_arg(ap, char *));
	if (format == 'x' || format == 'X')
		ret += print_hex(fd, va_arg(ap, unsigned int), format);
	if (format == 'p')
		ret += print_adr(fd, va_arg(ap, unsigned long long));
	if (format == 'u')
		ret += print_uint(fd, va_arg(ap, unsigned int));
	return (ret);
}

int	ft_fprintf(int fd, char const *format, ...)
{
	va_list			ap;
	int				ret;

	ret = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format != '%')
			write(fd, (unsigned char *)format, 1);
		if (*format == '%')
		{
			format++;
			ret += choose_format(fd, ap, *format);
		}
		format++;
		ret++;
	}
	va_end(ap);
	return (ret);
}
