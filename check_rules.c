/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rules.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghazi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:14:27 by aghazi            #+#    #+#             */
/*   Updated: 2022/05/24 15:20:58 by aghazi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_c_p_e(t_data *img)
{
	if (img->for_c <= 0)
	{
		write(1, "Error, : You have to have at least one collection.\n", 51);
		free_sp(img->map);
		exit(1);
	}
	if (img->e != 1)
	{
		write(1, "Error, : You have to have at least one Exit.\n", 45);
		free_sp(img->map);
		exit(1);
	}
	if (img->p != 1)
	{
		write(1, "Error, : You have to have at least one player.\n", 47);
		free_sp(img->map);
		exit(1);
	}
}
