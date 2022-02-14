/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_on_mouse_up.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:07:18 by mzarhou           #+#    #+#             */
/*   Updated: 2022/02/14 18:19:13 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "events/events.h"

int	ft_on_mouse_up(int keycode, void *data)
{
	data = NULL;
	printf("%s %d\n", "mouse up - ", keycode);
	return (0);
}
