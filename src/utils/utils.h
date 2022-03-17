/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:11:20 by mzarhou           #+#    #+#             */
/*   Updated: 2022/03/16 23:43:22 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../fract_ol.h"

typedef struct s_interval
{
	double	start;
	double	end;
}	t_interval;

void	ft_new_image(
			t_data *data,
			void (*fill)(double x, double y, t_data *data)
			);
void	ft_mlx_pixel_put(t_img *img, int x, int y, int color);
void	ft_pixel_coloring(const double a, const double b, t_data *data);
double	ft_map(double value, t_interval from, t_interval to);

#endif
