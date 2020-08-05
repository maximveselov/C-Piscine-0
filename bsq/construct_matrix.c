#include "bsq.h"

void	construct_matrix(char *argv)
{
	char	**file;
	int		**intfile;
	int		**intarr;
	int		*index;

	file = read_file(argv);
	if (!err_catcher(file) || !str_compare(file))
	{
		ft_putstr("map error");
		return ;
	}
	// check
	intfile = malloc(sizeof(int **) * ft_strlen(file[1]) * string_count_from_buffer(file));
	intarr = malloc(sizeof(int **) * ft_strlen(file[1]) * string_count_from_buffer(file));
	intfile = get_int_array(file, string_count_from_buffer(file));
	intarr = get_max_square(intfile, file);
	index = get_square_index(get_max_num(intarr, file), intarr, file);
	file = change_map_to_answer(get_max_num(intarr, file), index[0], index[1], file);
	print_tab(file, string_count_from_buffer(file) + 1);
}

void	construct_from_input(char **input)
{
	int		**intfile;
	int		**intarr;
	int		*index;
	
	if (!err_catcher(input) || !str_compare(input))
	{
		ft_putstr("map error");
		return ;
	}
	intfile = get_int_array(input, string_count_from_buffer(input));
	intarr = get_max_square(intfile, input);
	index = get_square_index(get_max_num(intarr, input), intarr, input);
	input = change_map_to_answer(get_max_num(intarr, input), index[0], index[1], input);
	print_tab(input, string_count_from_buffer(input) + 1);
}
