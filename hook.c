#include "fractal.h"

void	zoom_increase(t_mlxdata *mlxdata)
{
	mlxdata->offsets.scale /= ZOOM_STEP;
	mlxdata->offsets.x += SIZE_X / 2 * mlxdata->offsets.scale;
	mlxdata->offsets.y += SIZE_Y / 2 * mlxdata->offsets.scale;
}

void	zoom_decrease(t_mlxdata *mlxdata)
{
	mlxdata->offsets.scale *= ZOOM_STEP;
	mlxdata->offsets.x -= SIZE_X / 4 * mlxdata->offsets.scale;
	mlxdata->offsets.y -= SIZE_Y / 4 * mlxdata->offsets.scale;
}

int	key_hook(int key, t_mlxdata *mlxdata)
{
	if (key == KEY_EXIT)
		exit(0);
	else if (key == KEY_Z)
		zoom_increase(mlxdata);
	else if (key == KEY_X)
		zoom_decrease(mlxdata);
	draw_fractal(mlxdata);
	return (0);
}

int	mouse_hook(int key, int mouse_x, int mouse_y, t_mlxdata *mlxdata)
{
	(void)mouse_x;
	(void)mouse_y;
	if (key != MOUSE_SCROLL_UP && key != MOUSE_SCROLL_DOWN)
		return (1);
	if (key == MOUSE_SCROLL_UP)
		zoom_increase(mlxdata);
	else
		zoom_decrease(mlxdata);
	draw_fractal(mlxdata);
	return (0);
}

int	exit_hook(t_mlxdata *mlxdata)
{
	(void)mlxdata;
	exit(0);
}
