/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnanke <mnanke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:51:57 by mnanke            #+#    #+#             */
/*   Updated: 2024/03/22 00:23:37 by mnanke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	check_input_and_set(int argc, char **argv, t_data *fractol)
{
	if (argc != 2 && argc != 4)
		ft_error(fractol);
	if (!ft_strcmp(argv[1], "mandelbrot") && !argv[2])
		fractol->set = 0;
	else if (!ft_strcmp(argv[1], "julia") && argv[2] && argv[3])
	{
		fractol->set = 1;
		fractol->d_a = atof(argv[2]);
		fractol->d_b = atof(argv[3]);
	}
	else
		ft_error(fractol);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int result)
{
	char	*dst;
	int		red;
	int		green;
	int		blue;

	if (result != MAX_ITER)
	{
		green = result * 5;
		blue = result * 20;
		red = 0;
	}
	else
	{
		green = 0;
		blue = 0;
		red = 0;
	}
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = (red << 16) | (green << 8) | blue;
}

void	put_image(t_data *fractol)
{
	int		x;
	int		y;
	double	real;
	double	imag;
	int		result;

	x = 0;
	y = 0;

	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			real = (x - WIDTH / 2.0) * 4.0 * \
				fractol->zoom_factor / WIDTH + fractol->center_x;
			imag = (y - HEIGHT / 2.0) * 4.0 * \
				fractol->zoom_factor / HEIGHT + fractol->center_y;
			if (fractol->set == 0)
				result = mandelbrot(real, imag);
			else
				result = julia(real, imag, fractol);
			my_mlx_pixel_put(fractol->img, x, y, result);
			y++;
		}
		x++;
	}
}

int	main(int argc, char **argv)
{
	t_data	*fractol;

	fractol = malloc(sizeof(t_data));
	if (fractol == NULL)
		exit(0);
	check_input_and_set(argc, argv, fractol);
	fractol->mlx = mlx_init();
	fractol->win = mlx_new_window(fractol->mlx, WIDTH, HEIGHT, argv[1]);
	fractol->zoom_factor = 1.0;
	fractol->center_x = 0.0;
	fractol->center_y = 0.0;
	fractol->img = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	fractol->addr = mlx_get_data_addr(fractol->img, &fractol->bits_per_pixel, \
		&fractol->line_length, &fractol->endian);
	put_image(fractol);
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img, 0, 0);
	shortcutmain(fractol);
	mlx_loop(fractol->mlx);
	return (0);
}

__attribute__((destructor)) static void destructor()
{
    system("leaks -q fractol");
}
