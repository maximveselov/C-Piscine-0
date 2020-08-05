#include "bsq.h"

int		min(int a, int b, int c)
{
	int		i;

	i = a;
	if (i > b)
		i = b;
	if (i > c)
		i = c;
	return (i);
}

int		**get_max_square(int **mat, char **tab)
{
	int		i;
	int		j;
	int		**ret;

	ret = (int **)malloc(sizeof(int **) * (9 + 1) /*rowcount*/);
	i = -1;
	j = -1;
	while (++i < 9 /*func to get rowcount*/)
	{
		ret[i] = malloc(sizeof(int *) * (ft_strlen(tab[1]) + 1));
		ret[i][0] = mat[i][0];		// ret[i][0] = malloc(sizeof(int)) ??
	}
	while (++j < ft_strlen(tab[1]))
		ret[0][j] = mat[0][j];		// ret[0][j] = malloc(sizeof(int)) ??
	i = 1;
	while (i < 9 /*rowcount*/)
	{
		j = 1;
		while (j < ft_strlen(tab[1]))
		{
			if (mat[i][j] == 1)
				ret[i][j] = min(ret[i][j - 1], ret[i - 1][j], ret[i - 1][j - 1]) + 1;
			else
				ret[i][j] = 0;
			j++;
		}
		i++;
	}
	free(ret);
	return (ret);
}

