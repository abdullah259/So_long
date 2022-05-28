/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghazi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:48:46 by aghazi            #+#    #+#             */
/*   Updated: 2022/05/24 18:50:35 by aghazi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*map(char *argv)
{
	int		fd;
	char	*new;
	char	*s;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (NULL);
	new = ft_strdup("");
	s = get_next_line(fd);
	while (s)
	{
		new = ft_strjoin(new, s);
		free(s);
		s = get_next_line (fd);
	}
	return (new);
}
