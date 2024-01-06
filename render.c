/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 08:33:40 by msoria-j          #+#    #+#             */
/*   Updated: 2024/01/06 11:20:44 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub_editor.h"

/*
*In order to know where to put the vertex, we calculate the offset
*using the values filled by the 'mlx_get_data_addr()' function:
*bits per pixel, size of line, and the endian value, then we use the formula
*'y * size_line + x * (bits_per_pixel / 8)' to change the atributes
*of a specific vertex (or pixel).
*/
void	print_pixel(t_mlx *m, t_point p, int color)
{
	char	*ptr;
	int		offset;

	if (p.x < 0 || p.y < 0)
		return ;
	if (p.x > SCREEN_WIDTH || p.y > SCREEN_HEIGHT)
		return ;
	offset = (p.y * m->sl) + (p.x * (m->bpp / 8));
	ptr = m->addr + offset;
	*(unsigned int *)ptr = mlx_get_color_value(m->mlx, color);
}

int	render_frame(t_mlx *m)
{
	mlx_destroy_image(m->mlx, m->img);
	m->img = mlx_new_image(m->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	// do your stuff
	mlx_put_image_to_window(m->mlx, m->win, m->img, 0, 0);
	return (0);
}

void	render_grid(t_mlx *m)
{
	// horizontal lines
	for (int x = m->step_x; x < m->end_x; x++)
		for (int y = m->step_y; y <= m->end_y; y += m->step_y)
			if (x % 2 == 0 && y % 2 == 0)
				print_pixel(m, (t_point){x, y}, COLOR_GRID);
	// vertical lines
	for (int x = m->step_x; x <= m->end_x; x += m->step_x)
		for (int y = m->step_y; y < m->end_y; y++)
			if (x % 2 == 0 && y % 2 == 0)
				print_pixel(m, (t_point){x, y}, COLOR_GRID);
}
