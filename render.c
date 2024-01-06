/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 08:33:40 by msoria-j          #+#    #+#             */
/*   Updated: 2024/01/06 17:05:24 by msoria-j         ###   ########.fr       */
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
	// m->addr[offset] = mlx_get_color_value(m->mlx, color);
}

void	print_square(t_mlx *m, int gx, int gy, char c)
{
	int	x = gx * m->grid.step_x + MARGIN;
	int	y = gy * m->grid.step_y + MARGIN;
	int	color;
(void)x, (void)y;
	if (c == ' ')
		return ;
	if (c == '1')
		color = COLOR_WALL;
	else if (c == '0')
		color = COLOR_FLOOR;
	/* for (int i = y; i < m->grid.step_y; i++)
		for (int j = x; j < m->grid.step_x; j++)
			print_pixel(m, (t_point){x, y}, color); */
	ft_fprintf(1, "color: %d - x: %d - y: %d\n", color, x, y);
	
}

void	render_map(t_mlx *m, t_grid grid, char **map)
{
	for (int y = 0; y < grid.size_y; y++)
		for (int x = 0; x < grid.size_x; x++)
			print_square(m, x, y, map[y][x]);

}

int	render_frame(t_mlx *m)
{
	mlx_destroy_image(m->mlx, m->img);
	m->img = mlx_new_image(m->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	// do your stuff
	render_map(m, m->grid, m->map);
	render_grid(m, m->grid);
	mlx_put_image_to_window(m->mlx, m->win, m->img, 0, 0);
	return (0);
}

void	render_grid(t_mlx *m, t_grid grid)
{
	// horizontal lines
	for (int x = MARGIN; x < grid.end_x; x++)
		for (int y = MARGIN; y <= grid.end_y; y += grid.step_y)
			if (x % 2 == 0 && y % 2 == 0)
				print_pixel(m, (t_point){x, y}, COLOR_GRID);
	// vertical lines
	for (int x = MARGIN; x <= grid.end_x; x += grid.step_x)
		for (int y = MARGIN; y < grid.end_y; y++)
			if (x % 2 == 0 && y % 2 == 0)
				print_pixel(m, (t_point){x, y}, COLOR_GRID);
}
