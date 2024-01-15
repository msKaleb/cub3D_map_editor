/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 08:31:43 by msoria-j          #+#    #+#             */
/*   Updated: 2024/01/15 14:39:54 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub_editor.h"

int	close_mlx(t_mlx *m)
{
	free_map(m->map);
	free(m->map_name);
	if (m->mlx && m->img)
		mlx_destroy_image(m->mlx, m->img);
	for (int i = 0; i < MAX_SQUARES; i++) {
		if (m->squares[i].img)
			mlx_destroy_image(m->mlx, m->squares[i].img);
	}
	if (m->win)
		mlx_destroy_window(m->mlx, m->win);
	free(m->mlx);
	exit(EXIT_SUCCESS);
}

/**
 * @brief initializes t_mlx struct and mlx window
  */
void	init_mlx(t_mlx *m, char *path)
{
	char	*title = ft_strjoin("cub3D Map Editor by msoria-j - ", path);

	// init to NULL to avoid free errors
	m->mlx = NULL;
	m->win = NULL;
	m->img = NULL;
	for (int i = 0; i < MAX_SQUARES; i++)
		m->squares[i].img = NULL;
	m->map = NULL;
	m->map_name = NULL;

	m->argv = path;
	m->map_name = title;
	m->mlx = mlx_init();
	if (m->mlx == NULL)
		exit (err_mlx(m));
	m->win = mlx_new_window(m->mlx, m->grid.end_x, m->grid.end_y + BANNER, \
		title);
	if (m->win == NULL)
		exit(err_mlx(m));
	m->img = mlx_new_image(m->mlx, m->grid.end_x, m->grid.end_y);
	if (m->img == NULL)
		exit(err_mlx(m));
	m->addr = mlx_get_data_addr(m->img, &m->bpp, &m->sl, &m->endian);
	if (m->addr == NULL)
		exit(err_mlx(m));
	m->bpp_div = m->bpp / 8;
	m->painting = P_NONE;
}

t_img	init_square_img(t_mlx *m, int index)
{
	t_img	sqr;
	void	*sqr_ptr;
	int		offset;
	int		color[MAX_SQUARES] = {COLOR_FLOOR, COLOR_WALL, COLOR_DOOR, COLOR_PLAYER};

	sqr.img = mlx_new_image(m->mlx, m->grid.step_x, m->grid.step_y);
	sqr.addr = mlx_get_data_addr \
		(sqr.img, &sqr.bpp, &sqr.sl, &sqr.endian);
	sqr.bpp_div = sqr.bpp / 8;
	for (int y = 0; y < m->grid.step_y - 2; y++)
	{
		for (int x = 0; x < m->grid.step_x - 2; x++)
		{
			offset = (y * sqr.sl) + (x * (sqr.bpp_div));
			sqr_ptr = sqr.addr + offset;
			*(unsigned int *)sqr_ptr = mlx_get_color_value(m->mlx, color[index]);
		}
	}
	return (sqr);
}
