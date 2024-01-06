/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 08:28:03 by msoria-j          #+#    #+#             */
/*   Updated: 2024/01/06 14:52:54 by msoria-j         ###   ########.fr       */
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
		ft_memset(map[i], 32, cols);	
	}
	map[rows] = NULL;
	return (map);
}

int	test(int x, int y, t_mlx *m)
{
	int	gx = (x - MARGIN) / m->grid.step_x;
	int	gy = (y - MARGIN) / m->grid.step_y;

	if ((x < MARGIN || y < MARGIN)
		|| (x > SCREEN_WIDTH - MARGIN || y > SCREEN_HEIGHT - MARGIN))
		return 1;
	/* if (button == 1)
		m->map[gy][gx] = '1';
	else if (button == 3)
		m->map[gy][gx] = '0';
	else if (button == 2)
		m->map[gy][gx] = ' '; */
	/* for (int i = 0; i < m->grid.size_y; i++)
		printf("%s\n", m->map[i]); */
		
	// ft_fprintf(1, "button: %d - x: %d - y: %d\n", button, gx, gy);
	(void)m;
	if (m->painting == 1)
		ft_fprintf(1, "x: %d - y: %d\n", gx, gy);
		// ft_fprintf(1, "x: %d - y: %d\n", x, y);
	return 0;
}

int	set_painting(int key_code, t_mlx *m)
{
	if (key_code == XK_ESCAPE)
		close_mlx(m);
	if (key_code == XK_W)
		m->painting = 1;
	render_frame(m);
	return (0);
}

int	release_painting(int key_code, t_mlx *m)
{
	if (key_code == XK_W)
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

	for (int i = 0; i < y; i++)
		printf("%s\n", m.map[i]);

	render_grid(&m, m.grid);
	mlx_put_image_to_window(m.mlx, m.win, m.img, 0, 0);
	// mlx_string_put(m.mlx, m.win, 20, 20, 0x00, argv[1]);
	// mlx_key_hook(m.win, key_hook, &m);
	// mlx_mouse_hook(m.win, mouse_hook, &m);
	mlx_hook(m.win, ON_KEYDOWN, (1L<<0), &set_painting, &m);
	mlx_hook(m.win, ON_KEYUP, (1L<<1), &release_painting, &m);
	mlx_hook(m.win, 6, (1L<<6), &test, &m);
	// mlx_hook(m.win, ON_KEYDOWN, (1L<<0), &key_hook, &m);
	mlx_hook(m.win, ON_DESTROY, X_MASK, &close_mlx, &m);
	// mlx_loop_hook(m.mlx, &render_frame, &m);
	mlx_loop(m.mlx);
	
	return(0);
}
