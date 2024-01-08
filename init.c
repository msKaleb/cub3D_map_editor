/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 20:49:26 by msoria-j          #+#    #+#             */
/*   Updated: 2024/01/08 12:38:39 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub_editor.h"

t_grid	init_grid(int x, int y)
{
	t_grid	grid;

	grid.size_x = x;
	grid.size_y = y;
	grid.step_x = (SCREEN_WIDTH - MARGIN * 2) / grid.size_x;
	grid.step_y = (SCREEN_HEIGHT - MARGIN * 2) / grid.size_y;
	grid.end_x = (SCREEN_WIDTH - MARGIN);
	grid.end_y = (SCREEN_HEIGHT - MARGIN);
	return (grid);
}

char	**create_map(int rows, int cols)
{
	char	**map;

	map = ft_calloc(sizeof(char *), rows + 1);
	for (int i = 0; i < rows; i++) {
		map[i] = ft_calloc(1, cols + 1);
		ft_memset(map[i], ' ', cols);	
	}
	map[rows] = NULL;
	return (map);
}

t_img	create_banner(t_mlx *m)
{
	t_img	banner;
	void	*banner_ptr;
	int		offset;

	banner.img = mlx_new_image(m->mlx, SCREEN_WIDTH, BANNER);
	banner.addr = mlx_get_data_addr \
		(banner.img, &banner.bpp, &banner.sl, &banner.endian);
	for (int y = 0; y < BANNER - 2; y++)
	{
		for (int x = 0; x < SCREEN_WIDTH; x++)
		{
			offset = (y * banner.sl) + (x * (banner.bpp / 8));
			banner_ptr = banner.addr + offset;
			*(unsigned int *)banner_ptr = mlx_get_color_value(m->mlx, COLOR_BANNER);
		}
	}
	return (banner);
}

void	init_map_data(t_mlx *m, t_point *p)
{
	m->map = create_map(p->y, p->x);
	m->grid = init_grid(p->x, p->y);
	for (int i = 0; i < MAX_SQUARES; i++)
		m->squares[i] = init_square_img(m, i);
	m->banner = create_banner(m);
}
