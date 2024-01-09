/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 08:31:43 by msoria-j          #+#    #+#             */
/*   Updated: 2024/01/10 00:20:52 by msoria-j         ###   ########.fr       */
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

/* int	key_hook(int key_code, t_mlx *m)
{
	if (key_code == XK_ESCAPE)
		close_mlx(m);
	if (key_code == XK_UP)
		m->painting = P_NORTH;
	if (key_code == XK_W)
		m->painting = P_WALL;
	return (0);
} */

int	mouse_hook(int button, int x, int y, t_mlx *m)
{
	int	gx = (x - MARGIN) / m->grid.step_x;
	int	gy = (y - MARGIN - BANNER) / m->grid.step_y;

	/* if ((x < MARGIN || y < MARGIN + BANNER)
		|| (x > SCREEN_WIDTH - MARGIN || y > SCREEN_HEIGHT + BANNER - MARGIN)) */
	if ((x < MARGIN || y < MARGIN + BANNER)
		|| x > m->grid.end_x || y > m->grid.end_y + BANNER)
		return 1;

	if (gx >= m->grid.size_x)
		gx = m->grid.size_x - 1;
	if (gy >= m->grid.size_y)
		gy = m->grid.size_y - 1;

	if (button == 1)
		m->map[gy][gx] = '1';
	else if (button == 3)
		m->map[gy][gx] = '0';
	else if (button == 2)
		m->map[gy][gx] = ' ';
	// ft_fprintf(1, "button: %d - x: %d - y: %d\n", button, gx, gy);
	render_frame(m);
	return 0;
}

/**
 * @todo check leaks on exit()
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
	m->win = mlx_new_window(m->mlx, SCREEN_WIDTH, SCREEN_HEIGHT + BANNER, \
		title);
	if (m->win == NULL)
		exit(err_mlx(m));
	m->img = mlx_new_image(m->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (m->img == NULL)
		exit(err_mlx(m));
	m->addr = mlx_get_data_addr(m->img, &m->bpp, &m->sl, &m->endian);
	m->painting = P_NONE;
}

t_img	init_square_img(t_mlx *m, int index)
{
	t_img	sqr;
	void	*sqr_ptr;
	int		offset;
	int		color[MAX_SQUARES] = {COLOR_WALL, COLOR_FLOOR, COLOR_PLAYER};

	sqr.img = mlx_new_image(m->mlx, m->grid.step_x, m->grid.step_y);
	sqr.addr = mlx_get_data_addr \
		(sqr.img, &sqr.bpp, &sqr.sl, &sqr.endian);
	for (int y = 0; y < m->grid.step_y - 2; y++)
	{
		for (int x = 0; x < m->grid.step_x - 2; x++)
		{
			offset = (y * sqr.sl) + (x * (sqr.bpp / 8));
			sqr_ptr = sqr.addr + offset;
			*(unsigned int *)sqr_ptr = mlx_get_color_value(m->mlx, color[index]);
			// ft_fprintf(1, "x: %d - y: %d\n", i, j);
		}
	}
	return (sqr);
}
