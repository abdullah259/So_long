#include "so_long.h"
#include "get_next_line.h"

void	ft_init(t_data *img)
{
	img->check_exit = 0;
	img->for_c = 0;
	img->e = 0;
	img->p = 0;
	img->i = 0;
	img->movix = 0;
	img->moviy = 0;
	img->x = 0;
	img->y = 0;
	img->img_wid = 0;
	img->img_hei = 0;
	img->steps = 0;
}

int main(int arc,char **argv)
{
	if (arc == 2)
	{
		t_data img;
		int j;
		int compa;
		char *tmp;
		ft_init(&img);

		j = 0;
		check_par(argv[1]);
		tmp = map(argv[1]);
		if (!tmp)
			return (0);
		img.map = ft_split(map(argv[1]),'\n');
		free(tmp);
		compa = check_fl(&img);
		j++;
		j = check_mid(compa,j,&img);
		check_last(&img, compa,j);
		every_thing_ok(&img,img.for_c,j);
		exit(1);
	}
	printf("invalid argment\n");
	return 0;
}
