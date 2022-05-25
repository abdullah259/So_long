#include "so_long.h"

void    check_last(t_data *img,int comp,int j)
{
	int g;

	g = 0;
	while (img->map[j][g])
	{
		if (img->map[j][g] != '1')
		{
				write(1,"ERROR PLEASE FIrst line\n",24);
				free_sp(img->map);
				exit(1);
		}
		g++;
	}
	if (g != comp)
	{
			write(1,"Lines are not equal each other\n",31);
			free_sp(img->map);
			exit(1);
	}
}