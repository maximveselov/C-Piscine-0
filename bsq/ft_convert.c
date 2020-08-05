#define BUF_SIZE 4096
#define LEN(arr) ((int) (sizeof (arr) / sizeof (arr) [0]))
#include "bsq.h"

int     *convert_char_to_int(char *arr, char **file)
{
    int     *tab;
    int     i;
    int     j;

    i = 0;
    j = 0;
    tab = malloc(sizeof(int *) * BUF_SIZE);
    while (arr[i] != '\n' && arr[i] != '\0')
    {
        if (arr[i] == get_empty_c(file))
            tab[j] = 1;
        else if (arr[i] == get_obstacle_c(file))
            tab[j] = 0;
        i++;
        j++;
    }
    free(tab);
    return (tab);
}

int     **get_int_array(char **tab, int x)//функция использует convert_char_to_int
{
    int     **arr;
    int     j;
	int		i;
    
	j = 0;
	i = 1;
    arr = malloc(sizeof(int **) * BUF_SIZE);
    while (j < x)
    {
        arr[j] = malloc(sizeof(int *) * BUF_SIZE);
        arr[j] = convert_char_to_int(tab[i], tab);
        j++;
		i++;
    }
//  free(arr);
    return (arr);
}
void    print_int_tab(int **tab, char **char_tab)
{
    int     i;
    int     j;
    int     size;
    
    size = string_count_from_buffer(char_tab);
    printf("%d    asdasfgdsgfdsg hfd hdgf nghfn hfg nfhgn f", size);
    for (i = 0; i < size; i++)
    {
        printf("\n");
        for (j = 0; j < ft_strlen(char_tab[1]); j++)
            printf("%d", tab[i][j]);
    }
}
