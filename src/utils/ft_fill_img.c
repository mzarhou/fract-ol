/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:40:23 by mzarhou           #+#    #+#             */
/*   Updated: 2022/03/16 21:10:15 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include "utils/utils.h"
#include "mlx.h"

double ft_map(double value, double a, double b, double c, double d)
{
	return c + ((value - a) * (d - c) / (b - a));
}

void ft_fill_img(double a, double b, t_data *data)
{
	int			nIter;
	int			i, r;
	double		x;
	double		xx;
	double		y;
	double		yy;

	i = a;
	r = b;

	a = ft_map(a, 0, data->win_width, data->x - data->zoom, data->x + data->zoom);
	b = ft_map(b, 0, data->win_height, data->y - data->zoom, data->y + data->zoom);
	x = a;
	y = b;
	nIter = 0;
	xx = 0;
	yy =0;
	while (nIter < data->max_iterations)
	{
		xx = x * x - y * y + a;
		yy = 2 * x * y + b;
		x = xx;
		y = yy;
		nIter++;
		if (x * x + y * y > 4)
			break;
	}
	if (nIter == data->max_iterations)// inside
		ft_mlx_pixel_put(&data->img,i, r, 0);
	else
		ft_mlx_pixel_put(&data->img,i, r, data->color * nIter);
}
