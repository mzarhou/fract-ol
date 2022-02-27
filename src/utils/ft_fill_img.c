/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:40:23 by mzarhou           #+#    #+#             */
/*   Updated: 2022/02/27 11:49:03 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include "utils/utils.h"

double map(double value, double a, double b, double c, double d)
{
	return c + ((value - a) * (d - c) / (b - a));
}

void ft_fill_img(double a, double b, int height, int width, t_img *img)
{
	const int	maxIterations = 200;
	int			nIter;
	double		x;
	double		y;

	a = map(a, 0, width, -2, 2);
	b = map(b, 0, height, -2, 2);
	x = a;
	y = b;
	nIter = 0;
	while (nIter < maxIterations)
	{
		x = x * x - y * y + a;
		y = 2 * x * y + b;
		if (x * x + y * y > 4)
			break;
		nIter++;
	}

	if (nIter == maxIterations)// inside
		return ft_mlx_pixel_put(img, x, y, 0x00000000); // black
	ft_mlx_pixel_put(img, x, y, 0x000000FF);
}
