/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_on_mouse_move.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 02:45:58 by mzarhou           #+#    #+#             */
/*   Updated: 2022/03/17 02:56:46 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events/events.h"
#include "utils/utils.h"
#include "printf.h"

int	ft_on_mouse_move(int x, int y, t_data *data)
{
	double	maped_x;
	double	maped_y;

	if (x < 0 || x > data->win_width || y < 0 || y > data->win_height)
		return (0);
	maped_x = ft_map(x, (t_interval){0, data->win_width}, (t_interval){-1, 1});
	maped_y = ft_map(y, (t_interval){0, data->win_height}, (t_interval){-1, 1});
	// Todo: use these mapped value to render a new julia set
	return 0;
}