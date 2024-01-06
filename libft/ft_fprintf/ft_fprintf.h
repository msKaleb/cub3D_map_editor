/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:28:56 by msoria-j          #+#    #+#             */
/*   Updated: 2023/04/13 18:47:29 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FPRINTF_H
# define FT_FPRINTF_H

# include<stdarg.h>
# include<unistd.h>
# include"../libft.h"

char	*change_base(unsigned long long nbr, char base);
char	*ft_itoa_u(unsigned int n);
int		print_char(int fd, char c);
int		print_str(int fd, char *s);
int		print_hex(int fd, unsigned int p, char format);
int		print_uint(int fd, unsigned int u);
int		print_int(int fd, int d, char arg);
int		ft_fprintf(int fd, char const *format, ...);

#endif