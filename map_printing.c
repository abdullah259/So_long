#include "so_long.h"

void	printing(char a,t_data *img)
{
	if (a == '1')
		mlx_put_image_to_window(img->mlx,img->mlx_win,img->img_wall,img->x,img->y);
	if (a == '0')
		mlx_put_image_to_window(img->mlx,img->mlx_win,img->img_bg,img->x,img->y);
	if (a == 'C')
	{
		mlx_put_image_to_window(img->mlx,img->mlx_win,img->img_bg,img->x,img->y);
		mlx_put_image_to_window(img->mlx,img->mlx_win,img->img_coll,img->x,img->y);
	}
	if (a == 'E')
	{
		mlx_put_image_to_window(img->mlx,img->mlx_win,img->img_bg,img->x,img->y);
		mlx_put_image_to_window(img->mlx,img->mlx_win,img->img_ex,img->x,img->y);
	}
	if (a == 'P')
	{
		img->movix = img->x;
		img->moviy = img->y;
		mlx_put_image_to_window(img->mlx,img->mlx_win,img->img_bg,img->x,img->y);
		mlx_put_image_to_window(img->mlx,img->mlx_win,img->img_pl,img->x,img->y);
	}
}

void	print_map(t_data *img)
{
	int i;
	int y;

	img->x = 0;
	img->y = 0;
	i = 0;
	y = 0;
	while (img->map[i])
	{
		y = 0;
		img->x = 0;
		while (img->map[i][y])
		{
			printing(img->map[i][y],img);
			y++;
			img->x += 60;
		}
		i++;
		img->y += 60;
	}
}