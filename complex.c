#include "fractal.h"

void	complex_set(t_complex *comp, double a, double b)
{
	comp->a = a;
	comp->b = b;
}

t_complex	complex_add(t_complex comp1, t_complex comp2)
{
	t_complex	new;

	new.a = comp1.a + comp2.a;
	new.b = comp1.b + comp2.b;
	return (new);
}

t_complex	complex_square(t_complex comp)
{
	t_complex	square;

	square.a = (comp.a * comp.a) - (comp.b * comp.b);
	square.b = 2 * comp.a * comp.b;
	return (square);
}

double	complex_module(t_complex comp)
{
	double	module;

	module = sqrt((comp.a * comp.a) + (comp.b * comp.b));
	return (module);
}
