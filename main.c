/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 08:28:03 by msoria-j          #+#    #+#             */
/*   Updated: 2024/01/06 11:21:56 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub_editor.h"

int	mouse_hook(int button, int x, int y, t_mlx *m)
{
	int	gx = m->step_x;
	int	gy = m->step_y;
	
	if ((x > gx && y > gy)
		&& (x < SCREEN_WIDTH - gx && y < SCREEN_HEIGHT - gy))
		ft_fprintf(1, "%d - %d - %d\n", button, (x / gx) - 1, (y / gy) - 1);
	return 0;
}

// color = (alpha << 24) + (red << 16) + (green << 8) + (blue);
int	main(int argc, char *argv[])
{
	t_mlx	m;

	if (argc < 2)
		return (err_arg_number());
	if ( argc > 2 && argv[2])
		m.size_x = ft_atoi(argv[2]);
	if (argc > 3 && argv[3])
		m.size_y = ft_atoi(argv[3]);
	init_mlx(&m);
	render_grid(&m);
	mlx_put_image_to_window(m.mlx, m.win, m.img, 0, 0);
	// mlx_string_put(m.mlx, m.win, 20, 20, 0x00, argv[1]);
	mlx_key_hook(m.win, key_hook, &m);
	mlx_mouse_hook(m.win, mouse_hook, &m);
	/* mlx_hook(m.win, ON_KEYDOWN, (1L<<0), &set_motion, &m);
	mlx_hook(m.win, ON_KEYUP, (1L<<1), &release_motion, &m); */
	mlx_hook(m.win, ON_DESTROY, X_MASK, &close_mlx, &m);
	// mlx_loop_hook(m.mlx, &render_frame, &m);
	mlx_loop(m.mlx);
	
	return(0);
}
