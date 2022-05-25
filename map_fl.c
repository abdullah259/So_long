#include "so_long.h"

int     check_fl(char **sp)
{
	int j;
	int g;
	int comp;

	comp = 0;
	j = 0;
	g = 0;
	while (sp[j][g])
	{
		if (sp[j][g] != '1')
		{
			// write(1,"ERROR PLEASE FL\n",16);
			write(1,"invalid argment\n",16);
			exit(1);
		}
		g++;
	}
	comp = g;
	return (comp);
}