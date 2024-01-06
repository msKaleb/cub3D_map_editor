/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 08:33:40 by msoria-j          #+#    #+#             */
/*   Updated: 2024/01/07 00:16:50 by msoria-j         ###   ########.fr       */
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

void	print_square(t_mlx *m, int gx, int gy, char c)
{
	int	x = gx * m->grid.step_x + MARGIN;
	int	y = gy * m->grid.step_y + MARGIN;
	
	if (c == '1')
		mlx_put_image_to_window(m->mlx, m->win, m->wall.img, x + 1, y + 1);
	if (c == '0')
		mlx_put_image_to_window(m->mlx, m->win, m->floor.img, x + 1, y + 1);
}

int	set_painting(int key_code, t_mlx *m)
{
	if (key_code == XK_ESCAPE)
		close_mlx(m);
	if (key_code == XK_W)
		m->painting = 1;
	else if (key_code == XK_S)
		m->painting = 2;
	else if (key_code == XK_Q) {
		m->fd = open(m->argv, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		print_map(m->map, m->fd);
	}
	return (0);
}

int	release_painting(int key_code, t_mlx *m)
{
	if (key_code == XK_W || key_code == XK_S)
		m->painting = 0;
	else if (key_code == XK_F)
		m->painting = 3;
	else if (key_code == XK_UP) // place the character N
		m->painting = 4;
	else if (key_code == XK_DOWN) // place the character S
		m->painting = 5;
	else if (key_code == XK_LEFT) // place the character W
		m->painting = 6;
	else if (key_code == XK_RIGHT) // place the character E
		m->painting = 7;
	return (0);
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
	render_grid(m, m->grid);
	mlx_put_image_to_window(m->mlx, m->win, m->img, 0, 0);
	render_map(m, m->grid, m->map);
	return (0);
}

void	render_grid(t_mlx *m, t_grid grid)
{
	// horizontal lines
	for (int x = MARGIN; x < grid.end_x; x++) {
		for (int y = MARGIN; y <= grid.end_y; y += grid.step_y) {
			if (y == SCREEN_HEIGHT)
				y--;
			// ft_fprintf(1, "%d %d\n", x, y);
			print_pixel(m, (t_point){x, y}, COLOR_GRID);
		}
	}
	// vertical lines
	for (int x = MARGIN; x <= grid.end_x; x += grid.step_x) {
		for (int y = MARGIN; y < grid.end_y; y++) {
			if (x == SCREEN_HEIGHT)
				x--;			
			print_pixel(m, (t_point){x, y}, COLOR_GRID);
		}
	}
}

int	render_loop(int x, int y, t_mlx *m)
{
	int	gx = (x - MARGIN) / m->grid.step_x;
	int	gy = (y - MARGIN) / m->grid.step_y;

	if (m->painting == 0) return 1;
	if (gx >= m->grid.size_x)
		gx = m->grid.size_x - 1;
	if (gy >= m->grid.size_y)
		gy = m->grid.size_y - 1;
	if ((x < MARGIN || y < MARGIN)
		|| (x > SCREEN_WIDTH - MARGIN || y > SCREEN_HEIGHT - MARGIN))
		return 1;
	(void)m;
	if (m->painting == 1)
		m->map[gy][gx] = '1';
	else if (m->painting == 2)
		m->map[gy][gx] = '0';
	else if (m->painting == 3 && m->map[gy][gx] != '0')
		flood_fill(m->map, (t_point){m->grid.size_x, m->grid.size_x}, (t_point){gx, gy});
	else if (m->painting == 4)
		m->map[gy][gx] = 'N'; // function to check if there is already a character
	if (m->painting == 3)
		m->painting = 0;
	render_frame(m);
	return 0;
}
