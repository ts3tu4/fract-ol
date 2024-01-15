/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnanke <mnanke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:51:57 by mnanke            #+#    #+#             */
/*   Updated: 2024/01/15 16:07:38 by mnanke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void put_pixel_to_image(void *img, int x, int y, int red, int green, int blue)
{
    char *data;
    int bpp;
    int sizeline;
    int endian;
    data = mlx_get_data_addr(img, &bpp, &sizeline, &endian);
    int i = (x * 4) + (y * sizeline);
    data[i] = blue;
    data[i + 1] = green;
    data[i + 2] = red;
}

void	put_image(void *img)
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
		while (y < HEIGHT)
		{
			real = (x - WIDTH / 2.0) * 4.0 / WIDTH;
			imag = (y - HEIGHT / 2.0) * 4.0 / HEIGHT;
			mandelbrot_result = mandelbrot(real, imag);
			put_pixel_to_image(img, x, y, 0, 0, 0);
			y++;
		}
		x++;
	}
}

int	main(void)
{
	void	*mlx;
	void	*win;
	void	*img;

	mlx = mlx_init();
	win = mlx_new_window(mlx, WIDTH, HEIGHT, "Mandelbrot");
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	put_image(img);
	mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_loop(mlx);
	return (0);
}

// __attribute__((destructor)) static void destructor()
// {
//     system("leaks -q fractol");
// }
