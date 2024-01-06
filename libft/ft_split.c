/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:19:07 by msoria-j          #+#    #+#             */
/*   Updated: 2022/12/12 13:12:17 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	count_words(char const *s, char c)
{
	int		strnumber;
	int		isstr;

	isstr = 0;
	strnumber = 0;
	while (*s)
	{
		if (*s != c && isstr == 0)
		{
			strnumber++;
			isstr = 1;
		}
		if (*s == c)
			isstr = 0;
		s++;
	}
	return (strnumber);
}

static int	find_index(char const *s, char c)
{
	int	index;

	index = 0;
	while (s[index] != c && s[index])
		index++;
	return (index);
}

char	**ft_split(char const *s, char c)
{
	char	**strarray;
	int		i;

	strarray = (char **)malloc ((count_words(s, c) + 1) * sizeof(char *));
	if (!strarray)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			strarray[i] = ft_substr(s, 0, find_index(s, c));
			i++;
			s += find_index(s, c);
		}
	}
	strarray[i] = NULL;
	return (strarray);
}

/*char	**ft_split(char const *s, char c)
{
	char	**strarray;
	char	*str;
	int		i;

	str = (char *)s;
	strarray = (char **)malloc ((count_words(s, c) + 1) * sizeof(char *));
	if (!strarray)
		return (NULL);
	i = 0;
	while (i < count_words(s, c))
	{
		if (find_index(str, c) < 1)
			str++;
		else
		{
			strarray[i] = ft_calloc(1, find_index(str, c) + 2);
			ft_strlcpy(strarray[i], str, find_index(str, c) + 1);
			str = ft_strchr(str, c);
			i++;
		}
	}
	return (strarray);
}*/

/*
#include<stdio.h>

int	main(void)
{
	char	s[] = "0x000102fe1787 is located 57 bytes to the left";
	char	**strarray;
	int		i;
	int		words;
	char	c;

	c = ' ';
	i = 0;
	words = count_words((char *)s, c);
	printf("words: %d\n-----------\n", words);
	strarray = ft_split (s, c);
	while (i <= words)
	{
		printf ("array[%d]: %s\n", i, strarray[i]);
		free(strarray[i]);
		i++;
	}
	free(strarray);
}
*/