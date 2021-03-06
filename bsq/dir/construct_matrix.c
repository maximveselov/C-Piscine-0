/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrian <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 22:35:15 by abrian            #+#    #+#             */
/*   Updated: 2020/08/05 23:21:31 by aannett          ###   ########.fr       */
/*   Created: 2020/08/05 20:26:05 by abrian            #+#    #+#             */
/*   Updated: 2020/08/05 22:42:19 by aannett          ###   ########.fr       */
/*   Updated: 2020/08/05 20:58:25 by aannett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	add_const(char **file)
{
	int		**intfile;
	int		**intarr;
	int		*index;

	intfile = malloc(sizeof(int **) * ft_strlen(file[1]) *
	str_count_buff(file));
	intarr = malloc(sizeof(int **) * ft_strlen(file[1]) * str_count_buff(file));
	intfile = fetch_int_arr(file, str_count_buff(file));
	intarr = fetch_max_sqr(intfile, file);
	index = fetch_sqr_indx(fetch_max_nbr(intarr, file), intarr, file);
	file = empty_to_sqr(fetch_max_nbr(intarr, file), index[0], index[1], file);
	output_tab(file, str_count_buff(file) + 1);
}

void	construct_matrix(char *argv)
{
	char	**file;

	if (!open_f(argv))
	{
		ft_putstr("map error\n");
		return ;
	}
	file = read_f(argv);
	if (!err_catcher(file) || !str_compare(file))
	{
		ft_putstr("map error\n");
		return ;
	}
	add_const(file);
}

void	construct_from_input(char **input)
{
	int		**intfile;
	int		**intarr;
	int		*index;

	if (!err_catcher(input) || !str_compare(input))
	{
		ft_putstr("map error\n");
		return ;
	}
	intfile = fetch_int_arr(input, str_count_buff(input));
	intarr = fetch_max_sqr(intfile, input);
	index = fetch_sqr_indx(fetch_max_nbr(intarr, input), intarr, input);
	input = empty_to_sqr(fetch_max_nbr(intarr, input), index[0], index[1],
	input);
	output_tab(input, str_count_buff(input) + 1);
}
