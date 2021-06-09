#include "fractal.h"

int	get_color(t_mlxdata *mlxdata)
{
	int	rounds;
	int	color;

	rounds = 0;
	while (rounds < COMPLEX_ROUNDS_MAX && complex_module(mlxdata->z) \
	<= COMPLEX_MODULE_MAX)
	{
		mlxdata->z = complex_square(mlxdata->z);
		mlxdata->z = complex_add(mlxdata->z, mlxdata->C);
		rounds++;
	}
	color = mlxdata->offsets.color;
	if (rounds >= COMPLEX_ROUNDS_MAX)
		return (mlx_create_rgb(rounds + color, rounds / 5 + color \
		, rounds / 5 + color));
	else
		return (mlx_create_rgb((rounds + color) * 20, (rounds + color) * 10, \
		(rounds + color) * 5 ));
}

int	get_fractal_color(t_mlxdata *mlxdata, int x, int y)
{
	double	a;
	double	b;

	a = (double)(x * mlxdata->offsets.scale + mlxdata->offsets.x \
	- SIZE_X / 2) / (double)(SIZE_X / 4);
	b = (double)(y * mlxdata->offsets.scale + mlxdata->offsets.y \
	- SIZE_Y / 2) / (double)(SIZE_Y / 4);
	if (mlxdata->type == MANDELBROT)
	{
		complex_set(&mlxdata->C, a, b);
		complex_set(&mlxdata->z, 0, 0);
	}
	else if (mlxdata->type == JULIA)
	{
		complex_set(&mlxdata->z, a, b);
		complex_set(&mlxdata->C, JULIA_A, JULIA_B);
	}
	return (get_color(mlxdata));
}

int	draw_fractal(t_mlxdata *mlxdata)
{
	int	x;
	int	y;
	int	color;

	x = 0;
	while (x < SIZE_X)
	{
		y = 0;
		while (y < SIZE_Y)
		{
			color = get_fractal_color(mlxdata, x, y);
			mlx_pixel_put_f(mlxdata, x, y, color);
			y++;
		}
		x++;
	}
	mlx_win_update(mlxdata);
	return (0);
}

int	first_draw_fractal(t_mlxdata *mlxdata)
{
	if (!mlxdata->first_draw)
		return (1);
	draw_fractal(mlxdata);
	mlxdata->first_draw = NO;
	return (0);
}
