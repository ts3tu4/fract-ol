/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnanke <mnanke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:51:57 by mnanke            #+#    #+#             */
/*   Updated: 2024/01/13 19:54:41 by mnanke           ###   ########.fr       */
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
int main()
{
    void *mlx;
    void *win;
    void *img;

    mlx = mlx_init();
    win = mlx_new_window(mlx, WIDTH, HEIGHT, "Mandelbrot");
    img = mlx_new_image(mlx, WIDTH, HEIGHT);

    for(int x = 0; x < WIDTH; x++)
    {
        for(int y = 0; y < HEIGHT; y++)
        {
            double real = (x - WIDTH / 2.0) * 4.0 / WIDTH;
            double imag = (y - HEIGHT / 2.0) * 4.0 / HEIGHT;
            int mandelbrot_result = mandelbrot(real, imag); // マンデルブロット集合の計算結果
            int normalized_result = (mandelbrot_result % 256); // 計算結果を0から255の範囲に正規化
            put_pixel_to_image(img, x, y, normalized_result, 0, 0); // 赤色成分に設定
        }
    }

    mlx_put_image_to_window(mlx, win, img, 0, 0);
    mlx_loop(mlx);

    return 0;
}

// __attribute__((destructor)) static void destructor()
// {
//     system("leaks -q fractol");
// }
