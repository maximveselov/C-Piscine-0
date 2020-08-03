#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#define BUF_SIZE 4096

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

char	*ft_strdup(char *src)
{
	int		i;
	int		size;
	char	*copy;

	i = 0;
	size = 0;
	while (src[size])
		size++;
	if(!(copy = (char*)malloc(size + 1)))
		return (NULL);
	while (i < size)
	{
		copy[i] = src[i];
		i++;
	}
	copy[size] = '\0';
	return (copy);
	free(copy);
}

int		open_file(char *file)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	else if (fd == 0)
		return (0);
	else
		return (fd);
}

void    print_tab(char **tab, int i)
{
    int j;

    j = 0;
    while(j < i)
    {
        ft_putstr(tab[j]);
		ft_putstr("\n");
        j++;
    }
}

char	**read_file(char *file)
{
	int		i;
	char	*tmp;
	char	**tab;
	char	c[1];
	int 	j;
	int		fd;

	j = -1;
	tab = (char **)malloc(sizeof(tab) * (BUF_SIZE));
	fd = open(file, O_RDONLY);
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
	print_tab(tab, j);
	return (tab);
}
/*
int		**convert_tab_to_int(char **tab, int k)
{
	int		i;
	int		j;
	int		**ret;

	j = -1;
	ret = (int **)malloc(sizeof(int **) * BUF_SIZE);
	while (++j < k)
	{
		i = -1;
		while (tab[j][++i] != '\0')
		{
			if (tab[j][i] == '.')
				ret[j][i] = 0 - '0';
			else if (tab[j][i] == 'o')
				ret[j][i] = 1 - '0';
		}
	}
	free(ret);
	return (ret);
}
*/
int		*convert_char_to_int(char *arr)
{
	int		*tab;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	tab = malloc(sizeof(int *) * BUF_SIZE);
	while (arr[i] != '\n' && arr[i] != '\0')
	{
		if (arr[i] == '.')
			tab[j] = 0;
		else if (arr[i] == 'o')
			tab[j] = 1;
		i++;
		j++;
	}
	for (k = 0; k < j; k++)
		printf("%d\t", tab[k]);
	return (tab);
}
/*
int		**get_int_array(char **tab, int x)
{
	int		**arr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	arr = malloc(sizeof(int **) * BUF_SIZE);
	while (j < x)
	{
		arr[j][0] = convert_char_to_int(tab[i][0]);
		j++;
		i++;
	}
	return (arr);
}


void	print_int_tab(int **tab)
{
	int		i;
	int		j;

	for (i = 0; i < 8; i++)
	{
		printf("\n");
		for (j = 0; j < 27; j++)
			printf("%d\t", tab[i][j]);
	}
}*/

int		main(int argc, char **argv)
{
	char	**tab;
	int		*arr;

	if (argc != 2)
		return (0);
	else
	{
		tab = read_file(argv[1]);
		arr = convert_char_to_int(tab[1]);
//		test = get_int_array(tab, 8);
//		arr = convert_tab_to_int(tab, 27);
//		print_int_tab(arr);
	}
	return (0);
}
