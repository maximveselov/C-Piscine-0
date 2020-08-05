/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct_for_one.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrian <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 21:33:19 by abrian            #+#    #+#             */
/*   Updated: 2020/08/05 21:33:20 by abrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	construct_for_line(char **tab)
{
	int		i;
	char	obs;
	char	emp;
	char	full;

	tab = malloc(sizeof(char **) * BUF_SIZE);
	obs = fetch_obstcl_char(tab);
	emp = fetch_empt_char(tab);
	full = fetch_full_char(tab);
	i = 0;
	while (tab[1][i] != '\0')
	{
		if (tab[1][i] == emp)
			tab[1][i] = full;
		i++;
	}
	map_out_arr(tab);
	free(tab);
}
