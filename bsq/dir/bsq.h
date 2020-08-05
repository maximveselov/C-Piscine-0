/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrian <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 20:00:31 by abrian            #+#    #+#             */
/*   Updated: 2020/08/05 20:00:36 by abrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# define BUF_SIZE 4096
# define LEN(arr) ((int) (sizeof (arr) / sizeof (arr) [0]))
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

void	ft_putstr(char *str);
char	*ft_strdup(char *src);
int		open_f(char *file);
void    output_tab(char **tab, int i);
char	**read_f(char *file);
int		*change_char_to_int(char *arr, char **file);
int		**fetch_int_arr(char **tab, int x);
void	output_int_tab(int **tab);
int		ft_atoi(char *str);
int		custom_isspace(char c);
int		fetch_line_nbr(char *optional, char empty, char obstacle, char full);
char	fetch_empt_char(char **c);
char	fetch_obstcl_char(char **c);
char	fetch_full_char(char **c);	
int		**fetch_max_sqr(int **mat, char **tab);
int		ft_strlen(char *str);
int		examine_map(char **file_name, int line_count, char empty, char obstacle);
int		fetch_min_val(int a, int b, int c);
int		err_check_str(char *optional_str);
int		read_str_line_nbr(char *optional_str, char *empty_ch, char *obstacle_ch, char *full_ch);
int		str_count_buff(char **buffer);
int		fetch_max_nbr(int **mat, char **tab);
int		*fetch_sqr_indx(int max, int **mat, char **tab);
char	**empty_to_sqr(int size, int string, int pos, char **tmp);// меняет в начальном массиве символы пустоты на квадрат
void	map_out_arr(char **answer);	// отрисовывает двумерный массив чаров
char	**parse_input(void);
void	construct_matrix(char *argv);
void	construct_from_input(char **input);
int		err_catcher(char **file);
int		str_compare(char **file);

#endif
