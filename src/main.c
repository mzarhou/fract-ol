/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:28:46 by mzarhou           #+#    #+#             */
/*   Updated: 2022/03/16 20:37:56 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include "fract_ol.h"
#include "events/events.h"
#include "utils/utils.h"
#include "unistd.h"

#include <mlx.h>


void ft_render(t_data* data) {
	int	i = -1, j = -1;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	while(++i < data->win_width ) {
		j = -1;
		while (++j < data->win_height) {
			ft_fill_img(i, j, data);
		}
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr , data->img.ptr, 0, 0);
}

int	main(void)
{
	t_data	data;

	data.win_width = 600;
	data.win_height = 600;
	data.zoom = 2;
	data.x = 0;
	data.y = 0;

	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.win_width, data.win_height, "Hello world!");
	data.img.ptr = mlx_new_image(data.mlx_ptr, data.win_width, data.win_height);
	data.img.pixels = mlx_get_data_addr(data.img.ptr, &data.img.bits_per_pixel, &data.img.line_length,
								&data.img.endian);
	ft_register_events(&data);
	// mlx_hook(data.win_ptr, ON_MOUSEDOWN, 0, ft_mouse_hook, &data);
	ft_render(&data);
	mlx_loop(data.mlx_ptr);
}
