/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelborot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinozaki <shinozaki@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:14:46 by shinozaki         #+#    #+#             */
/*   Updated: 2023/11/21 18:09:20 by shinozaki        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

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
