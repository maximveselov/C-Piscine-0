/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_rules.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrian <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 19:26:56 by abrian            #+#    #+#             */
/*   Updated: 2020/08/05 20:13:42 by aannett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	fetch_empt_char(char **c)
{
	int i;
    i = ft_strlen(c[0]);
    return c[0][i-3];
}

char	fetch_obstcl_char(char **c)
{
	int i;
    i = ft_strlen(c[0]);
    return c[0][i-2];
}

char	fetch_full_char(char **c)
{
    int i;
    i = ft_strlen(c[0]);
	return c[0][i-1];
}

int		fetch_line_nbr(char *optional, char empty, char obstacle, char full)
{
	return (read_str_line_nbr(optional, &empty, &obstacle, &full));
}
