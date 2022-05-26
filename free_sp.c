#include "so_long.h"

void	free_sp(char **s)
{
	int	p;

	p = 0;
	while (s[p])
	{
		free(s[p]);
		p++;
	}
	free(s);
	exit(0);
}