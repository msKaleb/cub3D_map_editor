/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 08:28:03 by msoria-j          #+#    #+#             */
/*   Updated: 2024/01/06 20:16:20 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub_editor.h"

void	print_map(char **map)
{
	int	i = -1;

	while (map[++i])
		printf("%s\n", map[i]);
	printf("\n");
}

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
		ft_memset(map[i], 64, cols);	
	}
	map[rows] = NULL;
	return (map);
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
	// ft_fprintf(1, "x: %d - y: %d\n", gx, gy);
	render_frame(m);
	// print_map(m->map);
	return 0;
}

int	set_painting(int key_code, t_mlx *m)
{
	if (key_code == XK_ESCAPE)
		close_mlx(m);
	if (key_code == XK_W)
		m->painting = 1;
	else if (key_code == XK_S)
		m->painting = 2;
	else if (key_code == XK_Q)
		print_map(m->map);
	// render_frame(m);
	return (0);
}

int	release_painting(int key_code, t_mlx *m)
{
	if (key_code == XK_W || key_code == XK_S)
		m->painting = 0;
	return (0);
}

// color = (alpha << 24) + (red << 16) + (green << 8) + (blue);
int	main(int argc, char *argv[])
{
	t_mlx	m;
	int		x = 10;
	int		y = 10;

	if (argc < 2)
		return (err_arg_number());
	if ( argc > 2 && argv[2])
		x = ft_atoi(argv[2]);
	if (argc > 3 && argv[3])
		y = ft_atoi(argv[3]);
	init_mlx(&m);
	m.map = create_map(y, x);
	m.grid = init_grid(x, y);
	m.wall = init_wall_img(&m);
	m.floor = init_floor_img(&m);
	// print_map(m.map);
	render_grid(&m, m.grid);
	mlx_put_image_to_window(m.mlx, m.win, m.img, 0, 0);
	// mlx_string_put(m.mlx, m.win, 20, 20, 0x00, argv[1]);
	// mlx_key_hook(m.win, key_hook, &m);
	mlx_mouse_hook(m.win, mouse_hook, &m);
	mlx_hook(m.win, ON_KEYDOWN, X_KEYPRESS, &set_painting, &m);
	mlx_hook(m.win, ON_KEYUP, X_KEYRELEASE, &release_painting, &m);
	mlx_hook(m.win, ON_MOUSEMOVE, X_POINTERMOTION, &render_loop, &m);
	mlx_hook(m.win, ON_DESTROY, X_MASK, &close_mlx, &m);
	// mlx_loop_hook(m.mlx, &render_frame, &m);
	mlx_loop(m.mlx);
	
	return(0);
}
