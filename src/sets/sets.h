/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 23:25:48 by mzarhou           #+#    #+#             */
/*   Updated: 2022/03/17 19:09:35 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETS_H
# define SETS_H
# include "fract_ol.h"

int	ft_mandelbrot_iterate(const double maped_a,
		const double maped_b, const t_data *data);
int	ft_julia_set_iterate(const double maped_a,
		const double maped_b, const t_data *data);
int	ft_burning_ship_iterate(const double maped_a,
		const double maped_b, const t_data *data);

#endif
