/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinozaki <shinozaki@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:51:57 by mnanke            #+#    #+#             */
/*   Updated: 2023/11/21 18:40:57 by shinozaki        ###   ########.fr       */
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

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 600, 400, "mandelbrot");
	
	mlx_loop(mlx);
}
