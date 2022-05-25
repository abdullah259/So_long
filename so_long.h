#ifndef SO_LONG_H
# define SO_LONG_H

#include "mlx.h"
# include "get_next_line.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# define black "\033[0;30m"
# define red "\033[0;31m"
# define green "\033[0;32m"
# define yellow "\033[0;33m"
# define blue "\033[0;34m"
# define purple "\033[0;35m"
# define cyan "\033[0;36m"
# define white "\033[0;37m"

typedef struct	s_data {
	void	*mlx_win;
	void	*mlx;
	int		steps;
	void	*img_ex;
	void	*img_pl;
	void	*img_coll;
	void	*img_wall;
	void	*img_bg;
	int		img_wid;
	int		img_hei;
	int		x;
	int		y;
	int		movix;
	int		moviy;
	char	**map;
	int		check_exit;
	int		for_c;
	int		e;
	int		p;
	int		i;
}	t_data;
void 	every_thing_ok(t_data *img,int for_c, int j);
char    **ft_split(char const *s, char c);
void    check_par(char *s);
int     check_fl(t_data *img);
int    check_mid(int compa,int j,t_data *img);
void    check_last(t_data *img,int comp,int j);
char    *map(char *argv);
void	move_y(char c, t_data *img);
void	move_x(char c, t_data *img);
void	check_c(char c , char val, t_data *img);
void	check_exit(char e, char val , t_data *img);
void	check_bg(char b, char val,t_data *img);
void	printing(char a,t_data *img);
void	print_map(t_data *img);
void 	ft_putnbr(int n);
void	check_c_p_e(t_data *img);
void    destroy(t_data *img);
void	free_sp(char **s);
#endif