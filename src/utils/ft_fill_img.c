/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:40:23 by mzarhou           #+#    #+#             */
/*   Updated: 2022/02/21 01:30:13 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include "utils/utils.h"

typedef struct s_complex
{
	double	real;
	double	imaginary;
}	t_complex;

t_complex ft_zPower2(double x, double y)
{
	t_complex complex;
	complex.real = pow(x, 2) - pow(y, 2);
	complex.imaginary = 2 * x * y;
	return complex;
}

t_complex ft_addComplex(t_complex c1, t_complex c2)
{
	t_complex result;
	result.imaginary = c1.imaginary + c2.imaginary;
	result.real = c1.real + c2.real;
	return result;
}

double map(double value, double x0, double y0, double x1, double y1)
{
	return value * (y1 - x1) / (y0 - x0);
}

double ft_abs(double value) {
	if (value < 0)
		return -value;
	return value;
}


void	ft_fill_img(t_img *img, int height, int width, int color)
{
	static const int maxIterations = 100;
	double	x;
	double	y;
	int nIter;
	t_complex result;
	t_complex C;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			nIter = 0;
			C.real = map(x, 0, width, -2, 2);
			C.imaginary = map(y, 0, height, -2, 2);

			while (nIter <= maxIterations)
			{
				result = ft_addComplex(ft_zPower2(C.real, C.imaginary), C);
				if (ft_abs(C.real + C.imaginary) > 4) {
					if (ft_abs(C.real + C.imaginary) < 4)
						printf("%lf\n", ft_abs(C.real + C.imaginary));
					break;
				}
				nIter++;
			}

			if (nIter == maxIterations) {
				// inside
				// black
				ft_mlx_pixel_put(img, x, y, color);
			} else {
				// outside
				// color
				ft_mlx_pixel_put(img, x, y, 0x00000000);
			}
			x++;
		}
		y++;
	}
}
