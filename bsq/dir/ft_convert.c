/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrian <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 19:12:57 by abrian            #+#    #+#             */
/*   Updated: 2020/08/05 21:43:50 by abrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		*change_char_to_int(char *arr, char **file)
{
	int	*tab;
	int	i;
	int	j;

	i = 0;
	j = 0;
	tab = malloc(sizeof(int *) * BUF_SIZE);
	while (arr[i] != '\n' && arr[i] != '\0')
	{
		if (arr[i] == fetch_empt_char(file))
			tab[j] = 1;
		else if (arr[i] == fetch_obstcl_char(file))
			tab[j] = 0;
		i++;
		j++;
	}
	free(tab);
	return (tab);
}

int		**fetch_int_arr(char **tab, int x)
{
	int	**arr;
	int	j;
	int	i;

	j = 0;
	i = 1;
	arr = malloc(sizeof(int **) * BUF_SIZE);
	while (j < x)
	{
		arr[j] = malloc(sizeof(int *) * BUF_SIZE);
		arr[j] = change_char_to_int(tab[i], tab);
		j++;
		i++;
	}
	return (arr);
}
