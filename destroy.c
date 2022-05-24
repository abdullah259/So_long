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

void	destroy(t_data *img)
{
	mlx_destroy_image(img->mlx, img->img_wall);
	mlx_destroy_image(img->mlx, img->img_bg);
	mlx_destroy_image(img->mlx, img->img_coll);
	mlx_destroy_image(img->mlx, img->img_ex);
	mlx_destroy_image(img->mlx, img->img_pl);
	mlx_destroy_window(img->mlx, img->mlx_win);
}
