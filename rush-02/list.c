/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aannett <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 15:46:17 by aannett           #+#    #+#             */
/*   Updated: 2020/08/02 17:24:03 by aannett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>
#define BUF_SIZE 4096
#include <fcntl.h>
#include <unistd.h>

t_list		*ft_create_elem(void *data)
{
	t_list	*toto;

	toto = NULL;
	toto = malloc(sizeof(t_list));
	if (toto)
	{
		toto->data = data;
		toto->next = NULL;
	}
	return (toto);
}


void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*curr;

	if (!*begin_list)
		*begin_list = ft_create_elem(data);
	curr = *begin_list;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = malloc(sizeof(t_list));
	curr->next->data = data;
	curr->next->next = NULL;
}


char	*ft_strdup(char *src)
{
	int		i;
	int		size;
	char	*copy;

	i = 0;
	size = 0;
	while(src[size])
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

t_list *read_from_dict(char *name)
{
	int		f;
	int		ret;
	char	buf[BUF_SIZE + 1];
	char	*tmp;
	int		i;
	t_list	*list;

	list = NULL;
	tmp = NULL;
	f = open(name, O_RDONLY);
	if (f == -1)
		return (NULL);
	while ((ret = read(f, buf, 1)))
	{
		i = 0;
		tmp = malloc(sizeof(char*) * 128);
		while (buf[0] != '\n' || buf[0] != ':')
		{
			tmp[i] = buf[0];
			read(f, buf, 1);
			i++;
		}
//		tmp[i] = '\0';
		ft_list_push_back(&list, tmp);
		free(tmp);
		free(list->data);
	}
	free(list);
	close(f);
	return (list);
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
	t_list *li;
	li = read_from_dict("numbers.dict");
	printlist(li);

	return (0);

}
