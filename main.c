/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinozaki <shinozaki@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:51:57 by mnanke            #+#    #+#             */
/*   Updated: 2023/11/21 18:09:55 by shinozaki        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	double	a;
	double	b;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 600, 400, "Hello world!");
	img.img = mlx_new_image(mlx, 600, 400);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	for (a = C0r-VS; a < C0r+VS; a += 2.0*VS/STEP) {
		for (b = C0i-VS; b < C0i+VS; b += 2.0*VS/STEP) {
			printf("%1.14e %1.14e %1.14e\n", a, b, mandelbrot(a, b));
		}
		printf("\n"); // これがないとgnuplotでエラーが出る
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
