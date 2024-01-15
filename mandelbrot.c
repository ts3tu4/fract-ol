/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnanke <mnanke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:14:46 by shinozaki         #+#    #+#             */
/*   Updated: 2024/01/03 01:03:19 by mnanke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int mandelbrot(double real, double imag)
{
    int n;
    double r = 0.0;
    double i = 0.0;

    for(n = 0; n < MAX_ITER; n++)
    {
        double r2 = r * r;
        double i2 = i * i;
        if (r2 + i2 > 4.0)
            break;
        i = 2 * r * i + imag;
        r = r2 - i2 + real;
    }

    return n;
}
