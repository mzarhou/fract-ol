/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:28:46 by mzarhou           #+#    #+#             */
/*   Updated: 2022/03/17 20:12:04 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "fract_ol.h"
#include "events/events.h"
#include "utils/utils.h"
#include "unistd.h"
#include "sets/sets.h"
#include <mlx.h>

void	ft_render(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	while (++i < data->win_width)
	{
		j = -1;
		while (++j < data->win_height)
		{
			ft_pixel_coloring(i, j, data);
		}
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.ptr, 0, 0);
}

void	ft_init_data(t_data *data)
{
	data->win_width = 600;
	data->win_height = 600;
	data->zoom = 2;
	data->origin = (t_coordinates){0, 0};
	data->max_iterations = 50;
	data->iterate = &ft_julia_set_iterate;
	data->color = 0x581b98;
	data->julia_data = (t_coordinates){-0.70176, -0.3842};
	data->julia_set_live = 0;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->win_width,
			data->win_height, "FRACT-OL");
	data->img.ptr = mlx_new_image(data->mlx_ptr,
			data->win_width, data->win_height);
	data->img.pixels = mlx_get_data_addr(
			data->img.ptr, &data->img.bits_per_pixel, &data->img.line_length,
			&data->img.endian
			);
}

void	ft_exit(void)
{
	write(1, "\n\n\n", 4);
	write(1, "1 - julia set\n", 15);
	write(1, "2 - mandelbrot\n", 16);
	write(1, "3 - burning ship\n", 18);
	write(1, "\n\n\n", 4);
	exit(0);
}

void	ft_selet_fractol(t_data *data, char *option_str)
{
	int	option;

	option = ft_atoi(option_str);
	if (option == 1)
		data->iterate = &ft_julia_set_iterate;
	else if (option == 2)
		data->iterate = &ft_mandelbrot_iterate;
	else if (option == 3)
		data->iterate = &ft_burning_ship_iterate;
	else
		ft_exit();
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2)
		ft_exit();
	ft_init_data(&data);
	ft_selet_fractol(&data, argv[1]);
	ft_register_events(&data);
	ft_render(&data);
	mlx_loop(data.mlx_ptr);
}
