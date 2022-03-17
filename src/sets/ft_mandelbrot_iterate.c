/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot_iterate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 23:26:46 by mzarhou           #+#    #+#             */
/*   Updated: 2022/03/17 01:02:45 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sets/sets.h"

int	ft_mandelbrot_iterate(const double maped_a,
	const double maped_b, const t_data *data)
{
	int		nb_iter;
	double	x;
	double	xx;
	double	y;
	double	yy;

	x = maped_a;
	y = maped_b;
	nb_iter = 0;
	xx = 0;
	yy = 0;
	while (nb_iter < data->max_iterations)
	{
		xx = x * x - y * y + maped_a;
		yy = 2 * x * y + maped_b;
		x = xx;
		y = yy;
		nb_iter++;
		if (x * x + y * y > 16)
			break ;
	}
	return (nb_iter);
}
