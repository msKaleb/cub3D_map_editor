/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 20:49:26 by msoria-j          #+#    #+#             */
/*   Updated: 2024/01/11 10:11:38 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub_editor.h"

t_grid	init_grid(int x, int y)
{
	t_grid	grid;

	grid.size_x = x;
	grid.size_y = y;
	grid.step_x = round((SCREEN_WIDTH - MARGIN * 2) / grid.size_x);
	grid.step_y = round((SCREEN_HEIGHT - MARGIN * 2) / grid.size_y);
	grid.end_x = (SCREEN_WIDTH - MARGIN);
	grid.end_y = (SCREEN_HEIGHT - MARGIN);
	grid.end_x = grid.step_x * grid.size_x;
	grid.end_y = grid.step_y * grid.size_y;
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

	banner.img = mlx_new_image(m->mlx, m->grid.end_x, BANNER);
	banner.addr = mlx_get_data_addr \
		(banner.img, &banner.bpp, &banner.sl, &banner.endian);
	banner.bpp_div = banner.bpp / 8;
	for (int y = 0; y < BANNER - 2; y++)
	{
		for (int x = 0; x < m->grid.end_x; x++)
		{
			offset = (y * banner.sl) + (x * (banner.bpp_div));
			banner_ptr = banner.addr + offset;
			*(unsigned int *)banner_ptr = mlx_get_color_value(m->mlx, COLOR_BANNER);
		}
	}
	return (banner);
}

void	init_map_data(t_mlx *m, t_point *p)
{
	m->map = create_map(p->y, p->x);
	// m->grid = init_grid(p->x, p->y);
	for (int i = 0; i < MAX_SQUARES; i++)
		m->squares[i] = init_square_img(m, i);
	m->banner = create_banner(m);
}
