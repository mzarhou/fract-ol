/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:05:19 by mzarhou           #+#    #+#             */
/*   Updated: 2022/03/17 02:47:27 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H
# include "fract_ol.h"

enum e_EVENTS
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};
int		ft_on_destroy(void);
int		ft_on_mouse_down(int keycode, int x, int y, t_data *data);
int		ft_on_key_down(int keycode, t_data *data);
int		ft_on_mouse_move(int x, int y, t_data *data);
void	ft_register_events(t_data *data);
#endif
