/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnanke <mnanke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:51:57 by mnanke            #+#    #+#             */
/*   Updated: 2023/11/20 18:40:31 by mnanke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>
 
#define C0r     -0.743  // 計算する場所の中心座標（実数部）
#define C0i      0.1145 // 計算する場所の中心座標（虚数部）
#define VS       0.003  // 計算する場所の中心座標からの範囲（±VS）
 
#define NMAX     20000  // 計算の繰り返し上限
#define STEP     800.0  // 計算する刻み

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

void	my_mlx_pixel_put(char *addr, int line_length, int bits_per_pixel, int x, int y, int color)
{
	char	*dst;

	dst = addr + (y * line_length + x * (bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

double mandelbrot(double a, double b){
  double x = 0.0;
  double y = 0.0;
  double x1, y1;
 
  int n;
 
  for (n = 1; n <= NMAX; n++) {
    x1 = x * x - y * y + a;
    y1 = 2.0 * x * y + b;
    if ( x1 * x1 + y1 * y1 > 4.0) return log(n); // 発散
    x = x1;
    y = y1;
  }
  return 0; // 計算の繰り返し上限到達
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		i;
	int		j;
	double a, b;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 600, 400, "Hello world!");
	img.img = mlx_new_image(mlx, 600, 400);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			my_mlx_pixel_put(img.addr, img.line_length, img.bits_per_pixel,
				50 + i, 50 + j, 0x00FF0000);
			j++;
		}
		i++;
	}

	for (a = C0r-VS; a < C0r+VS; a += 2.0*VS/STEP) {
    	for (b = C0i-VS; b < C0i+VS; b += 2.0*VS/STEP) {
      		printf("%1.14e %1.14e %1.14e\n", a, b, mandelbrot(a, b));
    	}
    	printf("\n"); // これがないとgnuplotでエラーが出る
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
