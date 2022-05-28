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

int	ft_doualen(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_esc(t_data *img)
{
	int	p;

	p = img->i;
	destroy(img);
	while (p >= 0)
	{
		free(img->map[p]);
		p--;
	}
	free(img->map);
	exit(0);
	return (0);
}

int	ft_close(t_data *img)
{
	int	p;

	p = img->i;
	destroy(img);
	while (p >= 0)
	{
		free(img->map[p]);
		p--;
	}
	free(img->map);
	exit(0);
	return (0);
}

int	for_key_hook(int keycode, t_data *img)
{
	if (keycode == 13)
		move_y ('-', img);
	if (keycode == 0)
		move_x ('-', img);
	if (keycode == 1)
		move_y ('+', img);
	if (keycode == 2)
		move_x ('+', img);
	if (keycode == 53)
		ft_esc (img);
	return (0);
}

void	every_thing_ok(t_data *img, int for_c, int j)
{
	int	width;
	int	height;

	width = 0;
	height = 0;
	img->for_c = for_c;
	img->i = j;
	img->mlx = mlx_init();
	width = ft_strlen(img->map[0]) * 60;
	height = ft_doualen(img->map) * 60;
	img->mlx_win = mlx_new_window(img->mlx, width, height, "Hello world");
	mlx_hook(img->mlx_win, 17, 0, ft_close, img);
	img->img_pl = mlx_xpm_file_to_image(img->mlx, "./images/luigi.xpm",
			&img->img_wid, &img->img_hei);
	img->img_wall = mlx_xpm_file_to_image(img->mlx, "./images/wall.xpm",
			&img->img_wid, &img->img_hei);
	img->img_coll = mlx_xpm_file_to_image(img->mlx, "./images/collect.xpm",
			&img->img_wid, &img->img_hei);
	img->img_bg = mlx_xpm_file_to_image(img->mlx, "./images/bg.xpm",
			&img->img_wid, &img->img_hei);
	img->img_ex = mlx_xpm_file_to_image(img->mlx, "./images/exit.xpm",
			&img->img_wid, &img->img_hei);
	print_map(img);
	mlx_key_hook(img->mlx_win, for_key_hook, img);
	mlx_loop(img->mlx);
}
