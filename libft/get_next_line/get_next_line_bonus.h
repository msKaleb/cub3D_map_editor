/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:29:31 by msoria-j          #+#    #+#             */
/*   Updated: 2023/04/13 13:44:19 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include<stdlib.h>
# include<unistd.h>
# include "../libft.h"

// int		ft_strlen(const char *s);
char	*gnl_strjoin(char *str1, char *str2);
char	*gnl_strchr(const char *s, int c);
char	*get_next_line(int fd);

#endif