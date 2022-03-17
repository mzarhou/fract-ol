/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 02:52:40 by mzarhou           #+#    #+#             */
/*   Updated: 2022/03/17 02:53:08 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils.h"

double	ft_map(double value, t_interval from, t_interval to)
{
	return (
		to.start + (
			(value - from.start) * (to.end - to.start)
			/ (from.end - from.start))
	);
}
