/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghazi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:47:04 by aghazi            #+#    #+#             */
/*   Updated: 2022/05/24 18:48:17 by aghazi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_x_c(char c, t_data *img)
{
	if (c == '-')
	{
		check_c('-', 'x', img);
		write(1, "\n", 1);
	}
	if (c == '+')
	{
		check_c('+', 'x', img);
		write(1, "\n", 1);
	}
}

void	move_y_c(char c, t_data *img)
{
	if (c == '-')
	{
		check_c('-', 'y', img);
		write(1, "\n", 1);
	}
	if (c == '+')
	{
		check_c('+', 'y', img);
		write(1, "\n", 1);
	}
}

void	move_y(char c, t_data *img)
{
	if (c == '-')
	{
		if (img->map[(img->moviy - 60) / 60][(img->movix) / 60] == 'C')
			move_y_c('-', img);
		else if (img->map[(img->moviy - 60) / 60][(img->movix) / 60] == 'E' &&
				img->check_exit == img->for_c)
			check_exit('-', 'y', img);
		else if (!(img->map[(img->moviy - 60) / 60][(img->movix) / 60] == '1')
				&&
				!(img->map[(img->moviy - 60) / 60][(img->movix) / 60] == 'E'))
			check_bg('-', 'y', img);
	}
	if (c == '+')
	{
		if (img->map[(img->moviy + 60) / 60][(img->movix) / 60] == 'C')
			move_y_c('+', img);
		else if (img->map[(img->moviy + 60) / 60][(img->movix) / 60] == 'E' &&
				img->check_exit == img->for_c)
			check_exit('+', 'y', img);
		else if (!(img->map[(img->moviy + 60) / 60][(img->movix) / 60] == '1')
				&&
				!(img->map[(img->moviy + 60) / 60][(img->movix) / 60] == 'E'))
			check_bg('+', 'y', img);
	}
}

void	move_x(char c, t_data *img)
{
	if (c == '-')
	{
		if (img->map[(img->moviy) / 60][(img->movix - 60) / 60] == 'C')
			move_x_c('-', img);
		else if (img->map[(img->moviy) / 60][(img->movix - 60) / 60] == 'E' &&
				img->check_exit == img->for_c)
			check_exit('-', 'x', img);
		else if (!(img->map[img->moviy / 60][(img->movix - 60) / 60] == '1')
				&&
				!(img->map[img->moviy / 60][(img->movix - 60) / 60] == 'E'))
			check_bg('-', 'x', img);
	}
	if (c == '+')
	{
		if (img->map[(img->moviy) / 60][(img->movix + 60) / 60] == 'C')
			move_x_c('+', img);
		else if (img->map[(img->moviy) / 60][(img->movix + 60) / 60] == 'E' &&
				img->check_exit == img->for_c)
			check_exit('+', 'x', img);
		else if (!(img->map[img->moviy / 60][(img->movix + 60) / 60] == '1')
				&&
				!(img->map[img->moviy / 60][(img->movix + 60) / 60] == 'E'))
			check_bg('+', 'x', img);
	}
}
