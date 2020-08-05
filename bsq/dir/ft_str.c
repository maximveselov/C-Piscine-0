/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrian <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 20:15:58 by abrian            #+#    #+#             */
/*   Updated: 2020/08/05 20:18:57 by aannett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void    ft_putstr(char *str)
{
    int     i;

    i = 0;
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
}

char    *ft_strdup(char *src)
{
    int     i;
    int     size;
    char    *copy;

    i = 0;
    size = 0;
    while (src[size])
        size++;
    if(!(copy = (char*)malloc(size + 1)))
        return (NULL);
    while (i < size)
    {
        copy[i] = src[i];
        i++;
    }
    copy[size] = '\0';
    return (copy);
    free(copy);
}

void    output_tab(char **tab, int i)// функция использует ft_putchar
{
    int j;

    j = 0;
    while(j < i)
    {
        ft_putstr(tab[j]);
        ft_putstr("\n");
        j++;
    }
}

