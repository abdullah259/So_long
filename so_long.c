#include "mlx.h"
#include "so_long.h"
#include <math.h>
#include <unistd.h>
#include <stdio.h>

int	ft_douAlen(char **s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return(i);
}

int	ft_esc(t_data *img)
{
	int p;

	p = img->i;
	mlx_destroy_image(img->mlx,img->img_wall);
	mlx_destroy_image(img->mlx,img->img_bg);
	mlx_destroy_image(img->mlx,img->img_coll);
	mlx_destroy_image(img->mlx,img->img_ex);
	mlx_destroy_image(img->mlx,img->img_pl);
	mlx_destroy_window(img->mlx,img->mlx_win);
	while (p >= 0)
	{
		free(img->map[p]);
		p--;
	}
	free(img->map);
	exit(0);
	return (0);
}

int		ft_close(void	*ptr)
{
	t_data	*img;
	int p;

	img = (void *)ptr;
	p = img->i;
	mlx_destroy_image(img->mlx,img->img_wall);
	mlx_destroy_image(img->mlx,img->img_bg);
	mlx_destroy_image(img->mlx,img->img_coll);
	mlx_destroy_image(img->mlx,img->img_ex);
	mlx_destroy_image(img->mlx,img->img_pl);
	mlx_destroy_window(img->mlx,img->mlx_win);
	while (p >= 0)
	{
		free(img->map[p]);
		p--;
	}
	free(img->map);
	exit(0);
	return (0);
}

int 	forKeyHook(int keycode,t_data *img)
{
	if (keycode == 13)//w
		move_y('-',img);
	if (keycode == 0)//a
		move_x('-',img);
	if (keycode == 1)//s
		move_y('+',img);
	if (keycode == 2)//d 
		move_x('+',img);
	if (keycode == 53)
		ft_esc(img);
	return (0);
}

char 	**every_thing_ok(char **sp, int for_c, int j)
{
	t_data	img;
	int	width;
	int height;

	width = 0;
	height = 0;
	img.steps = 0;
	img.check_exit = 0;
	img.for_c = for_c;
	img.i = j;
	img.mlx = mlx_init();
	width = ft_strlen(sp[0]) * 60;
	height = ft_douAlen(sp) * 60;
	img.mlx_win = mlx_new_window(img.mlx, width, height, "Hello world");
	mlx_hook(img.mlx_win, 17, 0,ft_close,&img);
	img.img_pl = mlx_xpm_file_to_image(img.mlx,"./images/luigi.xpm",&img.img_wid,&img.img_hei);
	img.img_wall = mlx_xpm_file_to_image(img.mlx,"./images/wall.xpm",&img.img_wid,&img.img_hei);
	img.img_coll = mlx_xpm_file_to_image(img.mlx,"./images/collect.xpm",&img.img_wid,&img.img_hei);
	img.img_bg = mlx_xpm_file_to_image(img.mlx,"./images/bg.xpm",&img.img_wid,&img.img_hei);
	img.img_ex = mlx_xpm_file_to_image(img.mlx,"./images/exit.xpm",&img.img_wid,&img.img_hei);
	img.map = sp;
	print_map(&img);
	mlx_key_hook(img.mlx_win,forKeyHook,&img);
	mlx_loop(img.mlx);
	return(sp);
}
