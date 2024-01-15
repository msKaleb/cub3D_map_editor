/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 09:38:32 by msoria-j          #+#    #+#             */
/*   Updated: 2024/01/15 14:40:33 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub_editor.h"

int	mouse_hook(int button, int x, int y, t_mlx *m)
{
	int	gx;
	int	gy;

	if ((x < MARGIN || y < MARGIN + BANNER)
		|| x > m->grid.end_x || y > m->grid.end_y + BANNER)
		return 1;

	gx = (x - MARGIN) / m->grid.step_x;
	gy = (y - MARGIN - BANNER) / m->grid.step_y;

	if (gx >= m->grid.size_x)
		gx = m->grid.size_x - 1;
	if (gy >= m->grid.size_y)
		gy = m->grid.size_y - 1;

	if (button == B_LEFT)
		m->map[gy][gx] = '1';
	else if (button == B_RIGHT)
		m->map[gy][gx] = '0';
	else if (button == B_MIDDLE)
		m->map[gy][gx] = ' ';

	render_frame(m);
	m->painting = P_NONE;
	return 0;
}

int		set_mouse_painting(int button, int x, int y, t_mlx *m)
{
	(void)x;
	(void)y;
	if (button == B_LEFT)
		m->painting = P_WALL;
	else if (button == B_RIGHT)
		m->painting = P_GROUND;
	else if (button == B_MIDDLE)
		m->painting = P_SPACE;
	return (0);
}
