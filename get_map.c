# include "so_long.h"

char    *map(char *argv)
{
    int fd;
    char *new;
    char *s;

    fd = open(argv,O_RDONLY);
    if (fd < 0)
        return (NULL);
    new = ft_strdup("");
    s = get_next_line(fd);
    while(s)
    {
        new = ft_strjoin(new,s);
        free(s);
        s = get_next_line(fd);    
    }
    return (new);
}