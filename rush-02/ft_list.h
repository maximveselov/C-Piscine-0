/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aannett <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 15:38:02 by aannett           #+#    #+#             */
/*   Updated: 2020/08/02 16:31:11 by aannett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_LIST_H
# define FT_LIST_H
#include <stdlib.h>

typedef struct			s_list
{
		struct s_list	*next;
		void			*data;
}						t_list;

t_list	*ft_create_elem(void *data);

#endif
