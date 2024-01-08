/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 08:28:03 by msoria-j          #+#    #+#             */
/*   Updated: 2024/01/08 12:36:02 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub_editor.h"
#include "colors.h"

void	print_controls(void)
{
	ft_fprintf(1, "Left click: paint a wall\n");
	ft_fprintf(1, "Middle click: delete a square\n");
	ft_fprintf(1, "Right click: paint one ground square\n");
	ft_fprintf(1, "Hold W + move mouse: paint walls\n");
	ft_fprintf(1, "Hold S + move mouse: paint ground\n");
	ft_fprintf(1, "Hold D + move mouse: delete square\n");
	ft_fprintf(1, "Press F: ground flood fill\n");
	ft_fprintf(1, "Press Arrow Keys: place the player (N, S, W, E)\n");
	ft_fprintf(1, "Press Q: save map (with default colors and texture paths)\n");
}

// color = (alpha << 24) + (red << 16) + (green << 8) + (blue);
int	main(int argc, char *argv[])
{
	t_mlx	m;
	t_point	p;

	// default map size values
	p.x = 10;
	p.y = 10;

	// check arguments
	if (argc < 2)
		return (err_arg_number());
	if ( argc > 2 && argv[2])
		p.x = ft_atoi(argv[2]);
	if (argc > 3 && argv[3])
		p.y = ft_atoi(argv[3]);

	print_controls();
	init_mlx(&m, argv[1]);
	init_map_data(&m, &p);
	render_grid(&m, m.grid);
	mlx_put_image_to_window(m.mlx, m.win, m.img, 0, BANNER); // put the main image
	mlx_put_image_to_window(m.mlx, m.win, m.banner.img, 0, 0); // put the banner
	mlx_mouse_hook(m.win, mouse_hook, &m);
	mlx_hook(m.win, ON_KEYDOWN, X_KEYPRESS, &set_painting, &m);
	mlx_hook(m.win, ON_KEYUP, X_KEYRELEASE, &release_painting, &m);
	mlx_hook(m.win, ON_MOUSEMOVE, X_POINTERMOTION, &render_loop, &m);
	mlx_hook(m.win, ON_DESTROY, X_MASK, &close_mlx, &m);
	mlx_loop(m.mlx);
	return(0);
}
