/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrian <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 19:24:21 by abrian            #+#    #+#             */
/*   Updated: 2020/08/05 21:41:29 by abrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str)
	{
		str++;
		len++;
	}
	return (len);
}

int		examine_map(char **file_name, int line_count, char empty,
		char obstacle)
{
	int i;
	int j;
	int len;

	i = 1;
	while (i < line_count)
	{
		len = ft_strlen(file_name[i]);
		if (len < 1)
			return (0);
		if ((i != 1) && (len != ft_strlen(file_name[i - 1])))
			return (0);
		j = 0;
		while (j < len)
		{
			if (file_name[i][j] != empty && file_name[i][j] != obstacle)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
