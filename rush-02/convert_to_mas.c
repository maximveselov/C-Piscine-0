/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_mas.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teloise <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 16:31:02 by teloise           #+#    #+#             */
/*   Updated: 2020/08/01 20:55:07 by aannett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#define		BUF_SIZE 4096

void	ft_putchar(char c)
{
	write(1, &c, 1);
}


void	ft_putstr(char *str)
{
	int j;

	j = 0;
	while (str[j] != '\0')
	{
		write(1, &str[j], 1);
		j++;
	}
	ft_putchar('\n');
}

void    print_tab(char **tab, int i)
{
    int j;
    
    j = 0;
    while(j < i)
	{
        ft_putstr(tab[j]);
		j++;
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

int	ft_strlen(char *str)
{
	int j;

	j = 0;
	while (str[j] != '\0')
	{
		j++;
	}
	return (j);
}


void	read_file(char *name)
{
	int		fd;
	int		i;
	char	*tmp;
	char	**tab;
	char	c[BUF_SIZE + 1];
	int 	j;
	int		ret;

	j = 0;
	fd = open(name, O_RDONLY);
	if (fd == -1)
		return ;
	if (!(tab = (char **)malloc(sizeof(tab) * (BUF_SIZE))))
		return ;
    while ((ret = read(fd, c, 1)))
	{
		i = 0;
		if (!(tmp = malloc(sizeof(char) * 128)))
			return ;
		while (c[0] != '\n')
    	{
        	tmp[i] = c[0];
			read(fd, c, 1);
			i++;
    	}
		tab[j] = ft_strdup(tmp);
		j++;
	}
	//tab[0][ft_strlen(tab[0])-1] = '\0';
	close(fd);
	print_tab(tab, j);
	free(tmp);
	free(tab);
}



int main(void)
{
	read_file("numbers.dict.txt");

}
