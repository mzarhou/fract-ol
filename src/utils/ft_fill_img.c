/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:40:23 by mzarhou           #+#    #+#             */
/*   Updated: 2022/02/14 19:53:37 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils.h"

void	ft_fill_img(t_img *img, int height, int width, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < width)
	{
		x = 0;
		while (x < height)
		{
			ft_mlx_pixel_put(img, x, y, color);
			x++;
		}
		y++;
	}
}
