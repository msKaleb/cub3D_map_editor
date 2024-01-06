/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 08:31:43 by msoria-j          #+#    #+#             */
/*   Updated: 2024/01/06 11:55:35 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub_editor.h"

int	close_mlx(t_mlx *m)
{
	// free_map(map);
	mlx_destroy_window(m->mlx, m->win);
	free(m->mlx);
	exit(EXIT_SUCCESS);
}

int	key_hook(int key_code, t_mlx *m)
{
	if (key_code == XK_ESCAPE)
		close_mlx(m);
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
}
