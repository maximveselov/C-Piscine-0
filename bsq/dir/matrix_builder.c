/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_builder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrian <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 22:55:09 by abrian            #+#    #+#             */
/*   Updated: 2020/08/05 23:06:29 by aannett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		fetch_min_val(int a, int b, int c)
{
	int	i;

	i = a;
	if (i > b)
		i = b;
	if (i > c)
		i = c;
	return (i);
}

void	add_mat(int **mat, char **tab, int **ret)
{
	int	i;
	int	j;

	i = 1;
	while (i < str_count_buff(tab))
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
}

int		**fetch_max_sqr(int **mat, char **tab)
{
	int	i;
	int	j;
	int	**ret;

	ret = (int **)malloc(sizeof(int **) * (str_count_buff(tab) + 1));
    i = -1;
    j = -1;
    while (++i < str_count_buff(tab))
    {
		ret[i] = malloc(sizeof(int *) * (ft_strlen(tab[1]) + 1));
		ret[i][0] = mat[i][0];
    }
	while (++j < ft_strlen(tab[1]))
		ret[0][j] = mat[0][j];
	add_mat(mat, tab, ret);
	return (ret);
}
