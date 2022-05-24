# include "so_long.h"

void    check_par(char *s)
{
    int i;

    i = 0;
    while (s[i])
    {
        if (s[i] == '.')
        {
            if (i == 0)
            {
                write(1,"invaild ag\n",11);
                exit(0);
            }
            i++;
            if(s[i] == 'b' && s[i+1] == 'e' && s[i+2]== 'r' && s[i+3] == '\0')
                break;
            else
            {
                write(1,"invaild ag\n",11);
                exit(0);
            }
        }
        i++;
    }
    if (s[i] == '\0')
    {
        write(1,"invaild ag\n",11);
        exit(0);
    }
}