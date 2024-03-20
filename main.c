/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnanke <mnanke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:51:57 by mnanke            #+#    #+#             */
/*   Updated: 2024/03/20 18:42:24 by mnanke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	check_input_and_set(int argc, char **argv, t_database *fractol)
{
	if (argc != 2 && argc != 4)
		exit(0);
	if (!ft_strcmp(argv[1], "mandelbrot") && !argv[2])
		fractol->set = 0;
	else if (!ft_strcmp(argv[1], "julia") && argv[2] && argv[3])
	{
		fractol->set = 1;
		fractol->d_a = atof(argv[2]);
		fractol->d_b = atof(argv[3]);
	}
	else
		exit(0);
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

void	put_image(t_data *img, t_database *fractol)
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
			my_mlx_pixel_put(img, x, y, result);
			y++;
		}
		x++;
	}
}

int	main(int argc, char **argv)
{
	t_database	*fractol;
	t_data		img;

	fractol = malloc(sizeof(t_database));
	if (fractol == NULL)
		exit(1);
	check_input_and_set(argc, argv, fractol);
	fractol->mlx = mlx_init();
	fractol->win = mlx_new_window(fractol->mlx, WIDTH, HEIGHT, argv[1]);
	fractol->zoom_factor = 1.0;
	fractol->center_x = 0.0;
	fractol->center_y = 0.0;
	img.img = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
		&img.line_length, &img.endian);
	put_image(&img, fractol);
	mlx_put_image_to_window(fractol->mlx, fractol->win, img.img, 0, 0);
	shortcutmain(fractol);
	mlx_loop(fractol->mlx);
	return (0);
}

__attribute__((destructor)) static void destructor()
{
    system("leaks -q fractol");
}
