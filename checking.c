/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghazi <aghazi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 16:25:36 by aghazi            #+#    #+#             */
/*   Updated: 2022/05/24 18:42:17 by aghazi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_c(char c, char val, t_data *img)
{
	mlx_put_image_to_window(img->mlx, img->mlx_win,
		img->img_bg, img->movix, img->moviy);
	if (c == '-' && val == 'y')
		img->map[(img->moviy -60) / 60][(img->movix) / 60] = '0';
	else if (c == '+' && val == 'y')
		img->map[(img->moviy + 60) / 60][(img->movix) / 60] = '0';
	if (c == '-' && val == 'x')
		img->map[(img->moviy) / 60][(img->movix - 60) / 60] = '0';
	else if (c == '+' && val == 'x')
		img->map[(img->moviy) / 60][(img->movix + 60) / 60] = '0';
	if (c == '-' && val == 'y')
		img->moviy -= 60;
	else if (c == '+' && val == 'y')
		img->moviy += 60;
	if (c == '-' && val == 'x')
		img->movix -= 60;
	else if (c == '+' && val == 'x')
		img->movix += 60;
	mlx_put_image_to_window(img->mlx, img->mlx_win,
		img->img_bg, img->movix, img->moviy);
	mlx_put_image_to_window(img->mlx, img->mlx_win,
		img->img_pl, img->movix, img->moviy);
	img->check_exit++;
	img->steps++;
	ft_putnbr(img->steps);
}

void	check_exit(char e, char val, t_data *img)
{
	int	p;

	p = img->i;
	mlx_put_image_to_window(img->mlx, img->mlx_win,
		img->img_bg, img->movix, img->moviy);
	if (e == '-' && val == 'y')
		img->moviy -= 60;
	else if (e == '+' && val == 'y')
		img->moviy += 60;
	if (e == '-' && val == 'x')
		img->movix -= 60;
	else if (e == '+' && val == 'x')
		img->movix += 60;
	img->steps++;
	destroy(img);
	while (p >= 0)
	{
		free(img->map[p]);
		p--;
	}
	free(img->map);
	exit(0);
}

void	check_bg(char b, char val, t_data *img)
{
	mlx_put_image_to_window(img->mlx, img->mlx_win,
		img->img_bg, img->movix, img->moviy);
	if (b == '-' && val == 'y')
		img->moviy -= 60;
	else if (b == '+' && val == 'y')
		img->moviy += 60;
	if (b == '-' && val == 'x')
		img->movix -= 60;
	else if (b == '+' && val == 'x')
		img->movix += 60;
	mlx_put_image_to_window(img->mlx, img->mlx_win,
		img->img_pl, img->movix, img->moviy);
	img->steps++;
	ft_putnbr(img->steps);
	write(1, "\n", 1);
}
