#include "bsq.h"

int     get_max_num(int **mat, char **tab)
{
    int     i;
    int     j;
    int     k;

    i = 1;
    k = 0;
    while (i < 9 /*rowcount*/)
    {
        j = 1;
        while (j < ft_strlen(tab[1]))
        {
            if (mat[i][j] > k)
				k = mat[i][j];
			j++;
        }
		i++;
    }
	return (k);
}

int		*get_square_index(int max, int **mat, char **tab)
{
	int		i;
	int		j;
	int		*ind;

	i = 1;
	ind = malloc(sizeof(int *) * BUF_SIZE);
	while (i < 9 /*rowcount*/)
	{
		j = 1;
		while (j < ft_strlen(tab[1]))
		{
			if (mat[i][j] == max)
			{
				ind[0] = i + 1;
				ind[1] = j + 1;
				return (ind);
			}
			j++;
		}
		i++;
	}
	return (ind);
}

