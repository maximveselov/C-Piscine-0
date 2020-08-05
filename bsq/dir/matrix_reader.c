/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_reader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrian <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 19:14:08 by abrian            #+#    #+#             */
/*   Updated: 2020/08/05 20:13:53 by aannett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	fetch_max_nbr(int **mat, char **tab)
{
	int	i;
	int	j;
	int	k;

	i = 1;
	k = 0;
    while (i < str_count_buff(tab) /*rowcount*/)
	{
		j = 0;
		while (j < ft_strlen(tab[1]))
		{
			if (mat[i][j] > k)
				k = mat[i][j];
			j++;
		}
		i++;
	}
	return (k);
}

int	*fetch_sqr_indx(int max, int **mat, char **tab)
{
	int	i;
	int	j;
	int	*ind;
	
	i = 1;
	ind = malloc(sizeof(int *) * BUF_SIZE);
	while (i < str_count_buff(tab) /*rowcount*/)
	{
		j = 1;
		while (j < ft_strlen(tab[1]))
		{
			if (mat[i][j] == max)
			{
				ind[0] = i + 1;
				ind[1] = j + 1;
				return (ind);
			}
			j++;
		}
		i++;
	}
	return (ind);
}
