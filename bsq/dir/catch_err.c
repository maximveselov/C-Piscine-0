/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrian <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 21:32:28 by abrian            #+#    #+#             */
/*   Updated: 2020/08/05 21:32:32 by abrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	err_catcher(char **file)
{
	char	obs;
	char	emp;
	char	full;

	obs = fetch_obstcl_char(file);
	emp = fetch_empt_char(file);
	full = fetch_full_char(file);
	if (err_check_str(file[0]) < 0)
		return (0);
	if (fetch_line_nbr(file[0], emp, obs, full) != str_count_buff(file))
		return (0);
	return (1);
}

int	str_compare(char **file)
{
	int		i;

	i = 1;
	while (i < str_count_buff(file))
	{
		if (ft_strlen(file[i]) != ft_strlen(file[i + 1]))
			return (0);
		i++;
	}
	return (1);
}
