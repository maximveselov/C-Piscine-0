
#include <unistd.h>

char	**empty_to_sqr(int size, int string, int pos, char **tmp)
{
	int	a;
	int	b;

	a = 0;
	while (a < size)
	{
		b = 0;
		while (b < size)
		{
			tmp[string - a][pos - b - 1] = 'x';// допилю потом, как это правильно сделать, сейчас просто на кресты меняю
			b++;
		}
		a++;
	}
	return (tmp);
}

void	map_out_arr(char **answer)
{
	while (answer)
	{
		while (*answer)
		{
			write(1, *answer, 1);
			(*answer)++;
		}
		answer++;
	}
}
