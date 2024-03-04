/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnanke <mnanke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:51:57 by mnanke            #+#    #+#             */
/*   Updated: 2024/03/04 15:13:17 by mnanke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

void	put_image(t_data *img)
{
	int		x;
	int		y;
	double	real;
	double	imag;
	int		mandelbrot_result;

	x = 0;
	y = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			real = (x - WIDTH / 2.0) * 4.0 / WIDTH;
			imag = (y - HEIGHT / 2.0) * 4.0 / HEIGHT;
			mandelbrot_result = mandelbrot(real, imag);
			my_mlx_pixel_put(img, x, y, mandelbrot_result);
			y++;
		}
		x++;
	}
}

int	main(void)
{
	void	*mlx;
	void	*win;
	t_data	img;

	mlx = mlx_init();
	win = mlx_new_window(mlx, WIDTH, HEIGHT, "Mandelbrot");
	img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
		&img.line_length, &img.endian);
	put_image(&img);
	mlx_put_image_to_window(mlx, win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}

// __attribute__((destructor)) static void destructor()
// {
//     system("leaks -q fractol");
// }
