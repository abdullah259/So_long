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

int	check_fl(t_data *img)
{
	int	j;
	int	g;
	int	comp;

	comp = 0;
	j = 0;
	g = 0;
	while (img->map[j][g])
	{
		if (img->map[j][g] != '1')
		{
			write(1, "invalid argment\n", 16);
			free_sp(img->map);
			exit(1);
		}
		g++;
	}
	comp = g;
	return (comp);
}
