/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 08:28:03 by msoria-j          #+#    #+#             */
/*   Updated: 2024/01/10 09:41:54 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub_editor.h"
#include "colors.h"

void	print_controls(void)
{
	ft_fprintf(1, "\nControls:\n");
	ft_fprintf(1, "\tLeft click: paint a single wall square\n");
	ft_fprintf(1, "\tRight click: paint a single floor square\n");
	ft_fprintf(1, "\tMiddle click: delete a single square\n\n");
	ft_fprintf(1, "\tHold W + move mouse: paint walls\n");
	ft_fprintf(1, "\tHold S + move mouse: paint floor\n");
	ft_fprintf(1, "\tHold D + move mouse: delete squares\n\n");
	ft_fprintf(1, "\tArrow Keys: place the player (N, S, W, E)\n\n");
	ft_fprintf(1, "\tF: Fill the area with floor squares\n");
	ft_fprintf(1, "\tQ: save map (with default colors for floor and ceiling and texture paths)\n");
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
	if (argc < 2 || ft_strcmp(argv[1], "--help") == 0)
		return (err_arg_number());
	if ( argc > 2 && argv[2])
		p.x = ft_atoi(argv[2]);
	p.y = p.x;
	/* if (argc > 3 && argv[3])
		p.y = ft_atoi(argv[3]); */

	print_controls();
	m.grid = init_grid(p.x, p.y);
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
