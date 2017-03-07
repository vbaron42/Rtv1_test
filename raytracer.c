//42

#include "rtv1.h"

void		raytracer(t_env *env)
{
	int	x;
	int	y;

	y = 0;
	while (x < WIN_LENGHT)
	{
		x = 0;
		while (y < WIN_HEIGHT)
		{
			get_pixel_color(get_all_color(x, y, env));// ?
			x++;
		}
	y++;
	}
}
