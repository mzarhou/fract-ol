/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel_coloring.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 01:17:46 by mzarhou           #+#    #+#             */
/*   Updated: 2022/03/17 03:36:48 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "utils/utils.h"
#include "mlx.h"

void	ft_pixel_coloring(const double a, const double b, t_data *data)
{
	int			nb_iterations;
	double		maped_a;
	double		maped_b;

	maped_a = ft_map(a,
			(t_interval){0, data->win_width},
			(t_interval){
			data->origin.a - data->zoom, data->origin.a + data->zoom});
	maped_b = ft_map(b,
			(t_interval){0, data->win_height},
			(t_interval){
			data->origin.b - data->zoom, data->origin.b + data->zoom});
	nb_iterations = data->iterate(maped_a, maped_b, data);
	if (nb_iterations == data->max_iterations)
		ft_mlx_pixel_put(&data->img, a, b, 0);
	else
		ft_mlx_pixel_put(&data->img, a, b, data->color * nb_iterations);
}
