#include "bsq.h"
#define BUF_SIZE 4096
#define LEN(arr) ((int) (sizeof (arr) / sizeof (arr) [0]))

int		main(int argc, char **argv)
//функция временно использует ft_putchar и использует функцию  convert_char_to_int и функцию get_int_array и функцию print_int_tab
{
/*	char	**tab;
	int		**arr;
    int		**secarr;
	int		*test;
*/	char	**input;

	if (argc == 1)
	{
		input = parse_input();
		construct_from_input(input);
		return (0);
	}
	else
	{
		int 	i = 1;
		while (i < argc)
		{
			construct_matrix(argv[i]);
			i++;
		}
/*		tab = read_file(argv[1]);
//		arr = convert_char_to_int(tab[2]);
		ft_putstr("\n");
		if (err_option_str(tab[0]) < 0)
			ft_putstr("map error");
	//	int total = sizeof(tab)
	//	ft_putstr(tab[2]);
        arr = get_int_array(tab, string_count_from_buffer(tab));
        print_tab(tab, string_count_from_buffer(tab)+1);
//		arr = convert_tab_to_int(tab, 27);
	//	printf("%d\n", get_line_n(tab[0], get_empty_c(tab), get_obstacle_c(tab), get_full_c(tab)));
        secarr = get_max_square(arr, tab);
		print_int_tab(secarr, tab);
		printf("\n\n%d", get_max_num(secarr, tab));
		test = get_square_index(get_max_num(secarr, tab), secarr, tab);
		printf("\n%d\n%d", test[0], test[1]);
		tab = change_map_to_answer(get_max_num(secarr, tab), test[0], test[1],tab);	// меняем условие на ответ (смотри как работает функция в drawer.c и bsq.h)
		print_tab(tab, string_count_from_buffer(tab) + 1); */
	}
	return (0);
}
