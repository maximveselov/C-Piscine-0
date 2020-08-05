#define BUF_SIZE 4096
#define LEN(arr) ((int) (sizeof (arr) / sizeof (arr) [0]))
#include "bsq.h"

int     open_file(char *file)
{
    int     fd;

    fd = open(file, O_RDONLY);
    if (fd == -1)
        return (0);
    else if (fd == 0)
        return (0);
    else
        return (fd);
}

char    **read_file(char *file)//функция использует ft_strdup и функцию  open_file и функцию print_tab
{
    int     i;
    char    *tmp;
    char    **tab;
    char    c[1];
    int     j;
    int     fd;

    j = -1;
    tab = (char **)malloc(sizeof(tab) * (BUF_SIZE));
    fd = open_file(file);
    while (read(fd, c, 1))
    {
        i = -1;
        tmp = malloc(sizeof(char *) * BUF_SIZE);
        while (c[0] != '\n')
        {
            tmp[++i] = c[0];
            read(fd, c, 1);
        }
        tab[++j] = ft_strdup(tmp);
    }
    close(fd);
    free(tab);
    free(tmp);
    print_tab(tab, j + 1);
    return (tab);
}
