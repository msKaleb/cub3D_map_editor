/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub_editor.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 08:27:55 by msoria-j          #+#    #+#             */
/*   Updated: 2024/01/06 09:56:06 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CUB_EDITOR_H
# define FT_CUB_EDITOR_H

# include "libft/libft.h"
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <limits.h>

/* Keys may vary depending on the OS */
# ifdef __linux__
#  include "minilibx_linux/mlx.h"	// MLX for Linux
#  define XK_ESCAPE 	0xff1b
#  define XK_W 			0x77
#  define XK_A 			0x61
#  define XK_S 			0x73
#  define XK_D 			0x64
#  define XK_Q 			0x71
#  define XK_E 			0x65
#  define XK_P 			0x70
#  define XK_UP			0xff52
#  define XK_DOWN		0xff54
#  define XK_LEFT		0xff51
#  define XK_RIGHT		0xff53
# elif __APPLE__
#  include "minilibx_opengl/mlx.h"			// MLX for Mac
#  define XK_ESCAPE 	0x35
#  define XK_W 			0x0d
#  define XK_A 			0x00
#  define XK_S 			0x01
#  define XK_D 			0x02
#  define XK_Q 			0x0c
#  define XK_E 			0x0e
#  define XK_P 			0x23
#  define XK_UP			0x7e
#  define XK_DOWN		0x7d
#  define XK_LEFT		0x7b
#  define XK_RIGHT		0x7c
# endif /* OS Check */

/* Not defined in my distro */
# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

/* Some needed values */
# define COLOR_GRID 	0xFFFFFF
# define COLOR_WALL 	0x87CEEB
# define COLOR_SPACE	0x000000
# define COLOR_FLOOR	0x92745B
# define SCREEN_WIDTH 	1000.0
# define SCREEN_HEIGHT	1000.0

/* Events and values for mlx_hook */
# define ON_KEYDOWN		2
# define ON_KEYUP		3
# define ON_MOUSEDOWN	4
# define ON_MOUSEUP		5
# define ON_MOUSEMOVE	6
# define ON_EXPOSE		12
# define ON_DESTROY		17
# define X_MASK			131072 // (1L << 17), for Linux

typedef struct s_mlx	t_mlx;

typedef struct s_point
{
	int			x;
	int			y;
}				t_point;

// the FOV is 2 * atan(0.66/1.0)=66°
typedef struct s_player
{
	t_mlx		*m;

	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		width;
	double		height;

	int			motion_ns;
	int			motion_ew;
	int			motion_rot;

	char		dir;
	char		**map;
}				t_player;

/* minilibx structure */
typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
	void		*addr;

	int			bpp;
	int			sl;
	int			endian;
}				t_mlx;

/* Functions prototipes */
int		key_hook(int key_code, t_mlx *m);
int		render_frame(t_mlx *m);
int		err_arg_number(void);
int		err_file(char *file);
int		close_mlx(t_mlx *m);
int		is_space(char c);
int		err_mlx(void);

void	print_pixel(t_mlx *m, t_point p, int color);
void	free_map(t_player *player);
void	init_mlx(t_mlx *m);

#endif /* FT_CUB_EDITOR_H */
