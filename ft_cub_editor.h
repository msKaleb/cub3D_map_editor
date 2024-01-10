/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub_editor.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 08:27:55 by msoria-j          #+#    #+#             */
/*   Updated: 2024/01/10 09:40:29 by msoria-j         ###   ########.fr       */
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
#  define XK_F 			0x66
#  define XK_P 			0x70
#  define XK_UP			0xff52
#  define XK_DOWN		0xff54
#  define XK_LEFT		0xff51
#  define XK_RIGHT		0xff53
# elif __APPLE__
#  include "minilibx_opengl/mlx.h"	// MLX for Mac
#  define XK_ESCAPE 	0x35
#  define XK_W 			0x0d
#  define XK_A 			0x00
#  define XK_S 			0x01
#  define XK_D 			0x02
#  define XK_Q 			0x0c
#  define XK_E 			0x0e
#  define XK_F 			0x03
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
# define COLOR_GRID 	0x696969
# define COLOR_WALL 	0x4169E1
# define COLOR_SPACE	0x000000
# define COLOR_FLOOR	0x808080
# define COLOR_PLAYER	0X228B22
# define COLOR_STRING	0XECE58A
# define COLOR_BANNER	0X0B3846
# define SCREEN_WIDTH 	800.0
# define SCREEN_HEIGHT	800.0
# define MAX_SQUARES	3			// wall, floor, player
# define MARGIN			0			// deprecated
# define BANNER			20			// blank space to write some info

/* Events and values for mlx_hook */
# define ON_KEYDOWN			2
# define ON_KEYUP			3
# define ON_MOUSEDOWN		4
# define ON_MOUSEUP			5
# define ON_MOUSEMOVE		6
# define ON_EXPOSE			12
# define ON_DESTROY			17
# define X_KEYPRESS			1		// (1L << 0)
# define X_KEYRELEASE		2		// (1L << 1)
# define X_POINTERMOTION	64		// (1L << 6)
# define X_MASK				131072	// (1L << 17), for Linux

typedef struct s_point
{
	int		x;
	int		y;
}				t_point;

typedef struct s_grid
{
	int		size_x;
	int		size_y;
	int		step_x;
	int		step_y;
	int		end_x;
	int		end_y;
}				t_grid;

// square images structure
typedef struct s_img
{
	void	*img;
	void	*addr;
	
	int		bpp;
	int		sl;
	int		endian;
}				t_img;

// minilibx structure
typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*addr;

	int		bpp;
	int		sl;
	int		endian;

	t_grid	grid;
	t_img	squares[MAX_SQUARES];	// wall, floor, player
	t_img	banner;

	char	**map;
	char	*argv;					// the map name provided
	char	*map_name;
	int		painting;				// flag for different square types
	int		fd;
}				t_mlx;

// painting mode flags
enum e_paintings {
	P_NONE		= 0,
	P_WALL		= 1,
	P_GROUND	= 2,
	P_FLOOD		= 3,
	P_NORTH		= 4,
	P_SOUTH		= 5,
	P_WEST		= 6,
	P_EAST		= 7,
	P_SPACE		= 8
};

/* Functions prototipes */
int		mouse_hook(int button, int x, int y, t_mlx *m);
int		release_painting(int key_code, t_mlx *m);
int		set_painting(int key_code, t_mlx *m);
int		render_loop(int x, int y, t_mlx *m);
int		render_frame(t_mlx *m);
int		err_arg_number(void);
int		err_file(char *file);
int		close_mlx(t_mlx *m);
int		err_mlx(t_mlx *m);

void	flood_fill(char **tab, t_point size, t_point begin);
void	init_map_data(t_mlx *m, t_point *p);
void	print_pixel(t_mlx *m, t_point p, int color);
void	render_grid(t_mlx *m, t_grid grid);
void	init_mlx(t_mlx *m, char *path);
void	print_map(char **map, int fd);
void	free_map(char **map);
void	print_controls(void);

char	**create_map(int rows, int cols);

t_img	init_square_img(t_mlx *m, int index);
t_grid	init_grid(int x, int y);

#endif /* FT_CUB_EDITOR_H */
