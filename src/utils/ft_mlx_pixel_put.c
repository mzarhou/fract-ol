/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_pixel_put.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:09:28 by mzarhou           #+#    #+#             */
/*   Updated: 2022/02/27 11:28:24 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils.h"

void	ft_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->pixels + (
			y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
