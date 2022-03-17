/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_burning_ship_iterate.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 18:57:30 by mzarhou           #+#    #+#             */
/*   Updated: 2022/03/17 19:20:55 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sets/sets.h"

double	ft_abs(double value)
{
	if (value < 0)
		return (-value);
	return (value);
}

int	ft_burning_ship_iterate(const double maped_a,
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
		yy = ft_abs(2 * x * y) + maped_b;
		x = xx;
		y = yy;
		nb_iter++;
		if (x * x + y * y > 4)
			break ;
	}
	return (nb_iter);
}
