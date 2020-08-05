/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrian <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 19:12:30 by abrian            #+#    #+#             */
/*   Updated: 2020/08/05 20:13:16 by aannett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	**empty_to_sqr(int size, int string, int pos, char **tmp)
{
	int 	a;
	int 	b;
	char	filler;

	a = 0;
	filler = fetch_full_char(tmp);
	while (a < size)
	{
		b = 0;
		while (b < size)
		{
			tmp[string - a][pos - b - 1] = filler;
			b++;
		}
		a++;
	}
	return (tmp);
}

void	map_out_arr(char **answer)
{
	int		j;
	int		i;
	int		len;
	int		str;

	i = 0;
	answer++;
	str = str_count_buff(answer);
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
