/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinozaki <shinozaki@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:52:17 by mnanke            #+#    #+#             */
/*   Updated: 2023/11/21 18:52:20 by shinozaki        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include "mlx/mlx.h"

double	mandelbrot(double a, double b);
void	draw_mandelbrot(void *mlx, void *mlx_win, int width, int height);
#endif