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

int		**convert_tab_to_int(char **tab, int k)
{
	int		i;
	int		j;
	int		**ret;

	j = -1;
	ret = malloc(sizeof(int **) * BUF_SIZE);
	while (++j < k)
	{
		i = -1;
		while (tab[j][++i])
		{
			if (tab[j][i] == '.')
				ret[j][i] = 0;
			else if (tab[j][i] == 'o')
				ret[j][i] = 1;
		}
	}
	free(ret);
	return (ret);
}
/*
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
	int		**arr;
	char	**tab;

	if (argc != 2)
		return (0);
	else
	{
		tab = read_file(argv[1]);
		arr = convert_tab_to_int(tab, 27);
//		print_int_tab(arr);
	}
	return (0);
}
