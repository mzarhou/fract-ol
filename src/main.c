/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:28:46 by mzarhou           #+#    #+#             */
/*   Updated: 2022/03/13 20:56:05 by mzarhou          ###   ########.fr       */
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
	data.win_height = 600;
	data.win_width = 600;

	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(
			data.mlx_ptr, data.win_width, data.win_height, "Fract OL");
	ft_new_image(&data, &ft_fill_img);
	ft_register_events(&data);
	mlx_loop(data.mlx_ptr);
}
