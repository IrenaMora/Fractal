#include "fractal.h"

int	mlx_create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

unsigned int	mlx_pixel_get_f(t_mlxdata *mlxdata, int x, int y)
{
	char	*dst;
	t_data	*data;

	data = &mlxdata->img;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

void	mlx_pixel_put_f(t_mlxdata *mlxdata, int x, int y, int color)
{
	char	*dst;
	t_data	*data;

	data = &mlxdata->img;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	mlx_win_update(t_mlxdata *mlxdata)
{
	mlx_put_image_to_window(mlxdata->mlx, mlxdata->win, mlxdata->img.img, 0, 0);
}
