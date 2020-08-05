/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrian <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 22:03:23 by abrian            #+#    #+#             */
/*   Updated: 2020/08/05 22:21:05 by aannett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	main(int argc, char **argv)
{
	char	**input;
	int		i;

	if (argc == 1)
	{
		input = parse_input();
		construct_from_input(input);
		return (0);
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			construct_matrix(argv[i]);
			i++;
		}
	}
	return (0);
}
