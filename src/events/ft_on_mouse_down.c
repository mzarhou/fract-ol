/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_on_mouse_down.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:05:04 by mzarhou           #+#    #+#             */
/*   Updated: 2022/03/16 20:18:12 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events/events.h"
#include "utils/utils.h"
#include <stdio.h>
#include <mlx.h>
#include "fract_ol.h"

int isRendering = 0;

int	ft_on_mouse_down(int keycode, int x, int y, t_data *data)
{
	// static	int	colors[] = {
	// 	0x26FC49,
	// 	0x88C1FA,
	// 	0xD9D821,
	// 	0x26FCB0
	// };

	y = x;
	if (isRendering)
		return 0;
	isRendering = 1;
	printf("ft_on_mouse_down %d\n", keycode);
	printf("ft_on_mouse_down > zoom %lf\n", data->zoom);
	if (keycode == 5) {
		data->zoom -= data->zoom / 10;
		ft_render(data);
	} else if (keycode == 4) {
		data->zoom += data->zoom / 10;
		ft_render(data);
	}
	isRendering = 0;
	return (0);
}
