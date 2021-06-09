#ifndef FRACTAL_H
# define FRACTAL_H

# include "mlx.h"
# include "mlx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <unistd.h>

# define SIZE_X 800
# define SIZE_Y 600

# define JULIA_A -0.2
# define JULIA_B -0.75

# define NO 0
# define YES 1
# define DEFAULT 0
# define ZOOM_STEP 2
# define COLOR_STEP 5
# define OFFSET_STEP 10
# define OFFSET_COLOR_MAX 220
# define COMPLEX_ROUNDS_MAX 100
# define COMPLEX_MODULE_MAX 2.0

typedef enum e_types
{
	MANDELBROT = 1,
	JULIA = 2
}				t_types;

typedef enum e_keys
{
	KEY_EXIT = 53,
	KEY_RIGHT = 124,
	KEY_LEFT = 123,
	KEY_UP = 126,
	KEY_DOWN = 125,
	KEY_Q = 12,
	KEY_Z = 6,
	KEY_X = 7,
	MOUSE_SCROLL_UP = 5,
	MOUSE_SCROLL_DOWN = 4
}				t_keys;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_complex
{
	double	a;
	double	b;
}				t_complex;

typedef struct s_offset
{
	double	x;
	double	y;
	int		color;
	double	scale;
}				t_offset;

typedef struct s_mlxdata
{
	void		*mlx;
	void		*win;
	t_data		img;
	t_complex	z;
	t_complex	C;
	t_offset	offsets;
	int			type;
	int			first_draw;
}				t_mlxdata;

int				ft_strlen(char *str);
void			define_error(char *err);
void			complex_set(t_complex *comp, double a, double b);
t_complex		complex_add(t_complex comp1, t_complex comp2);
t_complex		complex_square(t_complex comp);
double			complex_module(t_complex comp);

int				draw_fractal(t_mlxdata *mlxdata);
int				first_draw_fractal(t_mlxdata *mlxdata);
int				key_hook(int key, t_mlxdata *mlxdata);
int				mouse_hook(int key, int mouse_x, int mouse_y, \
t_mlxdata *mlxdata);
int				exit_hook(t_mlxdata *mlxdata);

int				mlx_create_rgb(int r, int g, int b);
unsigned int	mlx_pixel_get_f(t_mlxdata *mlxdata, int x, int y);
void			mlx_pixel_put_f(t_mlxdata *mlxdata, int x, int y, int color);
void			mlx_win_update(t_mlxdata *mlxdata);

#endif
