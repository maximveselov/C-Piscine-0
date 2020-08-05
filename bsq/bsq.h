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
int		open_file(char *file);
void    print_tab(char **tab, int i);
char	**read_file(char *file);
int		*convert_char_to_int(char *arr, char **file);
int		**get_int_array(char **tab, int x);
void	print_int_tab(int **tab);
int		ft_atoi(char *str);
int		my_isspace(char c);
int		get_line_n(char *optional, char empty, char obstacle, char full);
char	get_empty_c(char **c);
char	get_obstacle_c(char **c);
char	get_full_c(char **c);
int		**get_max_square(int **mat, char **tab);
int		ft_strlen(char *str);
int		ft_check_map(char **file_name, int line_count, char empty, char obstacle);
int		min(int a, int b, int c);
int		err_option_str(char *optional_str);
int		read_option_str(char *optional_str, char *empty_ch, char *obstacle_ch, char *full_ch);
int		string_count_from_buffer(char **buffer);
int		get_max_num(int **mat, char **tab);
int		*get_square_index(int max, int **mat, char **tab);
char	**change_map_to_answer(int size, int string, int pos, char **tmp);	// меняет в начальном массиве символы пустоты на квадрат
void	draw(char **answer);	// отрисовывает двумерный массив чаров

#endif

