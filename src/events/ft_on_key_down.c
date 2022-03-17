/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_on_key_down.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:18:38 by mzarhou           #+#    #+#             */
/*   Updated: 2022/03/17 01:12:52 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"
#include "events/events.h"
#include "sets/sets.h"

#define SPACE_KEYCODE 49
#define I_KEYCODE 34
#define S_KEYCODE 1
#define D_KEYCODE 2

void	ft_change_color(t_data *data)
{
	static int	colors[] = {
		0x26FC49,
		0x88C1FA,
		0xD9D821,
		0x26FCB0
	};
	static int	color_index = 0;

	data->color = colors[color_index++ % (sizeof(colors) / 4)];
	ft_render(data);
}

void	ft_change_set(t_data *data)
{
	static void	*sets[] = {
		ft_mandelbrot_iterate,
		ft_julia_set_iterate
	};
	static int	set_index = 0;

	data->iterate = sets[set_index++ % (sizeof(sets) / 8)];
	ft_render(data);
}

int	ft_on_key_down(int keycode, t_data *data)
{
	if (keycode == SPACE_KEYCODE)
		ft_change_color(data);
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
	return (0);
}
