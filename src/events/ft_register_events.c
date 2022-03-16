/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_register_events.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:42:30 by mzarhou           #+#    #+#             */
/*   Updated: 2022/03/16 20:03:18 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events/events.h"
#include <stdio.h>
#include <mlx.h>

void	ft_register_events(t_data *data)
{
	mlx_hook(data->win_ptr, ON_MOUSEDOWN, 0, ft_on_mouse_down, data);
	mlx_hook(data->win_ptr, ON_MOUSEUP, 0, ft_on_mouse_up, data);
	mlx_hook(data->win_ptr, ON_DESTROY, 0, ft_on_destroy, NULL);
}
