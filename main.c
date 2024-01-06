/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 08:28:03 by msoria-j          #+#    #+#             */
/*   Updated: 2024/01/07 00:13:06 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub_editor.h"

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
	m.argv = argv[1];
	m.map = create_map(y, x);
	m.grid = init_grid(x, y);
	m.wall = init_wall_img(&m);
	m.floor = init_floor_img(&m);
	render_grid(&m, m.grid);
	mlx_put_image_to_window(m.mlx, m.win, m.img, 0, 0);
	mlx_mouse_hook(m.win, mouse_hook, &m);
	mlx_hook(m.win, ON_KEYDOWN, X_KEYPRESS, &set_painting, &m);
	mlx_hook(m.win, ON_KEYUP, X_KEYRELEASE, &release_painting, &m);
	mlx_hook(m.win, ON_MOUSEMOVE, X_POINTERMOTION, &render_loop, &m);
	mlx_hook(m.win, ON_DESTROY, X_MASK, &close_mlx, &m);
	mlx_loop(m.mlx);
	return(0);
}
