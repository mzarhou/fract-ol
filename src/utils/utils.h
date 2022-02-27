/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:11:20 by mzarhou           #+#    #+#             */
/*   Updated: 2022/02/27 18:30:28 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
#define UTILS_H

#include "../fract_ol.h"

void ft_new_image(
	void *mlx,
	t_img *img,
	int win_height,
	int win_width,
	void (*fill)(double a, double b, int height, int width, t_img *img, t_data *data),
	t_data *data);
void ft_mlx_pixel_put(t_img *img, int x, int y, int color);
void ft_fill_img(double a, double b, int height, int width, t_img *img, t_data *data);

#endif
