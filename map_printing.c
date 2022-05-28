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

void	print_player(char a, t_data *img)
{
	if (a == 'P')
	{
		img->movix = img->x;
		img->moviy = img->y;
		mlx_put_image_to_window(img->mlx, img->mlx_win,
			img->img_bg, img->x, img->y);
		mlx_put_image_to_window(img->mlx, img->mlx_win,
			img->img_pl, img->x, img->y);
	}
}

void	printing(char a, t_data *img)
{
	if (a == '1')
		mlx_put_image_to_window(img->mlx, img->mlx_win,
			img->img_wall, img->x, img->y);
	if (a == '0')
		mlx_put_image_to_window(img->mlx, img->mlx_win,
			img->img_bg, img->x, img->y);
	if (a == 'C')
	{
		mlx_put_image_to_window(img->mlx, img->mlx_win,
			img->img_bg, img->x, img->y);
		mlx_put_image_to_window(img->mlx, img->mlx_win,
			img->img_coll, img->x, img->y);
	}
	if (a == 'E')
	{
		mlx_put_image_to_window(img->mlx, img->mlx_win,
			img->img_bg, img->x, img->y);
		mlx_put_image_to_window(img->mlx, img->mlx_win,
			img->img_ex, img->x, img->y);
	}
	print_player(a, img);
}

void	print_map(t_data *img)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (img->map[i])
	{
		y = 0;
		img->x = 0;
		while (img->map[i][y])
		{
			printing(img->map[i][y], img);
			y++;
			img->x += 60;
		}
		i++;
		img->y += 60;
	}
}
