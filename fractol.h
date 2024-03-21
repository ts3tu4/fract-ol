/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnanke <mnanke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:52:17 by mnanke            #+#    #+#             */
/*   Updated: 2024/03/22 00:31:49 by mnanke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 800
# define IMAG_CONSTANT 0.156
# define REAL_CONSTANT 0.8

# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include "mlx.h"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx;
	void	*win;
	double	zoom_factor;
	double	center_x;
	double	center_y;
	int		set;
	double	d_a;
	double	d_b;
}	t_data;

int		mandelbrot(double real, double imag);
int		close_program(void *param);
int		shortcutmain(t_data *fractol);
int		zoooom(int button, int x, int y, t_data *fractol);
int		julia(double real, double imag, t_data *fractol);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_error(t_data *fractol);
#endif
