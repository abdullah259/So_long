#include "so_long.h"

void    check_cpe(char c,t_data *img)
{
	if (c == 'C')
		img->for_c++;
	if (c == 'E')
		img->e++;
	if (c == 'P')
		img->p++; 
}

void    check_alph(char c,char c1)
{
	if(c1 != '1')
	{
		write(1,"ERROR LINE LINES FIRST\n",23);
		exit(1);
	}
	if(c != '1' && c != '0' && c != 'C' && c != 'P' && c != 'E')
	{
		write(1,"there is alphabet not valid\n",28);
		exit(1);
	}
	
}

void    check_lines(int g, int compa)
{
	if (g != compa)
	{
		printf("Lines are not equal each other\n");
		exit(1);
	}
}

int    check_mid(char **sp, int compa,int j, t_data *img)
{
	int g;

	while (sp[j] && sp[j+1] != NULL)
	{       
		g = 0;
		while (sp[j][g])
		{
			check_alph(sp[j][g],sp[j][0]);
			if (sp[j][g + 1] == '\0')
			{
				if (sp[j][g] != '1')
				{
					write(1,"ERROR LINE LINES LAST\n",22);
					exit(1);
				}
			}
			check_cpe(sp[j][g],img);   
			g++;
		}
		check_lines(g,compa);
		j++;
	}
	check_c_p_e(img);
	return (j);
}