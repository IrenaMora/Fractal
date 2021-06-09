#include "fractal.h"

void	validate_args(int args_count, char **args)
{
	char	*arg;

	arg = args[1];
	if (args_count < 2 || (arg[0] != 'm' && arg[0] != 'M' && arg[0] != 'j' \
	&& arg[0] != 'J') || ft_strlen(arg) != 1)
		define_error("Wrong params. Please, give as the first " \
			   "argument \"M\" (Mandelbrot) or \"J\" (Julia)");
}

void	set_fractal_type(t_mlxdata *mlxdata, char **args)
{
	char	*arg;

	arg = args[1];
	if (arg[0] == 'm' || arg[0] == 'M')
		mlxdata->type = MANDELBROT;
	else if (arg[0] == 'j' || arg[0] == 'J')
		mlxdata->type = JULIA;
}

void	mlxdata_init(t_mlxdata *mlxdata)
{
	char	*caption;

	if (mlxdata->type == MANDELBROT)
		caption = "Mandelbrot";
	else
		caption = "Julia";
	mlxdata->mlx = mlx_init();
	mlxdata->win = mlx_new_window(mlxdata->mlx, SIZE_X, SIZE_Y, caption);
	mlxdata->img.img = mlx_new_image(mlxdata->mlx, SIZE_X, SIZE_Y);
	mlxdata->img.addr = mlx_get_data_addr(mlxdata->img.img, &mlxdata->img.bits_per_pixel, \
	&mlxdata->img.line_length, &mlxdata->img.endian);
	complex_set(&mlxdata->z, 0, 0);
	complex_set(&mlxdata->C, 0, 0);
	mlxdata->offsets.x = DEFAULT;
	mlxdata->offsets.y = DEFAULT;
	mlxdata->offsets.color = DEFAULT;
	mlxdata->offsets.scale = 1;
	mlxdata->first_draw = YES;
}

int	main(int args_count, char **args)
{
	t_mlxdata	mlxdata;

	validate_args(args_count, args);
	set_fractal_type(&mlxdata, args);
	mlxdata_init(&mlxdata);
	mlx_loop_hook(mlxdata.mlx, draw_fractal, &mlxdata);
	mlx_key_hook(mlxdata.win, key_hook, &mlxdata);
	mlx_mouse_hook(mlxdata.win, mouse_hook, &mlxdata);
	mlx_hook(mlxdata.win, 17, 0L, exit_hook, &mlxdata);
	mlx_loop(mlxdata.mlx);
	return (0);
}
