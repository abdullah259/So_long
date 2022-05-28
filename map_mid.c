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

void	check_cpe(char c, t_data *img)
{
	if (c == 'C')
		img->for_c++;
	if (c == 'E')
		img->e++;
	if (c == 'P')
		img->p++;
}

void	check_alph(char c, char c1, t_data *img)
{
	if (c1 != '1')
	{
		write(1, "ERROR LINE LINES FIRST\n", 23);
		free_sp(img->map);
		exit(1);
	}
	if (c != '1' && c != '0' && c != 'C' && c != 'P' && c != 'E')
	{
		write(1, "there is alphabet not valid\n", 28);
		free_sp(img->map);
		exit(1);
	}
}

void	check_lines(int g, int compa, t_data *img)
{
	if (g != compa)
	{
		write(1, "Lines are not equal each other\n", 31);
		free_sp(img->map);
		exit(1);
	}
}

int	check_mid(int compa, int j, t_data *img)
{
	int	g;

	while (img->map[j] && img->map[j + 1] != NULL)
	{
		g = 0;
		while (img->map[j][g])
		{
			check_alph(img->map[j][g], img->map[j][0], img);
			if (img->map[j][g + 1] == '\0')
			{
				if (img->map[j][g] != '1')
				{
					write(1, "ERROR LINE LINES LAST\n", 22);
					free_sp(img->map);
					exit(1);
				}
			}
			check_cpe(img->map[j][g], img);
			g++;
		}
		check_lines(g, compa, img);
		j++;
	}
	check_c_p_e(img);
	return (j);
}
