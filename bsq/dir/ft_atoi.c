/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrian <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 20:15:16 by abrian            #+#    #+#             */
/*   Updated: 2020/08/05 21:37:17 by abrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		custom_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' ||
			c == '\r' || c == ' ')
		return (1);
	else
		return (0);
}

int		ft_atoi(char *str)
{
	int sign;
	int meaning;

	sign = 1;
	meaning = 0;
	while (custom_isspace(*str))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		meaning *= 10;
		meaning += *str - '0';
		str++;
	}
	return (meaning * sign);
}
