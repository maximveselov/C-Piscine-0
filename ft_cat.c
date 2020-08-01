/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aannett <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 19:06:15 by aannett           #+#    #+#             */
/*   Updated: 2020/07/28 17:19:39 by aannett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libgen.h>
#include <string.h>
#include <sys/errno.h>
#include <unistd.h>
#include <fcntl.h>
#define BUF_SIZE 30000

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_error(char *base, int errnum, char *argv)
{
	ft_putstr(basename(argv));
	ft_putstr(": ");
	ft_putstr(base);
	ft_putstr(": ");
	ft_putstr(strerror(errnum));
	ft_putstr("\n");
}

void	ft_read(char *file, char *argv)
{
	int		thisfile;
	char	buf[BUF_SIZE + 1];
	int		ret;

	thisfile = open(file, O_RDONLY);
	if (errno != 0)
		ft_error(file, errno, argv);
	else if (thisfile > 0)
	{
		while ((ret = read(thisfile, buf, BUF_SIZE)))
		{
			if (errno != 0)
			{
				ft_error(file, errno, argv);
				return ;
			}
			buf[ret] = '\0';
			ft_putstr(buf);
		}
	}
	else
		ft_error(file, errno, argv);
	close(thisfile);
}

void	ft_display(int files, char **c)
{
	char	buf[BUF_SIZE + 1];
	int		i;

	i = 1;
	while (i < files)
	{
		if (files < 2 || c[i][0] == '-')
		{
			while (read(1, &buf, 1) != 0)
				write(1, &buf, 1);
		}
		if (c[i][0] == '-')
			i++;
		ft_read(c[i], c[0]);
		i++;
	}
}

int		main(int argc, char **argv)
{
	char	buf[BUF_SIZE + 1];

	if (argc < 2)
	{
		while (read(1, &buf, 1) != 0)
			write(1, &buf, 1);
	}
	else
		ft_display(argc, argv);
	return (0);
}
