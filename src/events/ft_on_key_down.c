/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_on_key_down.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:18:38 by mzarhou           #+#    #+#             */
/*   Updated: 2022/03/17 19:17:14 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"
#include "events/events.h"
#include "sets/sets.h"
#include <stdlib.h>

#define SPACE_KEYCODE 49
#define I_KEYCODE 34
#define S_KEYCODE 1
#define D_KEYCODE 2
#define R_KEYCODE 15
#define ESC_KEYCODE 53
#define ARROW_LEFT 123
#define ARROW_RIGHT 124
#define ARROW_DOWN 125
#define ARROW_UP 126

void	ft_change_color(t_data *data)
{
	static int	colors[] = {
		0x88C1FA,
		0xD9D821,
		0x071a52,
		0xfc5185,
		0x6e3b3b,
		0x071e3d,
		0x3b5441,
		0x226089,
		0x660077,
		0x581b98
	};
	static int	color_index = 0;

	data->color = colors[color_index++ % (sizeof(colors) / 4)];
	ft_render(data);
}

void	ft_change_set(t_data *data)
{
	static void	*sets[] = {
		ft_mandelbrot_iterate,
		ft_burning_ship_iterate,
		ft_julia_set_iterate
	};
	static int	set_index = 0;

	data->iterate = sets[set_index++ % (sizeof(sets) / 8)];
	ft_render(data);
}

void	ft_reset(t_data *data)
{
	data->zoom = 2;
	data->origin = (t_coordinates){0, 0};
	data->max_iterations = 50;
	data->julia_data = (t_coordinates){-0.70176, -0.3842};
	data->julia_set_live = 0;
	ft_render(data);
}

void	ft_move(int keycode, t_data *data)
{
	if (keycode == ARROW_DOWN)
		data->origin.b += data->zoom / 10;
	else if (keycode == ARROW_UP)
		data->origin.b -= data->zoom / 10;
	else if (keycode == ARROW_LEFT)
		data->origin.a -= data->zoom / 10;
	else if (keycode == ARROW_RIGHT)
		data->origin.a += data->zoom / 10;
	ft_render(data);
}

int	ft_on_key_down(int keycode, t_data *data)
{
	if (keycode == SPACE_KEYCODE)
		ft_change_color(data);
	if (keycode == R_KEYCODE)
		ft_reset(data);
	if (keycode == I_KEYCODE)
	{
		data->max_iterations += 50;
		ft_render(data);
	}
	if (keycode == S_KEYCODE)
		ft_change_set(data);
	if (keycode == D_KEYCODE)
	{
		if (data->max_iterations - 50 >= 50)
			data->max_iterations -= 50;
		ft_render(data);
	}
	if (keycode >= ARROW_LEFT && keycode <= ARROW_UP)
		ft_move(keycode, data);
	if (keycode == ESC_KEYCODE)
		exit(0);
	return (0);
}
