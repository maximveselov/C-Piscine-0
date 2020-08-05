#include "bsq.h"

char	**change_map_to_answer(int size, int string, int pos, char **tmp)
{
	int a;
	int b;

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

void	draw(char **answer)
{
	int j;
	int i;
	int len;
	int str;

	i = 0;
	answer++;
	str = string_count_from_buffer(answer);
	len = ft_strlen(answer[1]);
	while (i <= str)
	{
		j = 0;
		while (j < len)
		{
			write (1, *answer, 1);
			(*answer)++;
			j++;
		}
		write(1, "\n", 1);
		i++;
		answer++;
	}
}
