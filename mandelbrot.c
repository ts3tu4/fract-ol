/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinozaki <shinozaki@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:14:46 by shinozaki         #+#    #+#             */
/*   Updated: 2023/11/21 18:54:21 by shinozaki        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

void	draw_mandelbrot(void *mlx, void *mlx_win, int width, int height)
{
	int		i;
	int		j;
	double	a;
	double	b;
	double	result;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			a = (double) j / width * 3.5 - 2.5;
			b = (double) i / height * 2.0 - 1.0;
			result = mandelbrot(a, b);
			if (result == 0)
				mlx_pixel_put(mlx, mlx_win, j, i, 0x000000);
			else
				mlx_pixel_put(mlx, mlx_win, j, i, 0xFFFFFF);
			j++;
		}
		i++;
	}
}

double	mandelbrot(double a, double b)
{
	double	x1;
	double	y1;
	double	i;
	double	x;
	double	y;

	i = 0;
	while (i < 20000)
	{
		x1 = a * a - b * b + a;
		y1 = 2 * a * b + b;
		if (x1 * x1 + y1 * y1 > 4)
			return (log(i));
		x = x1;
		y = y1;
		i++;
	}
	return (0);
}
