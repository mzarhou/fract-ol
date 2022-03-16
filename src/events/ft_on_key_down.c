/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_on_key_down.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:18:38 by mzarhou           #+#    #+#             */
/*   Updated: 2022/03/16 20:55:30 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"
#include "events/events.h"
#include <stdio.h>

int	ft_on_key_down(int keycode, t_data *data)
{
	static int	colors[] = {
		0x26FC49,
		0x88C1FA,
		0xD9D821,
		0x26FCB0
	};
	static int	color_index = 0;

	if (keycode == 49)
	{
		data->color = colors[color_index++ % (sizeof(colors) / 4)];
		ft_render(data);
	}
	return (0);
}
