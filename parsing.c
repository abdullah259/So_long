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

void	empty_str(char s1)
{
	if (s1 == '\0')
	{
		write(1, "invaild ag empty\n", 17);
		exit(0);
	}
}

void	check_par(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '.')
		{
			if (i == 0)
			{
				write(1, "invaild ag\n", 11);
				exit(0);
			}
			i++;
			if (s[i] == 'b' && s[i + 1] == 'e' && s[i + 2] == 'r'
				&& s[i + 3] == '\0')
				break ;
			else
			{
				write(1, "invaild ag\n", 11);
				exit(0);
			}
		}
		i++;
	}
	empty_str(s[i]);
}
