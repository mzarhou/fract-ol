/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:11:08 by mzarhou           #+#    #+#             */
/*   Updated: 2022/02/27 18:30:56 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils.h"
#include <mlx.h>

void ft_new_image(
	void *mlx,
	t_img *img,
	int win_height,
	int win_width,
	void (*fill)(double x, double y, int height, int width, t_img *img, t_data *data),
	t_data *data
) {
	int x;
	int y;

	img->ptr = mlx_new_image(mlx, win_height, win_width);
	img->pixels = mlx_get_data_addr(
		img->ptr,
		&img->bits_per_pixel,
		&img->line_length,
		&img->endian
	);
	y = -1;
	while (++y < win_height)
	{
		x = -1;
		while (++x < win_width)
			fill(x, y, win_height, win_width, img, data);
	}
}
