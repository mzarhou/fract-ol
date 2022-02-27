/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:28:46 by mzarhou           #+#    #+#             */
/*   Updated: 2022/02/27 18:28:01 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include "fract_ol.h"
#include "events/events.h"
#include "utils/utils.h"

int	main(void)
{
	t_data		data;
	t_img		img;
	const int	win_height = 600;
	const int	win_width = 600;

	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(
			data.mlx_ptr, win_width, win_height, "Fract OL");
	ft_new_image(data.mlx_ptr, &img, win_height, win_width, &ft_fill_img, &data);
	// mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, img.ptr, 0, 0);
	ft_register_events(&data);
	mlx_loop(data.mlx_ptr);
}
