# include "so_long.h"
# include "get_next_line.h"

void	init(t_data *img)
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
        char **sp;

        j = 0;
        check_par(argv[1]);
        map(argv[1]);
        sp = ft_split(map(argv[1]),'\n');
        free(map(argv[1]));
        compa = check_fl(sp);
        j++;
        j = check_mid(sp,compa,j,&img);
        check_last(sp,compa,j);
        every_thing_ok(sp,img.for_c,j);
        exit(1);
    }
    printf("invalid argment\n");
    return 0;
}
