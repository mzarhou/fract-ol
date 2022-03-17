/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_on_mouse_down.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:05:04 by mzarhou           #+#    #+#             */
/*   Updated: 2022/03/17 03:34:03 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events/events.h"
#include "utils/utils.h"
#include <mlx.h>
#include "fract_ol.h"

int	ft_on_mouse_down(int keycode, int x, int y, t_data *data)
{
	if (keycode < 4)
		return (0);
	data->origin.a = ft_map(
			x,
			(t_interval){0, data->win_width},
			(t_interval){
			data->origin.a - (data->zoom * 0.128),
			data->origin.a + (data->zoom * 0.128)
		});
	data->origin.b = ft_map(y,
			(t_interval){0, data->win_height},
			(t_interval){
			data->origin.b - (data->zoom * 0.128),
			data->origin.b + (data->zoom * 0.128)
		});
	if (keycode == 5)
		data->zoom -= data->zoom / 10;
	else
		data->zoom += data->zoom / 10;
	ft_render(data);
	return (0);
}
