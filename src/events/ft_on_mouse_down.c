/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_on_mouse_down.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:05:04 by mzarhou           #+#    #+#             */
/*   Updated: 2022/03/17 18:53:51 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events/events.h"
#include "utils/utils.h"
#include <mlx.h>
#include "sets/sets.h"
#include "fract_ol.h"

void	ft_toggle_julia_set_liv_mode(t_data *data)
{
	if (data->iterate != ft_julia_set_iterate)
		return ;
	if (data->julia_set_live == 1)
		data->julia_set_live = 0;
	else
		data->julia_set_live = 1;
}

void	ft_set_origin(int x, int y, t_data *data)
{
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
}

int	ft_on_mouse_down(int keycode, int x, int y, t_data *data)
{
	if (keycode != 1 && keycode != 4 && keycode != 5)
		return (0);
	if (keycode == 1)
		ft_toggle_julia_set_liv_mode(data);
	else
	{
		ft_set_origin(x, y, data);
		if (keycode == 5)
			data->zoom -= data->zoom / 10;
		else
			data->zoom += data->zoom / 10;
	}
	ft_render(data);
	return (0);
}
