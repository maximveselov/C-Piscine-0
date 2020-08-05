/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrian <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 19:51:29 by abrian            #+#    #+#             */
/*   Updated: 2020/08/05 19:53:07 by abrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	**parse_input(void)
{
	int		i;
	int		j;
	char	*tmp;
	char	**tab;
	char	c[1];

	tab = (char **)malloc(sizeof(tab) * BUF_SIZE);
	j = -1;
	while (read(0, c, 1))
	{
		i = -1;
		tmp = malloc(sizeof(char *) * BUF_SIZE);
		while (c[0] != '\n')
		{
			tmp[++i] = c[0];
			read(0, c, 1);
		}
		tab[++j] = ft_strdup(tmp);
	}
	free(tab);
	free(tmp);
	return (tab);
}
