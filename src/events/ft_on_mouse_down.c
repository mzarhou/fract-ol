/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_on_mouse_down.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:05:04 by mzarhou           #+#    #+#             */
/*   Updated: 2022/02/14 18:18:52 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events/events.h"
#include <stdio.h>

int	ft_on_mouse_down(int keycode, void *data)
{
	data = NULL;
	printf("%s %d\n", "mouse down - ", keycode);
	return (0);
}
