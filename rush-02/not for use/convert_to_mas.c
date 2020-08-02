/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_mas.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teloise <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 16:31:02 by teloise           #+#    #+#             */
/*   Updated: 2020/08/02 19:18:32 by aannett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "ft_list.h"
#define		BUF_SIZE 4096


t_list		*ft_create_elem(void *data)
{
	t_list	*toto;

	toto = NULL;
	toto = malloc(sizeof(t_list));
	if (!toto)
		return (NULL);
	if (toto)
	{
		toto->data = data;
		toto->next = NULL;
	}
	return (toto);
}



t_list	*ft_list_push_strs(int size, char **strs)
{
	int		i;
	t_list	*tmp;
	t_list	*tmp2;

	if (size == 0)
		return (0);
	i = -1;
	while (++i < size)
	{
		tmp2 = tmp;
		tmp = ft_create_elem((void *)strs[i]);
		tmp->next = tmp2;
	}
	return (tmp);
}



void	ft_putchar(char c)
{
	write(1, &c, 1);
}


void	ft_putstr(char *str)
{
	int j;

	j = 0;
	while (str[j] != '\0')
	{
		write(1, &str[j], 1);
		j++;
	}
	ft_putchar('\n');
}

void    print_tab(char **tab, int i)
{
    int j;
    
    j = 0;
    while(j < i)
	{
        ft_putstr(tab[j]);
		j++;
	}
}

char	*ft_strdup(char *src)
{
	int		i;
	int		size;
	char	*copy;

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

int	ft_strlen(char *str)
{
	int j;

	j = 0;
	while (str[j] != '\0')
	{
		j++;
	}
	return (j);
}

char	*remove_spaces(char *str)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = -1;
	res = malloc(sizeof(char*) * (ft_strlen(str) + 1));
	while (str[i])
	{
		if (str[i] != ' ')
		{
			j++;
			res[j] = str[i];
		}
		i++;
		res[j + 1] = '\0';
	}
	return (res);
}


t_list	*read_file(char *name)
{
	int		fd;
	int		i;
	char	*tmp;
	char	**tab;
	char	c[1];
	int 	j;
	int		ret;
	t_list	*list;

	j = 0;
	list = NULL;
	tmp = NULL;
	fd = open(name, O_RDONLY);
	if (fd == -1)
		return (NULL);
	if (!(tab = (char **)malloc(sizeof(tab) * (BUF_SIZE))))
		return (NULL);
    while ((ret = read(fd, c, 1)))
	{
		i = 0;
		tmp = malloc(sizeof(char *) * 64);
		while (c[0] != '\n' && c[0] != 58)
    	{
			tmp[i] = c[0];
			read(fd, c, 1);
			i++;
    	}
		tab[j] = ft_strdup(remove_spaces(tmp));
		j++;
	}
	close(fd);
	list = ft_list_push_strs(j, tab);
	free(tmp);
	free(tab);
	free(list);
	return (list);
}

  int     ft_atoi(char *str)
  {
      int res;
      int sign;
      int i;
 
      res = 0;
      sign = 0;
      i = 0;
 
      while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n') || (str[i] == '\v') || (str[i] == '\r') || (str[i] == '\f'))
          i++;
      if (str[i] == '-')
          sign = 1;
      if (str[i] == '+' || str[i] == '-')
          i++;
 
          while (str[i] && (str[i] >= '0') && (str[i] <= '9'))
          {
              res = res * 10;
              res += (int)str[i] - '0';
              i++;
          }
          if (sign == 1)
             return (-res);
          return (res);
  }


int		int_read(char *num)		// count number of digits
{
	int		i;

	i = 0;
	while (num[i])
		i++;
	return (i);
}

int		ft_read_order(char *num)
{
	int		i;
	
	i = 1;
	while (i < ft_atoi(num))
		i *= 10;
	return (i / 10);
}


char	*str_from_list(char *argv, t_list *list)
{
	t_list	*glist;
	char	*ret;
	
	glist = list;
	while (glist)
	{
		if (ft_read_order(argv) == ft_read_order(glist->next->data))
		{
			ret = glist->data;
			return (ret);
		}
	/*	else if (int_read(argv) > ft_atoi(glist->data))
		{
			ret = glist->data;
			return (ret);
		} */
		glist = glist->next;
	}
	return (NULL);
}


void	printlist(t_list *list)
{
	while (list)
	{
		ft_putstr(list->data);
		list = list->next;
    }
}

int main(void)
{
	t_list	*li;

	li = read_file("numbers.dict.txt");
	ft_putstr(str_from_list("123", li));
	printlist(li);
	printf("%d", ft_read_order("12"));
	return (0);

}
