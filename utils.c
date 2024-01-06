/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 08:41:50 by msoria-j          #+#    #+#             */
/*   Updated: 2024/01/07 00:18:36 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub_editor.h"

int	is_space(char c)
{
	if (c == ' ' || (c > 8 && c < 14))
		return (1);
	else
		return (0);
}

void	trim_non_ascii(char **tab, int rows)
{
	char	*tmp;
	int		i;
	int		j;
	int		k;

	i = -1;
	j = -1;
	k = 0;
	while (++i < rows)
	{
		tmp = ft_calloc(1, ft_strlen(tab[i]));
		while (++j < (int)ft_strlen(tab[i]))
		{
			if (!is_space(tab[i][j]))
				tmp[k++] = tab[i][j];
		}
		free(tab[i]);
		tab[i] = tmp;
		j = -1;
		k = 0;
	}
}

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = -1;
	while (map[++i])
	{
		free(map[i]);
		map[i] = NULL;
	}
	free(map);
	map = NULL;
}

void	print_map(char **map, int fd)
{
	int	i = -1;

	ft_fprintf(fd, "NO textures/test/north.xpm\n");
	ft_fprintf(fd, "SO textures/test/south.xpm\n");
	ft_fprintf(fd, "WE textures/test/west.xpm\n");
	ft_fprintf(fd, "EA textures/test/east.xpm\n\n");
	ft_fprintf(fd, "F 146,116,91\n");
	ft_fprintf(fd, "C 135,206,235\n\n");
	while (map[++i])
		ft_fprintf(fd, "%s\n", map[i]);
	ft_fprintf(fd, "\n");
	close(fd);
}


