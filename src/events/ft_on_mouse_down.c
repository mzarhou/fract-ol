/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_on_mouse_down.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:05:04 by mzarhou           #+#    #+#             */
/*   Updated: 2022/03/13 21:51:55 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events/events.h"
#include "utils/utils.h"
#include <stdio.h>
#include <mlx.h>

int	ft_on_mouse_down(int keycode, t_data *data)
{
	printf("ft_on_mouse_down %d\n", keycode);
	if (keycode == 5) {
		data->zoom = 1;
		ft_new_image(data, &ft_fill_img);
	}
	return (0);
}
