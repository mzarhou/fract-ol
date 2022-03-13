/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:11:08 by mzarhou           #+#    #+#             */
/*   Updated: 2022/03/13 21:54:39 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils.h"
#include <mlx.h>

void ft_new_image(
	t_data *data,
	void (*fill)(double x, double y, t_data *data)
) {
	int x;
	int y;

	data->img->ptr = mlx_new_image(data->mlx_ptr, data->win_height, data->win_width);
	data->img->pixels = mlx_get_data_addr(
		data->img->ptr,
		&data->img->bits_per_pixel,
		&data->img->line_length,
		&data->img->endian
	);
	y = -1;
	while (++y < data->win_height)
	{
		x = -1;
		while (++x < data->win_width)
			fill(x, y, data);
	}
}
