/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:11:20 by mzarhou           #+#    #+#             */
/*   Updated: 2022/02/14 18:46:19 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../fract_ol.h"

void	ft_new_image(void *mlx, t_img *img, int win_height, int win_width);
void	ft_mlx_pixel_put(t_img *img, int x, int y, int color);
void	ft_fill_img(t_img *img, int height, int width, int color);

#endif
