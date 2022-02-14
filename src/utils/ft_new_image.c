/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:11:08 by mzarhou           #+#    #+#             */
/*   Updated: 2022/02/14 20:02:43 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils.h"
#include <mlx.h>

void	ft_new_image(void *mlx, t_img *img, int win_height, int win_width)
{
	img->ptr = mlx_new_image(mlx, win_height, win_width);
	img->pixels = mlx_get_data_addr(
			img->ptr,
			&img->bits_per_pixel,
			&img->line_length,
			&img->endian);
}
