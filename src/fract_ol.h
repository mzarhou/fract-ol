/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:10:05 by mzarhou           #+#    #+#             */
/*   Updated: 2022/03/17 03:27:44 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

typedef struct s_img
{
	void	*ptr;
	char	*pixels;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_coordinates
{
	double	a;
	double	b;
}	t_coordinates;

typedef struct s_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_img			img;
	double			win_height;
	double			win_width;
	double			zoom;
	t_coordinates	origin;
	int				color;
	int				max_iterations;
	int				(*iterate)(
			const double maped_x,
			const double maped_y,
			const struct s_data *data
			);
}	t_data;

void	ft_render(t_data *data);

#endif
