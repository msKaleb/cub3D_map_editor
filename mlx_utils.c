/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 08:31:43 by msoria-j          #+#    #+#             */
/*   Updated: 2024/01/06 14:50:37 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub_editor.h"

int	close_mlx(t_mlx *m)
{
	free_map(m->map);
	mlx_destroy_window(m->mlx, m->win);
	free(m->mlx);
	exit(EXIT_SUCCESS);
}

int	key_hook(int key_code, t_mlx *m)
{
	if (key_code == XK_ESCAPE)
		close_mlx(m);
	if (key_code == XK_W)
		m->painting = 1;
	/* if (has_to_move(key_code))
	{
		// mlx_destroy_image(m->mlx, m->img);
		// m->img = mlx_new_image(m->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
		set_motion(key_code, m);
		// raycast(&m->ray, &m->player, m);
		// mlx_put_image_to_window(m->mlx, m->win, m->img, 0, 0);
	} */
	return (0);
}



/**
 * @todo check leaks on exit()
  */
void	init_mlx(t_mlx *m)
{
	m->mlx = mlx_init();
	if (m->mlx == NULL)
		exit (err_mlx());
	m->win = mlx_new_window(m->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, \
		"cub3D Map Editor by msoria-j");
	if (m->win == NULL)
		exit(err_mlx());
	m->img = mlx_new_image(m->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (m->img == NULL)
		exit(err_mlx());
	m->addr = mlx_get_data_addr(m->img, &m->bpp, &m->sl, &m->endian);
	m->painting = 0;
}

int	mouse_hook(int button, int x, int y, t_mlx *m)
{
	int	gx = (x - MARGIN) / m->grid.step_x;
	int	gy = (y - MARGIN) / m->grid.step_y;

	if ((x < MARGIN || y < MARGIN)
		|| (x > SCREEN_WIDTH - MARGIN || y > SCREEN_HEIGHT - MARGIN))
		return 1;
	(void)button;
	if (button == 1)
		m->map[gy][gx] = '1';
	else if (button == 3)
		m->map[gy][gx] = '0';
	else if (button == 2)
		m->map[gy][gx] = ' ';
	for (int i = 0; i < m->grid.size_y; i++)
		printf("%s\n", m->map[i]);
		
	// ft_fprintf(1, "button: %d - x: %d - y: %d\n", button, gx, gy);
	render_frame(m);
	return 0;
}
