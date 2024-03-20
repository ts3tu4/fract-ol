/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnanke <mnanke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:14:46 by shinozaki         #+#    #+#             */
/*   Updated: 2024/03/20 18:42:12 by mnanke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(double real, double imag)
{
	int		n;
	double	r1;
	double	i1;
	double	r2;
	double	i2;

	r1 = 0.0;
	i1 = 0.0;
	n = 0;
	while (n < MAX_ITER)
	{
		r2 = r1 * r1;
		i2 = i1 * i1;
		if (r2 + i2 > 4.0)
			break ;
		i1 = 2 * r1 * i1 + imag;
		r1 = r2 - i2 + real;
		n++;
	}
	return (n);
}

int	julia(double real, double imag, t_database *fractol)
{
	int		n;
	double	r1;
	double	i1;
	double	r2;
	double	i2;

	r1 = real;
	i1 = imag;
	n = 0;
	while (n < MAX_ITER)
	{
		r2 = r1 * r1;
		i2 = i1 * i1;
		if (r2 + i2 > 4.0)
			break ;
		i1 = 2 * r1 * i1 + fractol->d_b;
		r1 = r2 - i2 + fractol->d_a;
		n++;
	}
	return (n);
}
