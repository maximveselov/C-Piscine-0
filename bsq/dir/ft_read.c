/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrian <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 19:29:06 by abrian            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/08/05 21:01:58 by abrian           ###   ########.fr       */
=======
/*   Updated: 2020/08/05 20:51:56 by aannett          ###   ########.fr       */
>>>>>>> ffa86dcfd2f0f246e0429e1fd589c05448c0eed2
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		open_f(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	else if (fd == 0)
		return (0);
	else
		return (fd);
}

char	**parse_file(int file)
{
	int	i;
	int	j;
	char	*tmp;
	char	**tab;
	char	c[1];

	tab = (char **)malloc(sizeof(tab) * BUF_SIZE);
	j = -1;
	while (read(file, c, 1))
	{
		i = -1;
		tmp = malloc(sizeof(char *) * BUF_SIZE);
		while (c[0] != '\n')
		{
			tmp[++i] = c[0];
			read(file, c, 1);
		}
		tab[++j] = ft_strdup(tmp);
	}
	close(file);
	free(tab);
	free(tmp);
	return (tab);
}

<<<<<<< HEAD
char    **read_f(char *file)
=======
char    **read_f(char *file)//функция использует ft_strdup и функцию  open_file и функцию print_tab
>>>>>>> ffa86dcfd2f0f246e0429e1fd589c05448c0eed2
{
	int	fd;

	fd = open_f(file);
	return (parse_file(fd));
}
