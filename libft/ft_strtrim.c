/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:43:45 by msoria-j          #+#    #+#             */
/*   Updated: 2022/12/07 17:10:17 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	in_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		index;
	char	*str;

	i = 0;
	j = ft_strlen(s1) - 1;
	while (in_set(s1[i], set) == 1)
		i++;
	while (in_set(s1[j], set) == 1)
		j--;
	if ((j - i) > 0)
		str = (char *) ft_calloc(1, (j - i) + 2);
	else
		str = (char *) ft_calloc(1, 1);
	if (!str)
		return (NULL);
	index = 0;
	while (i <= j)
		str[index++] = s1[i++];
	str[index] = '\0';
	return (str);
}

/*
#include<stdio.h>
#include<string.h>

int	main(void)
{
	char	s1[] = "abcdba";
	char	set[] = "acb";
	char	*str;

	str = ft_strtrim(s1, set);
	printf ("%d\n", strcmp(str, "d"));
	printf ("%s\n", str);
	free (str);
}
*/