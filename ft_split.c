/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghazi <aghazi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:53:04 by aghazi            #+#    #+#             */
/*   Updated: 2022/05/26 17:24:24 by aghazi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "so_long.h"
#include "get_next_line.h"

void	check(char s, char c, char s1,int *x)
{
	if (s == c && s1 == c)
	{
		write(1, "There is two newline\n", 21);
        
		*x = 2;
	}
	if (s == c && s1 == '\0')
	{
		write(1, "error newline then null\n", 24);
		*x = 2;
	}
}

static	int	word_count(char *s, char c, int *x)
{
	int	i;
	int	w;
	int	j;

	j = 0;
	w = 0;
	i = 0;
	if (*s == '\0')
		return (0);
	while (s[i])
	{
		if (s[i] != c && w == 0)
		{
			w = 1;
			j++;
		}
		else if (s[i] == c)
			w = 0;
		check(s[i], c, s[i + 1],x);
		i++;
	}
	return (j);
}

static	int	length_str(char *s, char c, int start)
{
	int	i;

	i = 0;
	while (s[i + start])
	{
		if (s[i + start] == c)
			return (i);
		i++;
	}
	return (i);
}
char    **fill_str(char *s, char c, int i, char **ptr)
{
    int j;
    int k;

    j = 0;
    k = 0;
	while (s[i])
	{
		ptr[j] = malloc((length_str((char *)s, c, i) + 1) * sizeof(char));
		k = 0;
		while (s[i] != c && s[i])
		{
			ptr[j][k] = s[i];
			i++;
			k++;
		}
		ptr[j][k] = '\0';
		j++;
		while (s[i] == c)
			i++;
	}
	ptr[j] = NULL;
    return (ptr);
}
char	**ft_split(char const *s, char c, int *x)
{
	char	**ptr;
	int		i;
	// int		j;
	// int		k;

	// k = 0;
	// j = 0;
	i = 0;
	ptr = malloc((word_count((char *)s, c,x) + 1) * sizeof(char *));
	if (!ptr)
		return (NULL);
	while (s[i] == c)
		i++;
    ptr = fill_str((char*)s, c, i, ptr);
	return (ptr);
}
