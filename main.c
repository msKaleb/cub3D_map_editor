/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 08:28:03 by msoria-j          #+#    #+#             */
/*   Updated: 2024/01/06 09:54:27 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub_editor.h"

void	render_test(t_mlx *m)
{
	for (int i = SCREEN_WIDTH / 3; i < SCREEN_WIDTH - (SCREEN_WIDTH / 3); i++)
		for (int j = SCREEN_HEIGHT / 3; j < SCREEN_HEIGHT - (SCREEN_HEIGHT / 3); j++)
			print_pixel(m, (t_point){i,j}, COLOR_WALL);
}

void	render_grid(t_mlx *m, int size_x, int size_y)
{
	int	step_x = SCREEN_WIDTH / size_x;
	int	step_y = SCREEN_HEIGHT / size_y;
	int	end_x = SCREEN_WIDTH - (SCREEN_WIDTH / size_x);
	int	end_y = SCREEN_HEIGHT - (SCREEN_HEIGHT / size_y);

	// horizontal lines
	for (int x = step_x; x < end_x; x++)
		for (int y = step_y; y <= end_y; y += step_y)
			print_pixel(m, (t_point){x, y}, COLOR_GRID);
	// vertical lines
	for (int x = step_x; x <= end_x; x += step_x)
		for (int y = step_y; y < end_y; y++)
			print_pixel(m, (t_point){x, y}, COLOR_GRID);
}

// color = (alpha << 24) + (red << 16) + (green << 8) + (blue);
int	main(int argc, char *argv[])
{
	t_mlx	m;
	int		x = 100;
	int		y = 100;
	(void) argv[1];

	if (argc < 2)
		return (err_arg_number());
	if ( argc > 2 && argv[2])
		x = ft_atoi(argv[2]);
	if (argc > 3 && argv[3])
		y = ft_atoi(argv[3]);
	init_mlx(&m);
	render_grid(&m, x, y);
	mlx_put_image_to_window(m.mlx, m.win, m.img, 0, 0);
	// mlx_string_put(m.mlx, m.win, 20, 20, 0x00, argv[1]);
	mlx_key_hook(m.win, key_hook, &m);
	/* mlx_hook(m.win, ON_KEYDOWN, (1L<<0), &set_motion, &m);
	mlx_hook(m.win, ON_KEYUP, (1L<<1), &release_motion, &m); */
	mlx_hook(m.win, ON_DESTROY, X_MASK, &close_mlx, &m);
	// mlx_loop_hook(m.mlx, &render_frame, &m);
	mlx_loop(m.mlx);
	
	return(0);
}
