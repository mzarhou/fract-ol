/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:40:23 by mzarhou           #+#    #+#             */
/*   Updated: 2022/03/16 22:10:08 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "utils/utils.h"
#include "mlx.h"

double ft_map(double value, double a, double b, double c, double d)
{
	return c + ((value - a) * (d - c) / (b - a));
}

int	ft_iterate(const double maped_a, const double maped_b, double max_iterations)
{
	int			nb_iter;
	double		x;
	double		xx;
	double		y;
	double		yy;

	x = maped_a;
	y = maped_b;
	nb_iter = 0;
	xx = 0;
	yy =0;
	while (nb_iter < max_iterations)
	{
		xx = x * x - y * y + maped_a;
		yy = 2 * x * y + maped_b;
		x = xx;
		y = yy;
		nb_iter++;
		if (x * x + y * y > 4)
			break;
	}
	return (nb_iter);
}

void ft_fill_img(const double a, const double b, t_data *data)
{
	int			nb_iterations;
	double		maped_a;
	double		maped_b;

	maped_a = ft_map(a, 0, data->win_width, data->x - data->zoom, data->x + data->zoom);
	maped_b = ft_map(b, 0, data->win_height, data->y - data->zoom, data->y + data->zoom);
	nb_iterations = ft_iterate(maped_a, maped_b, data->max_iterations);
	if (nb_iterations == data->max_iterations)// inside
		ft_mlx_pixel_put(&data->img,a, b, 0);
	else
		ft_mlx_pixel_put(&data->img,a, b, data->color * nb_iterations);
}
