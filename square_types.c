/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_types.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 09:51:42 by msoria-j          #+#    #+#             */
/*   Updated: 2024/01/07 09:51:56 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub_editor.h"

t_wall	init_wall_img(t_mlx *m)
{
	t_wall	wall;
	void	*wall_ptr;
	int		offset;

	wall.img = mlx_new_image(m->mlx, m->grid.step_x, m->grid.step_y);
	wall.addr = mlx_get_data_addr
		(wall.img, &wall.bpp, &wall.sl, &wall.endian);
	for (int y = 0; y < m->grid.step_y - 2; y++)
	{
		for (int x = 0; x < m->grid.step_x - 2; x++)
		{
			offset = (y * wall.sl) + (x * (wall.bpp / 8));
			wall_ptr = wall.addr + offset;
			*(unsigned int *)wall_ptr = mlx_get_color_value(m->mlx, COLOR_WALL);
			// ft_fprintf(1, "x: %d - y: %d\n", i, j);
		}
	}
	return (wall);
}

t_floor	init_floor_img(t_mlx *m)
{
	t_floor	floor;
	void	*floor_ptr;
	int		offset;

	floor.img = mlx_new_image(m->mlx, m->grid.step_x, m->grid.step_y);
	floor.addr = mlx_get_data_addr
		(floor.img, &floor.bpp, &floor.sl, &floor.endian);
	for (int y = 0; y < m->grid.step_y - 2; y++)
	{
		for (int x = 0; x < m->grid.step_x - 2; x++)
		{
			offset = (y * floor.sl) + (x * (floor.bpp / 8));
			floor_ptr = floor.addr + offset;
			*(unsigned int *)floor_ptr = mlx_get_color_value(m->mlx, COLOR_FLOOR);
			// ft_fprintf(1, "x: %d - y: %d\n", i, j);
		}
	}
	return (floor);
}