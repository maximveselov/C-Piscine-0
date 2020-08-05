/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_builder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrian <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 19:13:18 by abrian            #+#    #+#             */
/*   Updated: 2020/08/05 19:13:26 by abrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	fetch_min_val(int a, int b, int c)
{
	int	i;
	
	i = a;
	if (i > b)
		i = b;
	if (i > c)
		i = c;
	return (i);
}

int	**fetch_max_sqr(int **mat, char **tab)
{
	int	i;
	int	j;
	int	**ret;
	printf("\n\n %d \n\n", str_count_buff(tab));
	ret = (int **)malloc(sizeof(int **) * (str_count_buff(tab) + 1) /*rowcount*/);
	i = -1;
	j = -1;
	while (++i < str_count_buff(tab) /*func to get rowcount*/)
	{
		ret[i] = malloc(sizeof(int *) * (ft_strlen(tab[1]) + 1));
		ret[i][0] = mat[i][0];        // ret[i][0] = malloc(sizeof(int)) ??
	}
	while (++j < ft_strlen(tab[1]))
		ret[0][j] = mat[0][j];        // ret[0][j] = malloc(sizeof(int)) ??
	i = 1;
	while (i < str_count_buff(tab) /*rowcount*/)
	{
		j = 1;
		while (j < ft_strlen(tab[1]))
		{
			if (mat[i][j] == 1)
				ret[i][j] = fetch_min_val(ret[i][j - 1], ret[i - 1][j], ret[i - 1][j - 1]) + 1;
			else
				ret[i][j] = 0;
			j++;
		}
		i++;
	}
//    free(ret);
	return (ret);
}
