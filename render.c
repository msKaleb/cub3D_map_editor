/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 08:33:40 by msoria-j          #+#    #+#             */
/*   Updated: 2024/01/15 14:42:10 by msoria-j         ###   ########.fr       */
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
	if (p.x > m->grid.end_x || p.y > m->grid.end_x + BANNER)
		return ;
	offset = (p.y * m->sl) + (p.x * (m->bpp_div));
	ptr = m->addr + offset;
	*(unsigned int *)ptr = mlx_get_color_value(m->mlx, color);
}

void	print_direction(t_mlx *m, t_point p, char c)
{
	char	*orientation = "Currently heading ";

	switch (c)
	{
	case 'N':
		orientation = ft_strjoin(orientation, "North");
		break;
	case 'S':
		orientation = ft_strjoin(orientation, "South");
		break;
	case 'W':
		orientation = ft_strjoin(orientation, "West");
		break;
	case 'E':
		orientation = ft_strjoin(orientation, "East");
		break;
	
	default:
		break;
	}
	mlx_put_image_to_window(m->mlx, m->win, m->squares[S_PLAYER].img, p.x + 1, p.y + BANNER + 1);
	mlx_string_put(m->mlx, m->win, 20, BANNER - 5, COLOR_STRING, orientation);
	free(orientation);
}

/**
 * @brief put the appropiate tile on place
  */
void	print_square(t_mlx *m, int gx, int gy, char c)
{
	t_point	p;
	
	if (c == ' ')
		return ;

	p.x = gx * m->grid.step_x + MARGIN;
	p.y = gy * m->grid.step_y + MARGIN;
	
	if (ft_strchr("NSEW", c))
		print_direction(m, p, c);
	else
		mlx_put_image_to_window(m->mlx, m->win, m->squares[c - '0'].img, p.x + 1, p.y + BANNER + 1);
}

// key press events
int	set_painting(int key_code, t_mlx *m)
{
	if (key_code == XK_ESCAPE)
		close_mlx(m);
	else if (key_code == XK_R)
		m->painting = P_SPACE;
	return (0);
}

// key release events
int	release_painting(int key_code, t_mlx *m)
{
	char	*saved_text;

	if (key_code == XK_F)
		m->painting = P_FLOOD;
	else if (key_code == XK_E)
		m->painting = P_DOOR;
	else if (key_code == XK_W)	// place the character N
		m->painting = P_NORTH;
	else if (key_code == XK_S)	// place the character S
		m->painting = P_SOUTH;
	else if (key_code == XK_A)	// place the character W
		m->painting = P_WEST;
	else if (key_code == XK_D)	// place the character E
		m->painting = P_EAST;
	else if (key_code == XK_Q) {
		m->fd = open(m->argv, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (m->fd < 0)
			exit(err_file(m->argv));
		print_map(m->map, m->fd);
		saved_text = ft_strjoin("Map saved to ", m->argv);
		mlx_string_put(m->mlx, m->win, m->grid.end_x - (m->grid.end_x / 3), \
			BANNER - 5, COLOR_STRING, saved_text);
		free(saved_text);
	}
	render_loop(m->cur.x, m->cur.y, m);
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
	mlx_destroy_image(m->mlx, m->img); // main image of the whole map
	m->img = mlx_new_image(m->mlx, m->grid.end_x, m->grid.end_x); // recycle the main image
	render_grid(m, m->grid);
	mlx_put_image_to_window(m->mlx, m->win, m->img, 0, BANNER); // put the main image
	mlx_put_image_to_window(m->mlx, m->win, m->banner.img, 0, 0); // put the banner
	render_map(m, m->grid, m->map);
	return (0);
}

void	render_grid(t_mlx *m, t_grid grid)
{
	// horizontal lines
	for (int x = MARGIN; x < grid.end_x; x++) {
		for (int y = MARGIN; y < grid.end_y; y += grid.step_y) {
			print_pixel(m, (t_point){x, y}, COLOR_GRID);
			if ((y + grid.step_y) >= (grid.end_y))
				print_pixel(m, (t_point){x, m->grid.end_x - 1}, COLOR_GRID);
		}
	}
	// vertical lines
	for (int x = MARGIN; x < grid.end_x; x += grid.step_x) {
		for (int y = MARGIN; y < grid.end_y; y++) {			
			print_pixel(m, (t_point){x, y}, COLOR_GRID);
			if ((x + grid.step_x) >= (grid.end_x))
				print_pixel(m, (t_point){m->grid.end_x - 1, y}, COLOR_GRID);
		}
	}
}

char	place_player(char **map, int index)
{
	char	player[4] = {'N', 'S', 'W', 'E'};
	char	*ptr;
	int		i = 0;

	// check if there is already a player and,
	// if so, delete it and put it in the new place
	while (map[i])
	{
		for (int j = 0; j < 4; j++)
			if ((ptr = ft_strchr(map[i], player[j])))
			{
				*ptr = '0'; // store the previous square type?
				break ;
			}
		i++;
	}
	// codes for player range from 5 to 8
	return (player[index - P_NORTH]);
}

int	render_loop(int x, int y, t_mlx *m)
{
	int	gx;
	int	gy;

	m->cur.x = x;
	m->cur.y = y;
	if (m->painting == P_NONE || (x < MARGIN || y < BANNER - MARGIN)
		|| (x > m->grid.end_x - MARGIN || y > m->grid.end_x + BANNER - MARGIN))
		return 1;

	gx = (x - MARGIN) / m->grid.step_x;
	gy = (y - MARGIN - BANNER) / m->grid.step_y;

	if (gx >= m->grid.size_x)
		gx = m->grid.size_x - 1;
	if (gy >= m->grid.size_y)
		gy = m->grid.size_y - 1;

	if (m->painting == P_WALL)
		m->map[gy][gx] = '1';
	else if (m->painting == P_GROUND)
		m->map[gy][gx] = '0';
	else if (m->painting == P_DOOR)
		m->map[gy][gx] = '2';
	else if (m->painting == P_SPACE)
		m->map[gy][gx] = ' ';
	else if (m->painting == P_FLOOD && m->map[gy][gx] != '0')
		flood_fill(m->map, (t_point){m->grid.size_x, m->grid.size_x}, (t_point){gx, gy});
	else if (m->painting >= P_NORTH && m->painting <= P_EAST)
		m->map[gy][gx] = place_player(m->map, m->painting);
	// reset painting mode
	if (m->painting >= P_FLOOD && m->painting <= P_SPACE)
		m->painting = P_NONE;
	// printf("painting mode: %d\n", m->painting); // debugging
	render_frame(m);
	return 0;
}
