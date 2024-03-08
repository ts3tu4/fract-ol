/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortcut.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnanke <mnanke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:34:22 by mnanke            #+#    #+#             */
/*   Updated: 2024/03/08 17:37:59 by mnanke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	shortcutmain(t_database *fractol)
{
	mlx_hook(fractol->win, 17, 0, close_program, (void *)0);
	mlx_mouse_hook(fractol->win, zoooom, fractol);
	return (0);
}

int	close_program(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

int	zoooom(int button, int x, int y, t_database *fractol)
{
	if (button == 5)
	{
		fractol->zoom_factor *= 0.9;
		fractol->center_x = (x - WIDTH / 2.0) * 4.0 / WIDTH;
		fractol->center_y = (y - HEIGHT / 2.0) * 4.0 / HEIGHT;
	}
	return (0);
}
