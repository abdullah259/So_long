# include "so_long.h"

void    check_last(char **sp, int comp,int j)
{
    int g;

    g = 0;
    while (sp[j][g])
    {
        if (sp[j][g] != '1')
        {
                write(1,"ERROR PLEASE FIrst line\n",24);
                exit(1);
        }
        g++;
    }
    if (g != comp)
    {
            write(1,"Lines are not equal each other\n",31);
            exit(1);
    }
}