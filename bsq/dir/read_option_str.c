/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_option_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrian <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 19:37:36 by abrian            #+#    #+#             */
/*   Updated: 2020/08/05 20:14:08 by aannett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	err_check_str(char *optional_str)
{
	int flag;
	int count_ch;

	flag = 0;
	count_ch = 0;
	while ((*optional_str) && (*optional_str != '\0' || *optional_str != '\n'))
	{
		if (((*optional_str < '0') || (*optional_str > '9')) && (flag == 0))
			flag = 1;
		if ((*optional_str >= '0') && (*optional_str <= '9') && (flag == 1))
			count_ch++;
		if ((*optional_str < '0') || (*optional_str > '9'))
			count_ch++;
		optional_str++;
	}
	optional_str++;
	if (count_ch > 3)
		return (-1);
	return (0);
}

int	read_str_line_nbr(char *optional_str, char *empty_ch, char *obstacle_ch,
	char *full_ch)
{
	int res;
	int orders;

	res = 0;
	orders = 1;
	while ((*optional_str) && (*optional_str != '\0' || *optional_str != '\n'))
		optional_str++;
	if ((*optional_str == '\0') || (*optional_str == '\n'))
		optional_str--;
	*full_ch = *optional_str;
	optional_str--;
	*obstacle_ch = *optional_str;
	optional_str--;
	*empty_ch = *optional_str;
	while (*optional_str)
	{
		optional_str--;
		if (*optional_str)
		{
			res += (*optional_str - '0') * orders;
			orders *= 10;
		}
	}
	return (res);
}
