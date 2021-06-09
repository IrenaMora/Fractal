#include "fractal.h"

int	ft_strlen(char *str)
{
	int	position;

	position = 0;
	while (str[position])
		position++;
	return (position);
}

void	define_error(char *err)
{
	int	length;

	length = ft_strlen(err);
	write(2, err, length);
	write(2, "\n", 1);
	exit(0);
}
