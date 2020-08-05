#include "bsq.h"

void	construct_matrix(char *argv)
{
	char	**file;
	int		**intfile;
	int		**intarr;
	int		*index;

	file = read_file(argv);
	// check
	intfile = get_int_array(file, string_count_from_buffer(file));
	intarr = get_max_square(intfile, file);
	index = get_square_index(get_max_num(intarr, file), intarr, file);
	file = change_map_to_answer(get_max_num(intarr, file), index[0], index[1], file);
	print_tab(file, string_count_from_buffer(file) + 1);
}
